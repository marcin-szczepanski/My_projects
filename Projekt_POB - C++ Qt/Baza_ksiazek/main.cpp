#include "mainwindow.h"
#include "ebook.h"
#include "audiobook.h"
#include "papierowa.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
