#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H
#include<QObject>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
class ClientSocket:public QObject
{
public:
	char ip[30];
	short port;
	int fd;
	struct sockaddr_in addr;
public:
	void  initSocket();   //
	int connect();
};

#endif
