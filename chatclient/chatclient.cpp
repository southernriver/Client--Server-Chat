#include<QApplication>
#include"clientwindow.h"
#include"clientsocket.h"
int main(int args,char** argv)
{
	QApplication app(args,argv);
	ClientWindow dlg;


	return app.exec();

}
