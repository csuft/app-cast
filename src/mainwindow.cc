#include "mainwindow.hpp"

#include "ui_main_window.h"
#include "winsparkle.h"

MainWindow::MainWindow(QWidget* parent) 
	: ui(new Ui::MainWindow){
	ui->setupUi(this);

	connect(ui->actionCheck_Updates, &QAction::triggered, this, &MainWindow::onCheckUpdatesTriggered);
}

void MainWindow::onCheckUpdatesTriggered() {
	win_sparkle_check_update_with_ui();
}

MainWindow::~MainWindow() {
	delete ui;
}