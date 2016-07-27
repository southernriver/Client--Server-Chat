#include"ChatException.h"
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
ChatException::ChatException()
{
	memset(msg,0,sizeof(msg));
	sprintf(msg,"聊天异常!");
}
ChatException::ChatException(const char* m)
{
	memset(msg,0,sizeof(msg));
	sprintf(msg,"聊天异常:%s!",m);
}
const char*  ChatException::what() const throw() 
{
	return msg;
}
