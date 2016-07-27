#include"ThClient.h"
#include"ServerWindow.h"
#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//静态成员必须实例化
list<ThClient*> ServerWindow::allusers;
void ThClient::run()
{
	int r;
	char buf[1024];
	while(true)
	{
		r=recv(fd,buf,sizeof(buf),0);
		if(r<=0)
		{
			//emit 
			emit sigInfo("有客户退出");
			ServerWindow::allusers.remove(this);
			close(fd);
			break;
		}
		buf[r]=0;
		//发送消息，把结束数据显示到服务器主窗体
		//广播
		emit sigInfo(buf);
		list<ThClient*>::iterator it=ServerWindow::allusers.begin();
		while(it!=ServerWindow::allusers.end())
		{
			send((*it)->fd,buf,strlen(buf),0);
			it++;
		}
	}
}

