#include "helpwindow.h"
#include "ui_helpwindow.h"

helpWindow::helpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::helpWindow)
{
    ui->setupUi(this);
}

helpWindow::~helpWindow()
{
    delete ui;
}
