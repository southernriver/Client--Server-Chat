#ifndef THCHAT_H
#define THCHAT_H
#include<QThread>
#include<QLineEdit>
#include"clientsocket.h"
#include<QString>
class ThChat:public QThread
{
Q_OBJECT
public:
	QLineEdit *info;
public:
	ClientSocket client;  //
public:
	int r;    //
	void init();      //
	void run();
public: signals:
	void sigInfo(const QString &);
};

#endif
