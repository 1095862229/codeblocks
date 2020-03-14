#include "stdafx.h"
#include <WINSOCK2.H> // 用于管理Windows Sockets版本2函数的头文件
#pragma comment(lib,"WS2_32.lib")
#include "stdlib.h"
#include "iostream"
using namespace std;


int main(int argc, char **argv)
{
	sockaddr_in s_addr;
	int sock;
	int addr_len;
	int len;
	char buff[128];

	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		perror("socket");
		exit(errno);
	} else
		printf("create socket.\n\r");

	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(7838);
	if (argv[1])
		s_addr.sin_addr.s_addr = inet_addr(argv[1]);
	else {
		printf("input sever ip!\n");
		exit(0);
	}

	addr_len = sizeof(s_addr);
	strcpy(buff, "hello i'm here");
	len = sendto(sock, buff, strlen(buff), 0,
			(struct sockaddr *) &s_addr, addr_len);
	if (len < 0) {
		printf("\n\rsend error.\n\r");
		return 3;
	}

	printf("send success.\n\r");
	return 0;
}
