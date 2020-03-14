#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#define BUFLEN 1024

int main(int argc, char** argv)
{
	SOCKET soc;
	SOCKADDR_IN addr;
	unsigned char buf[BUFLEN];
    unsigned char recvbuf[BUFLEN];
    int recv_num;
    int flag=0;
    WSADATA wsa;
	WSAStartup(MAKEWORD(2,2),&wsa);	//initial Ws2_32.dll by a process
    int ret;
    int send_num;
	memset(&addr, 0, sizeof(addr));


	if((soc = socket(AF_INET,SOCK_DGRAM,0)) <= 0)
	{
		printf("Create socket fail!\n");
		return -1;
	}

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	addr.sin_port = htons(4567);
	bind(soc,(struct sockaddr *)&addr,sizeof(addr));


	while(1) {
        if(flag==0)
        {
            printf("请输入向服务器发送的数据:");
            scanf("%s", buf);
            send_num=sendto(soc, buf, strlen(buf)+1, 0, (struct sockaddr *)&addr, sizeof(addr));
            buf[send_num] = '\0';
        }
        else
        {
            recv_num=recvfrom(soc, recvbuf, sizeof(recvbuf), 0, NULL, NULL);
            printf("%d",recv_num);
            recvbuf[recv_num] = '\0';
            printf("打印从服务器接收的数据：%s\n",recvbuf);
            flag=1;
        }
        if(strcmp(buf,"receive")==0)
        {
            flag=1;
        }
        if(strcmp(recvbuf,"receive")==0)
        {
            flag=0;
        }
        if(strcmp(buf,"quit")==0)
        {
            printf("  通讯关闭...");//当服务器发来bye时，关闭socket
            break;
        }
        if(strcmp(recvbuf,"quit")==0)
        {
            printf("  通讯关闭...");//当服务器发来bye时，关闭socket
            break;
        }
	}


	WSACleanup();	//clean up Ws2_32.dll
	return 0;
}
