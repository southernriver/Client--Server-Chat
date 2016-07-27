#ifndef SERVER_WINDOW_H
#define SERVER_WINDOW_H
#include<QMainWindow>
#include<QWidget>
#include<QTextEdit>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QStatusBar>
#include<QLabel>
#include"ThAccept.h"
#include"ThClient.h"
#include<list>
using namespace std;
class ServerWindow:public QMainWindow
{
Q_OBJECT
public:
	static list<ThClient*>   allusers;    //链表存放客户fd
private:
	QTextEdit *info;       
	//菜单
	QMenuBar *bar;
	QMenu    *mnuserver;
	QAction  *actstart;
	QAction  *actexit;

	//状态条
	QStatusBar *status;
	QLabel  *lbltip;
	QLabel  *lblresult;
	QLabel  *lbltime;

	//接收线程
	ThAccept thaccept;
public:
	ServerWindow(QWidget *p=NULL);
public slots:
	void onStart();
};


#endif
