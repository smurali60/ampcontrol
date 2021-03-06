#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QSerialPort>

class SetupDialog;

class MainWindow : public QWidget, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    SetupDialog *dlgSetup;
    QSerialPort *sPort;


private slots:
    void openPort();
    void closePort();
    void sendRC();
};

#endif // MAINWINDOW_H
