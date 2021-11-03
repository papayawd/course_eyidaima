#include<stdio.h>
#include<Windows.h>
using namespace std;

typedef int (*FREADFILE)(char *);
typedef int (*FWRITEFILE)(char*, char*);


DWORD WINAPI threadfunc(LPVOID p)
{
	printf("this is a thread\n");
	Sleep(1000);
	return 0;
}

int main()
{
	
	printf("��һ�μ���dll\n");
	HMODULE DLL1 = (HMODULE)LoadLibraryA("./Dll1.dll");
	Sleep(1000);
	printf("�ڶ��μ���dll\n");
	HMODULE DLL2 = (HMODULE)LoadLibraryA("./Dll1.dll");
	Sleep(1000);

	DWORD PID;
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)threadfunc, NULL, NULL, &PID);
	Sleep(5000);

	printf("��һ��ж��dll\n");
	FreeLibrary(DLL1);
	Sleep(1000);
	printf("�ڶ���ж��dll\n");
	FreeLibrary(DLL2);
	Sleep(1000);
	

	printf("�����μ���dll\n");
	HMODULE DLL3 = (HMODULE)LoadLibraryA("./Dll1.dll");
	FREADFILE READFILE = (FREADFILE)GetProcAddress(DLL3, "READFILE");
	FWRITEFILE WRITEFILE =(FWRITEFILE)GetProcAddress(DLL3, "WRITEFILE");
	Sleep(1000);

	printf("��ʼ���ļ�\n");
	char filename[] = "E:\\Visual Studio Project\\test\\main.cpp";
	char filename2[] = "E:\\Visual Studio Project\\test\\hello.txt";

	char buf[] = "Hello World\n";
	READFILE(filename);
	WRITEFILE(filename2, buf);
	
	Sleep(1000);
	printf("������ж��dll\n");
	FreeLibrary(DLL3);
	Sleep(1000);

	return 0;
}