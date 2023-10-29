/*
  SIMPLE WINDOW - Copyright © 2000,2005 Ken Fitlike

  API functions used:

  - `CreateWindowEx`

  - `DefWindowProc`

  - `DispatchMessage`

  - `GetMessage`

  - `GetSystemMetrics`

  - `LoadImage`

  - `MessageBox`

  - `PostQuitMessage`

  - `RegisterClassEx`

  - `ShowWindow`

  - `TranslateMessage`

  - `UpdateWindow`

  - `WinMain`

  This example creates a window, half the height and half the width of the
  desktop which is centred on the desktop.

  `WinMain` is the entry point function for winapi applications (equivalent to
  main). `_tWinMain` is a placeholder for `WinMain` (non-unicode fn) or
  `wWinMain` (unicode) but, since there is currently no `wWinMain` defined for
  MinGW just use `WinMain`. If a unicode command line string is required then
  use the `GetCommandLine` function.
*/
#include <tchar.h>    // string and other mapping macros
#include <windows.h>  // all the basics
#include <string>

// Define an unicode string type alias.
typedef std::basic_string<TCHAR> ustring;

// message processing function declarations.
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// non-message function declarations
inline int ErrMsg(const ustring&);

//=============================================================================
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR pStr, int nCmd) {
  ustring classname = _T("SIMPLEWND");
  WNDCLASSEX wcx = {0};  // used for storing information about the wnd 'class'

  wcx.cbSize = sizeof(WNDCLASSEX);
  wcx.lpfnWndProc = WndProc;  // wnd Procedure pointer
  wcx.hInstance = hInst;      // app instance

  // use 'LoadImage' to load wnd class icon and cursor as it supersedes the
  // obsolete functions 'LoadIcon' and 'LoadCursor', although these functions
  // will still work. Because the icon and cursor are loaded from system
  // resources ie they are shared, it is not necessary to free the image
  // resources with either 'DestroyIcon' or 'DestroyCursor'.
  wcx.hIcon = reinterpret_cast<HICON>(
      LoadImage(0, IDI_APPLICATION, IMAGE_ICON, 0, 0, LR_SHARED));

  wcx.hCursor = reinterpret_cast<HCURSOR>(
      LoadImage(0, IDC_ARROW, IMAGE_CURSOR, 0, 0, LR_SHARED));

  wcx.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BTNFACE + 1);

  wcx.lpszClassName = classname.c_str();

  // The window 'class' (not c++ class) has to be registered with the system
  // before windows of that 'class' can be created.
  if (!RegisterClassEx(&wcx)) {
    ErrMsg(_T("Failed to register wnd class"));
    return -1;
  }

  int desktopwidth = GetSystemMetrics(SM_CXSCREEN);

  int desktopheight = GetSystemMetrics(SM_CYSCREEN);

  HWND hwnd = CreateWindowEx(0,                    // extended styles
                                 classname.c_str(),    // name: wnd 'class'
                                 _T("Simple Window"),  // wnd title
                                 WS_OVERLAPPEDWINDOW,  // wnd style
                                 desktopwidth / 4,     // position:left
                                 desktopheight / 4,    // position: top
                                 desktopwidth / 2,     // window width
                                 desktopheight / 2,    // window height
                                 0,                    // parent window handle
                                 0,                    // menu handle/wnd id
                                 hInst,                // app instance
                                 0);                   // user defined info
      
  if (!hwnd) {
    ErrMsg(_T("Failed to create window!"));
    return -1;
  }

  ShowWindow(hwnd, nCmd);

  UpdateWindow(hwnd);

  // start message loop - windows applications are 'event driven' waiting on
  // user, application or system signals to determine what action, if any, to
  // take. Note that an error may cause GetMessage to return a negative value so,
  // ideally, this result should be tested for and appropriate action taken to
  // deal with it(the approach taken here is to simply quit the application).
  MSG msg;
  while (GetMessage(&msg, 0, 0, 0) > 0) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return static_cast<int>(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
    case WM_DESTROY:
      PostQuitMessage(0);  // signal end of application
      return 0;
    default:
      // Let system deal with msg.
      return DefWindowProc(hwnd, uMsg, wParam, lParam);
  }
}

inline int ErrMsg(const ustring& s) {
  return MessageBox(0, s.c_str(), _T("ERROR"), MB_OK | MB_ICONEXCLAMATION);
}
