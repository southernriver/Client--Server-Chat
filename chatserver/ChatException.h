//封装异常类
//原因：
#ifndef  CHAT_EXCEPTION_H
#define CHAT_EXCEPTION_H
#include<exception>
using namespace std;
class ChatException: public exception
{
private:
	char msg[50];   //存放错误信息描述
public:
	ChatException();
	ChatException(const char *);
	const char* what() const throw();    //
};
#endif
