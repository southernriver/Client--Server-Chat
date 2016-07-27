#include"ServerSocket.h" 
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
void ServerSocket::initSocket() throw(ChatException)
{
	struct sockaddr_in addr;
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd==-1)
		throw ChatException("socket错误");
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr=htonl(INADDR_ANY);

//	addr.sin_addr.s_addr=inet_addr(ip);
	int r=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1)
	{
		close(fd);
		throw ChatException("bind错误");
	}
	r=listen(fd,10);
	if(r==-1)
	{
		close(fd);
		throw ChatException("listen错误");
 	}
}
int ServerSocket::accept() throw(ChatException)
{
	int cfd;
	socklen_t cliaddr_len;
	cliaddr_len=sizeof(cliaddr);
	cfd=::accept(fd,(struct sockaddr*)&cliaddr,&cliaddr_len);
	if(cfd==-1)
	{
	//	close(fd);
		throw ChatException("accept错误");

	}
	return cfd;

}
