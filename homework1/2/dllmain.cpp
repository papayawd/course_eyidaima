// dllmain.cpp : 定义 DLL 应用程序的入口点。

#include "pch.h"
#include <stdio.h>
extern "C" __declspec (dllexport) int READFILE(char* FileName)
{
    FILE* fp;
    fopen_s(&fp, FileName, "rb+");
    if (fp == NULL)
    {
        printf("open error\n");
        return 0;
    }
    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(fp);
    return 1;
}
extern "C" __declspec (dllexport) int WRITEFILE(char* FileName,char* Buffer)
{
    FILE* fp;
    fopen_s(&fp, FileName, "rb+");
    if (fp == NULL)
    {
        printf("open error\n");
        return 0;
    }
    fwrite(Buffer, strlen(Buffer), 1, fp);
    fclose(fp);
    return 1;
}


VOID Process_Attach()
{
    printf("process attached\n");
}

VOID Process_Detach()
{
    printf("process detached\n");
}

VOID Thread_Attach()
{
    printf("thread attached\n");
}

VOID Thread_Detach()
{
    printf("thread detached\n");
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Process_Attach(); break;
    case DLL_THREAD_ATTACH:
        Thread_Attach(); break;
    case DLL_THREAD_DETACH:
        Thread_Detach(); break;
    case DLL_PROCESS_DETACH:
        Process_Detach(); break;
        break;
    }
    return TRUE;
}

