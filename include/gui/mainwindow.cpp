#include "mainwindow.h"

#include "dayfocus.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setCentralWidget(new DayFocus(nullptr, this));
}

MainWindow::~MainWindow()
{
}
