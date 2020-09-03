#include <windows.h>

#define MENU_GAME_NEW 50
#define MENU_GAME_EXIT 51
#define ELEMENT_BUTTON 5

HWND hEdit;

void addMenu(HWND hwnd);
void addElements(HWND hwnd);
LRESULT CALLBACK WindowProcedure(HWND hwnd,
                                 UINT uMsg,
                                 WPARAM wParam,
                                 LPARAM lParam);

int WINAPI
WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int nCmdShow)
// Window Class
{
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
                                 LPARAM lParam) {
  switch (msg) {
    case WM_CREATE:
      addMenu(hwnd);
      addElements(hwnd);
      break;

    case WM_COMMAND:
      switch (wParam) {
        case MENU_GAME_NEW:
          break;

        case MENU_GAME_EXIT:
          DestroyWindow(hwnd);
          break;

        default:
            char editText[100];
         	MessageBox(NULL, "Button", "X", MB_OK);
	    	break;
      }
      break;

    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
  }

  return DefWindowProc(hwnd, msg, wParam, lParam);
}

void addMenu(HWND hwnd) {
  HMENU hMenu = CreateMenu();
  HMENU hGameMenu = CreateMenu();
  AppendMenuA(hGameMenu, MF_STRING, MENU_GAME_NEW, "New");
  AppendMenuA(hGameMenu, MF_SEPARATOR, NULL, NULL);
  AppendMenuA(hGameMenu, MF_STRING, MENU_GAME_EXIT, "Exit");
  AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hGameMenu, "Game");

  SetMenu(hwnd, hMenu);
}

void addElements(HWND hwnd) {
  CreateWindow("Static", "Jogador 1", WS_VISIBLE | WS_CHILD, 10, 10, 400, 20,
               hwnd, NULL, NULL, NULL);

  hEdit = CreateWindow("Static", "0", WS_VISIBLE | WS_CHILD, 30, 40, 20, 20,
                       hwnd, NULL, NULL, NULL);

  CreateWindow("Static", "Jogador 2", WS_VISIBLE | WS_CHILD, 410, 10, 400, 20,
               hwnd, NULL, NULL, NULL);

  hEdit = CreateWindow("Static", "0", WS_VISIBLE | WS_CHILD, 435, 40, 20, 20,
                       hwnd, NULL, NULL, NULL);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  CreateWindow("Button", "Novo Jogo", WS_VISIBLE | WS_CHILD, 190, 30, 100, 35,
               hwnd, (HMENU)ELEMENT_BUTTON, NULL, NULL);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // LINHA 1
  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 10, 100, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 110, 100, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 210, 100, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 310, 100, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 410, 100, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // LINHA 2

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 10, 200, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 110, 200, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 210, 200, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 310, 200, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 410, 200, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // LINHA 3

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 10, 300, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 110, 300, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 210, 300, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 310, 300, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 410, 300, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // LINHA 4

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 10, 400, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 110, 400, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 210, 400, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 310, 400, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, 410, 400, 65, 65, hwnd,
               (HMENU)ELEMENT_BUTTON, NULL, NULL);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  HWND hStaticImage =
      CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 10, 90,
                   400, 20, hwnd, NULL, NULL, NULL);
}

