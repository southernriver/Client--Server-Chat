#include"clientsocket.h"
void  ClientSocket::initSocket()
{
//	struct sockaddr_in addr;
	fd=socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr=inet_addr(ip);
}
int ClientSocket::connect()
{
	int r; 
        r=::connect(fd,(struct sockaddr*)&addr,sizeof(addr));
        if(r==-1)
        {
                close(fd); 
                return -1;
        }
        return 0;
}
