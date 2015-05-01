#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "question.h"
#include <QMainWindow>
#include <QLineEdit>
#include <QToolButton>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <iostream>
#include <QTextEdit>

class MainWindow : public QMainWindow
{

    Q_OBJECT

private:

    QLineEdit *display;
    QToolButton *button;
    QToolButton *reset;
    QLabel *tip;
    QGridLayout *layout;
    QWidget *screen;
    QTextEdit *counter;
    CGame *first;

public:

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void counterAdding();

private slots:

    void sendSubmit();
    void reroll();

};

#endif // MAINWINDOW_H
