#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>

#define MENU_GAME_NEW 20
#define MENU_GAME_EXIT 21
#define WIDTH 5
#define HEIGHT 4
#define TOTAL_FIELDS 20

#define HAS_NOTHING 0
#define HAS_MINE 1
#define HAS_NOTHING_VISIBLE 2
#define HAS_MINE_VISIBLE 3

void addMenu(HWND hwnd);
void addElements(HWND hwnd);
void start();
void stop();
void action(int fieldIndex);

int player = 1;
int player1ScoreValue = 0;
int player2ScoreValue = 0;
int fields[TOTAL_FIELDS];

HWND player1Name;
HWND player2Name;
HWND player1Score;
HWND player2Score;
HWND fieldsWindows[TOTAL_FIELDS];

LRESULT CALLBACK WindowProcedure(HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);

int WINAPI
WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int nCmdShow)
// Window Class
{
    srand((unsigned)time(0));
    WNDCLASS wc = {};
    wc.lpszClassName = "Campo Minado";
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInst;
    RegisterClass(&wc);

    CreateWindow(wc.lpszClassName, "Campo Minado",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 500, 535, NULL, NULL,
        NULL, NULL);

    MSG msg = {};

    while (GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (msg) {
    case WM_CREATE:
        addMenu(hwnd);
        addElements(hwnd);
        stop();
        break;

    case WM_COMMAND:
        switch (wParam) {
        case MENU_GAME_NEW:
            start();
            break;

        case MENU_GAME_EXIT:
            DestroyWindow(hwnd);
            break;

        default:
            action(wParam);
            // char editText[100];
            // MessageBox(NULL, "Button", "X", MB_OK);
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void addMenu(HWND hwnd)
{
    HMENU hMenu = CreateMenu();
    HMENU hGameMenu = CreateMenu();
    AppendMenuA(hGameMenu, MF_STRING, MENU_GAME_NEW, "Novo jogo");
    AppendMenuA(hGameMenu, MF_SEPARATOR, NULL, NULL);
    AppendMenuA(hGameMenu, MF_STRING, MENU_GAME_EXIT, "Sair");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hGameMenu, "Opções");

    SetMenu(hwnd, hMenu);
}

void addElements(HWND hwnd)
{
    player1Name = CreateWindow("Static", "Jogador 1", WS_VISIBLE | WS_CHILD, 10, 10, 400, 20,
        hwnd, NULL, NULL, NULL);

    player1Score = CreateWindow("Static", "0", WS_VISIBLE | WS_CHILD, 30, 40, 20, 20,
        hwnd, NULL, NULL, NULL);

    player2Name = CreateWindow("Static", "Jogador 2", WS_VISIBLE | WS_CHILD, 410, 10, 400, 20,
        hwnd, NULL, NULL, NULL);

    player2Score = CreateWindow("Static", "0", WS_VISIBLE | WS_CHILD, 435, 40, 20, 20,
        hwnd, NULL, NULL, NULL);

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    CreateWindow("Button", "Novo Jogo", WS_VISIBLE | WS_CHILD, 190, 30, 100, 35,
        hwnd, (HMENU)MENU_GAME_NEW, NULL, NULL);

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    int index = 0;
    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
            fieldsWindows[index] = CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, column * 100 + 10, row * 100 + 100, 65, 65, hwnd,
                (HMENU)index, NULL, NULL);
            index++;
        }
    }
}

void start()
{
    if (player == 2) {
        ShowWindow(player1Name, false);
        ShowWindow(player2Name, true);
    }
    else {
        ShowWindow(player1Name, true);
        ShowWindow(player2Name, false);
    }

    int mine1 = rand() % TOTAL_FIELDS;

    int mine2;
    do {
        mine2 = rand() % TOTAL_FIELDS;
    } while (mine2 == mine1);

    int mine3;
    do {
        mine3 = rand() % TOTAL_FIELDS;
    } while (mine3 == mine1 || mine3 == mine2);

    for (int index = 0; index < TOTAL_FIELDS; index++) {
        if (index == mine1) {
            fields[index] = HAS_MINE;
        }
        else if (index == mine2) {
            fields[index] = HAS_MINE;
        }
        else if (index == mine3) {
            fields[index] = HAS_MINE;
        }
        else {
            fields[index] = HAS_NOTHING;
        }

        EnableWindow(fieldsWindows[index], true);
    }
}

void stop()
{
    ShowWindow(player1Name, true);
    ShowWindow(player2Name, true);

    for (int index = 0; index < TOTAL_FIELDS; index++) {
        EnableWindow(fieldsWindows[index], false);
    }
}

void action(int index)
{
    if (fields[index] == HAS_MINE) {
	    if (player == 1) {
	        player = 2;
	        player2ScoreValue++;
	        char player2ScoreValueChars [3];
	        sprintf(player2ScoreValueChars, "%d", player2ScoreValue);
	        LPCSTR player2ScoreValueString = player2ScoreValueChars;
	        SetWindowTextA(player2Score, player2ScoreValueString);
	    }
	    else {
	        player = 1;
	        player1ScoreValue++;
	        char player1ScoreValueChars [3];
	        sprintf(player1ScoreValueChars, "%d", player1ScoreValue);
	        LPCSTR player1ScoreValueString = player1ScoreValueChars;
	        SetWindowTextA(player1Score, player1ScoreValueString);
	    }
    	
        for (int current = 0; current < TOTAL_FIELDS; current++) {
            if (fields[current] == HAS_MINE) {
                fields[current] = HAS_MINE_VISIBLE;
            }
        }

        stop();
        return;
    }

    EnableWindow(fieldsWindows[index], false);
    if (player == 1) {
        player = 2;
        ShowWindow(player1Name, false);
        ShowWindow(player2Name, true);
    }
    else {
        player = 1;
        ShowWindow(player1Name, true);
        ShowWindow(player2Name, false);
    }
}

