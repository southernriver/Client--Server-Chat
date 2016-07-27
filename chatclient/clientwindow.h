#ifndef CLIENT_WINDOW_H
#define CLIENT_WINDOW_H
#include<QMainWindow>
#include<QWidget>
#include<QTextEdit>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include"thchat.h"
class ClientWindow:public QMainWindow
{
Q_OBJECT
private:
	QWidget *center;
	QTextEdit *edtinfo;
	QLineEdit *edtmsg;   //输入的聊天信息
	QPushButton *btnsend;   //发送按钮
	
	//布局
	QVBoxLayout *hlay;
	QHBoxLayout *vlay;
public:
	ClientWindow(QWidget *p=NULL);
public:
	ThChat thchat;       //client
public slots:
	void onSend();
public slots:
	void show();
};


#endif
