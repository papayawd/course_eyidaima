// dllmain.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "dllmain.h"
#include <windows.h>

HHOOK hHook = NULL;

__declspec (dllexport) LRESULT CALLBACK HOOKFUNC(int nCode, WPARAM wParam, LPARAM lParam)
{
	if(wParam == VK_TAB)
		MessageBoxW(0, L"你按下了TAB按钮", 0, 0);
	return CallNextHookEx(hHook, nCode, wParam, lParam);
}
