#include <QApplication>
#include <QResource>

#include "mainwindow.hpp"
#include "winsparkle.h"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	MainWindow mainWindow;
	mainWindow.show();

	win_sparkle_set_appcast_url("https://raw.githubusercontent.com/csuft/app-cast/master/doc/appcast.xml");
	win_sparkle_set_app_details(L"insta360.com", L"Nova Studio", L"1.0.0");
	win_sparkle_set_dsa_pub_pem(reinterpret_cast<const char*>(QResource(":/key/dsa_pub.pem").data()));

	int a = app.exec();

	win_sparkle_cleanup();  

	return a;
}