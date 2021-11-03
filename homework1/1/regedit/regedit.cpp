// regedit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	HKEY hRoot = HKEY_LOCAL_MACHINE;
	const char* Register = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
	const char* notepad = "C:\\Windows\\notepad.exe";
	HKEY hKey;

	if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, Register, 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
	{
		if (RegSetValueExA(hKey, "notepad_run", 0, REG_SZ, (BYTE*)notepad, strlen(notepad)) == ERROR_SUCCESS)
		{
			printf("succeed!\n");
		}
		else
		{
			printf("Failed2!");
			RegCloseKey(hKey);
			return -1;
		}
		RegCloseKey(hKey);

	}
	else
	{
		printf("Failed!");
		return -1;
	}
	return 0;
}
