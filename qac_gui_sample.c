#include <windows.h>
#include <stdio.h>

/* マクロ多用による可読性低下 (Rule 20.1) */
#define DECLARE_GLOBAL_HANDLE(name) HWND name
#define SET_HANDLE(target, value) target = value
#define WINDOW_CLASS_NAME L"QACGuiSampleClass"
#define WINDOW_TITLE_TEXT L"QAC GUI Sample"
#define BUTTON_LABEL     L"Start"            /* ← ここを ASCII に */
#define DIALOG_MESSAGE   L"Start scanning..."/* ← ここも ASCII に */
#define DIALOG_CAPTION L"QAC Notice"
#define BUTTON_CLASS_NAME L"BUTTON"
#define MAIN_BUTTON_ID 1001
#define CREATE_START_BUTTON(parent)                                              \
    CreateWindowExW(0, BUTTON_CLASS_NAME, BUTTON_LABEL,                          \
                    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 110, 60, 200, 50,     \
                    (parent), (HMENU)(UINT_PTR)MAIN_BUTTON_ID,                   \
                    GetModuleHandleW(NULL), NULL)
#define MESSAGE_BOX_INFO(hwnd, text, caption)                                    \
    MessageBoxW((hwnd), (text), (caption), MB_OK | MB_ICONINFORMATION)
#define HANDLE_MESSAGE_BEGIN switch (message) {
#define HANDLE_MESSAGE_CASE(msg) case msg
#define HANDLE_MESSAGE_END }

DECLARE_GLOBAL_HANDLE(gMainWindow); /* グローバル変数の定義 (Rule 8.7) */

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void StartScanSequence(HWND hwnd);    /* グローバル関数で複数呼び出し (CMA) */
void DisplayScanDialog(HWND hwnd);
void SimulateDfaIssue(void);
void LogButtonActivity(void);
void UnusedHelperFunction(void);      /* 使用されていない関数定義 (Rule 2.2) */

void StartScanSequence(HWND hwnd)
{
    /* printf 系使用 (Rule 21.6) */
    printf("StartScanSequence invoked.\n");

    /* グローバル関数からの複数呼び出し (CMA) */
    LogButtonActivity();
    SimulateDfaIssue();
    DisplayScanDialog(hwnd);
}

void DisplayScanDialog(HWND hwnd)
{
    MESSAGE_BOX_INFO(hwnd, DIALOG_MESSAGE, DIALOG_CAPTION);
}

void LogButtonActivity(void)
{
    /* printf 系使用 (Rule 21.6) */
    printf("Button \"Start\" pressed.\n"); /* ASCII のみに変更 */
}

void SimulateDfaIssue(void)
{
    int suspiciousValue; /* 条件分岐で未初期化変数使用 (DFA 学習用) */

    if ((GetTickCount() % 2U) == 0U)
    {
        /* 故意に未初期化のまま使用 → QAC の DFA が警告を出す */
        if (suspiciousValue > 0)
        {
            printf("Suspicious value: %d\n", suspiciousValue);
        }
    }
}

void UnusedHelperFunction(void)
{
    OutputDebugStringW(L"This helper is intentionally unused.\n");
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HANDLE_MESSAGE_BEGIN
        HANDLE_MESSAGE_CASE(WM_CREATE):
            SET_HANDLE(gMainWindow, hwnd);
            CREATE_START_BUTTON(hwnd);
            return 0;

        HANDLE_MESSAGE_CASE(WM_COMMAND):
        {
            switch (LOWORD(wParam)) /* switch 文に default 節なし (Rule 16.4) */
            {
                case MAIN_BUTTON_ID:
                    StartScanSequence(hwnd);
                    break;
            }
            return 0;
        }

        HANDLE_MESSAGE_CASE(WM_DESTROY):
            PostQuitMessage(0);
            return 0;
    HANDLE_MESSAGE_END

    return DefWindowProcW(hwnd, message, wParam, lParam);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR lpCmdLine,
                      _In_ int nCmdShow)
{
    (void)hPrevInstance;
    (void)lpCmdLine;

    WNDCLASSEXW wcex = {0};
    wcex.cbSize = sizeof(WNDCLASSEXW);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = hInstance;
    wcex.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszClassName = WINDOW_CLASS_NAME;

    if (!RegisterClassExW(&wcex))
    {
        return -1;
    }

    HWND hwnd = CreateWindowExW(0,
                                WINDOW_CLASS_NAME,
                                WINDOW_TITLE_TEXT,
                                WS_OVERLAPPEDWINDOW,
                                CW_USEDEFAULT,
                                0,
                                420,
                                220,
                                NULL,
                                NULL,
                                hInstance,
                                NULL);

    if (hwnd == NULL)
    {
        return -1;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessageW(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return (int)msg.wParam;
}
