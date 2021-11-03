// client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma comment(lib, "ws2_32.lib")	// ��Ҫ���������ӿ�

#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>	// windows socket  2.2�汾

void main(void)
{
    WSADATA		wsaData;	// ������ʼ���׽���
    SOCKET		SendingSocket;	// �ͻ����׽���
    SOCKADDR_IN		ReceiverAddr;	// ����˵�ַ
    int			ReceiverAddrSize = sizeof(SOCKADDR); // ����˵�ַ�Ĵ�С
    int    		Port = 4444;	// �˿ں�

    
    // ��ʼ��������Ϣ����ʼ�׽��֣�
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    
    // �����׽���
    SendingSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // ��ʼ������˵�ַ
    ReceiverAddr.sin_family = AF_INET;
    ReceiverAddr.sin_port = htons(Port);
    ReceiverAddr.sin_addr.S_un.S_addr = inet_addr("192.168.150.134"); // �����������в�����������ߵĳ�ʼ��

    while(1)		// ��ʼ��������  ��������
    {
        char buffer[1024] = "\0";	// ���ڷ��� ���յ�����

        printf("Input message:\n");
        scanf("%s", buffer);		// ����Ҫ���͵�����

        if(strcmp(buffer, "bye") == 0)	// �����Ի��ж� 
            break;

        // ��������
        if(sendto(SendingSocket, buffer, sizeof(buffer), 0, (SOCKADDR*)&ReceiverAddr, 
            sizeof(ReceiverAddr)) != SOCKET_ERROR)
        {
            // ���ͳɹ��󣬽����մӷ�����Ǳ߷�����������
            if (recvfrom(SendingSocket, buffer, sizeof(buffer), 0, (SOCKADDR*)&ReceiverAddr,
                &ReceiverAddrSize) != SOCKET_ERROR)
            {
                // �ɹ��������ݣ���ӡ����
            	printf("Received from server: %s\n", buffer);
            }
            
        }    
    }    
    
    closesocket(SendingSocket);	// �ͷ��׽���
    WSACleanup();		// ���������Ϣ
    
    system("pause");
}