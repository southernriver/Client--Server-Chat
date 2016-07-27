#include"ThAccept.h"
#include<cstdio>
#include"ThClient.h"
#include"ServerWindow.h"
void ThAccept:: init()  throw(ChatException)
{
	sprintf(server.ip,"%s","192.168.31.134");
	server.port=8000;
	try
	{
		server.initSocket();

	}
	catch(ChatException e)
	{
		throw e;
	}
}
void ThAccept::run()
{
	while(true)
	{
		try
		{
			int fd=server.accept();
			//发出信号
			printf("有人连接,打开的文件描述符为:%d\n",fd);
			char str[INET_ADDRSTRLEN];
			inet_ntop(AF_INET,&(server.cliaddr).sin_addr,str,sizeof(str));
		//	QString num=QString::number(str);
			emit sigInfo(str);
//			emit sigInfo("有人链接！");
			//建立子线程监听对应的客户

			//???空间怎么回收
		/*	ThClient  *th=new ThClient;
			th->fd=fd;
			th->start();
		*/
			//局部变量会消失
			//用链表指针来维护
		/*	ThClient th;
			th.fd=fd;
			ServerWindow.alluser.push_back(th);
			th.start();
		*/
			//指针对象来管理
    		        ThClient  *th=new ThClient;
                        th->fd=fd;
			ServerWindow::allusers.push_back(th);

			connect(th,SIGNAL(sigInfo(const QString&)),
				info,SLOT(append(const QString &)));
                        th->start();



		}
		catch(ChatException e)
		{
			//发出信号
			emit sigInfo("服务器崩溃！");
			break;
		}
	}
	
}
