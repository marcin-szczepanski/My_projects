#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "papierowa.h"
#include "ebook.h"
#include "audiobook.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    template <class klasa>
    klasa* uzupelnijObiekt();

    template <class klasa>
    void wstawDoTabeli(klasa* wsk_obiekt);

    void wczytajDaneDoProgramu();

private slots:
    void on_dodajButton_clicked();

    void on_usun_clicked();

    void on_edytujButton_clicked();

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
