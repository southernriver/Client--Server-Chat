#ifndef TH_ACCEPT_H
#define TH_ACCEPT_H
#include<QThread>
#include"ChatException.h"
#include"ServerSocket.h"
#include<QTextEdit>
class ThAccept:public QThread
{
Q_OBJECT
public:
	QTextEdit *info;
private:
	ServerSocket server;
public:
	void init()  throw (ChatException);
	void run();    //在线程中接受客户链接

public: signals:
	void sigInfo(const QString &);
};

#endif
