#include "MovementInterpolation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MovementInterpolation w;
	w.show();
	return a.exec();
}
