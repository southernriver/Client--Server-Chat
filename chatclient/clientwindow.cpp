#include"clientwindow.h"
#include<stdio.h>
#include<stdio.h>
#include<string.h>
//将即将要发送的聊天信息QLineEdit(edtmsg)显示到QTextEdit(edtinfo)
//方法2：send案件单独调用一次，来显示
void ClientWindow::show()
{
 	char *buf;    
        QString str=edtmsg->text();
        QByteArray ba=str.toLatin1();
        buf=ba.data();

        edtinfo->append(buf);
}

void ClientWindow::onSend()
{
       //方法1,一次调用connect函数,直接追加
/*	char *buf;    
        QString str=edtmsg->text();
        QByteArray ba=str.toLatin1();
        buf=ba.data();

	edtinfo->append(buf);
*/
//	disconnect(btnsend,0,edtmsg,0);
//	connect(&thchat,SIGNAL(sigInfo(const QString&)),
//		edtinfo,SLOT(append(const QString &)));
//	usleep(100000);
//	edtinfo->disconnect();
	thchat.start(); //启动客户端
}

ClientWindow::ClientWindow(QWidget *p)
{

	center=new QWidget(this);
	edtinfo=new QTextEdit(center);   //放在center上面
	edtmsg=new QLineEdit(center) ;
	btnsend=new QPushButton("send",center);
	//横着两条，竖着两条
	hlay=new QVBoxLayout(center);
	hlay->addWidget(edtinfo);
	
	vlay=new QHBoxLayout();
	hlay->addLayout(vlay);
	//子布局
	vlay->addWidget(edtmsg);
	vlay->addWidget(btnsend);

	this->setCentralWidget(center);

	//
	edtinfo->append("客户端发送线程启动");
	thchat.init();
	QString num=QString::number(thchat.client.fd);
	edtinfo->append(num);
        thchat.info=edtmsg;        //获取输入的聊天信息，保存发送
	//绑定btnsen的clicked函数和当前的onSend函数
	connect(btnsend,SIGNAL(clicked()),this,SLOT(onSend()));

	//方法2.调用按钮send直接将要发送的数据显示到QTextEdit
	//特别注意：方法1和2都是不可靠的，因为必须要确定发送成功之后才能显示
	//否则是不可靠的，也可能发送失败，这种情况下还是会显示的，产生误判
	//connect(btnsend,SIGNAL(clicked()),this,SLOT(show()));


	//方法3.把该绑定放在构造函数里面，否则会有重复效应！!!
        connect(&thchat,SIGNAL(sigInfo(const QString&)),
                edtinfo,SLOT(append(const QString &)));
	this->setVisible(true);
}
