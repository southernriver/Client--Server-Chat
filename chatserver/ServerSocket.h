#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H
#include<QObject>
#include"ChatException.h"
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

class ServerSocket:public QObject
{
public:
	char ip[30];   //IP地址
	short port;    //端口号
	int fd;	       //文件描述符
public:
	struct sockaddr_in cliaddr;
public:
	void initSocket() throw(ChatException);
	int accept()      throw  (ChatException);	
};

#endif
