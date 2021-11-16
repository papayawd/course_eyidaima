
/*
    IAT HOOK
    Inline HOOK

*/

#include <stdio.h>
#include <Windows.h>
#include "detours.h"

#pragma comment(lib, "detours.lib")

static int (WINAPI* OLD_MessageBoxW)(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType) = MessageBoxW;
int WINAPI NEW_MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
    int ret = OLD_MessageBoxW(hWnd, L"我的HOOK", lpCaption, uType);
    return ret;
}

VOID Hook()
{
    DetourRestoreAfterWith();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());  // 当前线程hook
    DetourAttach(&(PVOID&)OLD_MessageBoxW, NEW_MessageBoxW);
    DetourTransactionCommit(); // 提交
}

VOID UnHook()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());  // 当前线程hook
    DetourDetach(&(PVOID&)OLD_MessageBoxW, NEW_MessageBoxW);
    DetourTransactionCommit(); // 提交
}



int main()
{
    MessageBoxW(0, L"正常消息框", 0, 0);
    Hook();
    MessageBoxW(0, L"正常消息框", 0, 0);
    UnHook();
    return 0;

}
