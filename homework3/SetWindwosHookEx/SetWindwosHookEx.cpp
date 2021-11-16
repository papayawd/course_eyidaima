// SetWindwosHookEx.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include<Windows.h>

HHOOK hHook;


int main()
{
	HMODULE hDll = LoadLibraryA("dllmain.dll");
	if(hDll == NULL)
	{
		printf("dll load error\n");
		return 0;
	}	
	FARPROC KeyboardProc = (FARPROC)GetProcAddress(hDll, "?HOOKFUNC@@YGJHIJ@Z");
	if(KeyboardProc == NULL)
	{
		printf("function find error\n");	
		FreeLibrary(hDll);	
		return 0;
	}
	hHook = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)KeyboardProc, hDll, 0);
	if(hHook == NULL) 
	{	
		printf("hook set error\n");
		FreeLibrary(hDll);
		return 0;
	}

	getchar();	
	UnhookWindowsHookEx(hHook);
	FreeLibrary(hDll);
	
	
	return 0;
}

