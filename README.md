# qt5-ChildProcess-lib
library for run child process for dynamically console output

# Usage lib in you project

clone this project near your project folder 

## Build
Open command prompt console and build library files:

> qmake
> mingw32-make release
> mingw32-make debug

## Add to your project
Open youProject.pro file and add following lines to end of file to connect library into your project

DEPENDPATH += . ../ChildProcess
INCLUDEPATH += ../ChildProcess
LIBS += -L../ChildProcess/debug -lChildProcess

## Your mainwindow.cpp file:

void MainWindow::runChildProcess()
{
    Process *tempProcess = new Process("ping google.com", this);
    connect(tempProcess, SIGNAL(readyRead(QByteArray)),
        this, SLOT(processResponded(QByteArray)));
    tempProcess->runCommand();
}

// MainWindow slots:
void MainWindow::processResponded(QByteArray p_Data) {
    qDebug() << p_Data;
}
