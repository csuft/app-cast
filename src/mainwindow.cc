#include "mainwindow.hpp"

#include "ui_main_window.h"
#ifdef Q_OS_WIN
#include "winsparkle.h"
#else
#include "mac/SparkleAutoUpdater.h"
#endif

MainWindow::MainWindow(QWidget* parent) 
	: ui(new Ui::MainWindow){
	ui->setupUi(this);

	connect(ui->actionCheck_Updates, &QAction::triggered, this, &MainWindow::onCheckUpdatesTriggered);
}

void MainWindow::onCheckUpdatesTriggered() {
#ifdef Q_OS_WIN
	win_sparkle_check_update_with_ui();
#else
    auto updater = new SparkleAutoUpdater("http://0.0.0.0:8000/appcast.xml");
    if (updater) {
        updater->checkForUpdates();
    }
#endif
}

MainWindow::~MainWindow() {
	delete ui;
}
