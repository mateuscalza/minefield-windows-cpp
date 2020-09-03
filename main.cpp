#include <windows.h>

#define MENU_GAME_NEW 50
#define MENU_GAME_EXIT 51
#define WIDTH 5
#define HEIGHT 4

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
  AppendMenuA(hGameMenu, MF_STRING, MENU_GAME_NEW, "Novo jogo");
  AppendMenuA(hGameMenu, MF_SEPARATOR, NULL, NULL);
  AppendMenuA(hGameMenu, MF_STRING, MENU_GAME_EXIT, "Sair");
  AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hGameMenu, "Opções");

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
               hwnd, (HMENU)MENU_GAME_NEW, NULL, NULL);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  int index = 0;
  for(int row = 0; row < HEIGHT; row++) {
	  for(int column = 0; column < WIDTH; column++) {
	  	CreateWindow("Button", "", WS_VISIBLE | WS_CHILD, column * 100 + 10, row * 100 + 100, 65, 65, hwnd,
               (HMENU)index, NULL, NULL);
	  	index++;
	  }
  }

  HWND hStaticImage =
      CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 10, 90,
                   400, 20, hwnd, NULL, NULL, NULL);
}

