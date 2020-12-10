#include <QApplication>
#include <QResource>

#include "mainwindow.hpp"
#ifdef Q_OS_WIN
#include "winsparkle.h"
#else
#include "mac/CocoaInitializer.h"
#include "mac/SparkleAutoUpdater.h"
#endif

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	MainWindow mainWindow;
	mainWindow.show();

#ifdef Q_OS_WIN
	win_sparkle_set_appcast_url("https://raw.githubusercontent.com/csuft/app-cast/master/doc/appcast.xml");
	win_sparkle_set_app_details(L"insta360.com", L"Nova Studio", L"1.0.0");
	win_sparkle_set_dsa_pub_pem(reinterpret_cast<const char*>(QResource(":/key/dsa_pub.pem").data()));
#else
    CocoaInitializer initializer;
    auto updater = new SparkleAutoUpdater("http://0.0.0.0:8000/appcast.xml");
    if (updater) {
        updater->checkForUpdates();
    }
#endif
    
	int a = app.exec();

#ifdef Q_OS_WIN
	win_sparkle_cleanup();  
#endif
	return a;
}
