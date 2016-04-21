#include "hopphen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HoppHen hoppHen;
	hoppHen.show();
	return a.exec();
}
