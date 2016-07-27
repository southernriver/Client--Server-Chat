#include"ServerWindow.h"
#include<QMessageBox>
#include"ChatException.h"
#include<QColor>
void ServerWindow::onStart()
{
//	QMessageBox::information(this,"提示","响应");
	try
	{
		thaccept.init();
		thaccept.info=info;
		info->setTextColor(QColor(0,255,0));
		info->append("服务器启动成功");
		//启动线程之前发送信号
		connect(&thaccept,SIGNAL(sigInfo(const QString&)),
			info,SLOT(append(const QString&)));

		thaccept.start();
		info->append("服务器接收线程启动！");
	}
	catch(ChatException e)
	{
		info->setTextColor(QColor(255,0,0));
		info->append(e.what());
	}
}
ServerWindow::ServerWindow(QWidget *p)
{
	//初始化窗体
	this->resize(1024,768);
	this->move(0,0);
	this->setWindowTitle("聊天服务器");
	//初始化组件
	info=new QTextEdit;
	info->setTextColor(QColor(255,0,0));
	info->append("欢迎使用聊天程序");
	info->append("================");  //自动换行
	info->setTextColor(QColor(0,255,0));
	info->insertPlainText("this is southernriver\n");  //需要手动换行
//	info->clear();	   //清空

	info->setFontPointSize(20);
	info->append("20号字体怎么样？");

	this->setCentralWidget(info);


	//初始化菜单
	bar=new QMenuBar(this);
	mnuserver=new QMenu("启动服务额",bar);
	actstart=new QAction("启动",mnuserver);
	actexit=new QAction("退出",mnuserver);
	mnuserver->addAction(actstart);
	mnuserver->addSeparator();
	mnuserver->addAction(actexit);
	bar->addMenu(mnuserver);
	this->setMenuBar(bar);
	
	//初始化状态栏
	status=new QStatusBar(this);
	lbltip=new QLabel("提示",status);
	lblresult=new QLabel("操作结果显示",status);
	lbltime=new QLabel("2016-7-27",status);
	status->addPermanentWidget(lbltip,300);
	status->addPermanentWidget(lblresult,500);
	status->addPermanentWidget(lbltime,0);
	this->setStatusBar(status);


	connect(actstart,SIGNAL(triggered()),this,SLOT(onStart()));
	this->setVisible(true);
}
