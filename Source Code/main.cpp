#include "bac.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication guiInterface(argc, argv); // create the application gui class
    bCalcu mainWindow; // create the main window
    mainWindow.show(); // display the program window

    guiInterface.setWindowIcon(QIcon(":/interface/icon1.ico")); // sets window icon to ico1
    return guiInterface.exec();
}
