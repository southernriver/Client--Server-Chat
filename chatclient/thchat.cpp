#include"thchat.h"
#include<unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<cstdio>
#include<string.h>
using namespace std;

void ThChat::init()
{
	sprintf(client.ip,"%s","192.168.31.134");
	client.port=8888;
	client.initSocket();
	r=client.connect();
}
void ThChat::run()     //管理发送数据
{
          //      r=client.connect();
		if(r==0)
		{
			//
		  	const char *buf; 
        	        QString str=info->text();
	          //      QByteArray ba=str.toLatin1();
			buf=str.toStdString().data();
                //	buf=ba.data();
			send(client.fd,buf,20,0);
					
			emit sigInfo(str);
		//	printf("%s\n",info);
				
			//usleep(100000);
			
			
		}
	

}
