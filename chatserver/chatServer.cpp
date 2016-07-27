#include<QApplication>
#include"ServerWindow.h"
int main(int args,char** argv)
{
	QApplication app(args,argv);
	ServerWindow sw;
	return app.exec();
}
