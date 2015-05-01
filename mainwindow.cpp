#include "mainwindow.h"
#include "question.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    first = new CGame;
    screen = new QWidget (this);
    layout = new QGridLayout (screen);

    this -> setCentralWidget (screen);
    this -> setFixedSize (400,90);

    display = new QLineEdit ("");
    button = new QToolButton;
    tip = new QLabel ("Guess number from 1 to 100");
    reset = new QToolButton;
    counter = new QTextEdit;

    button -> setText ("&Submit Answer");
    button -> setGeometry (15,15,150,30);

    counter -> setReadOnly (true);

    reset -> setText ("&Reroll");
    reset -> setGeometry (15,15,150,30);

    layout -> addWidget (button,2,2);
    layout -> addWidget (display,1,2);
    layout -> addWidget (tip,1,1);
    layout -> addWidget (reset,2,1);
    layout -> addWidget (counter, 1,3,2,1,0);
    layout -> setColumnMinimumWidth (1,150);

    connect ( display, SIGNAL(returnPressed()), this, SLOT(sendSubmit()));
    connect ( button, SIGNAL(clicked()), this , SLOT(sendSubmit()));
    connect ( reset, SIGNAL(clicked()), this, SLOT(reroll()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::sendSubmit()
{

    int numba;

    numba = ( display -> text().toInt() );

    first -> answer(numba);

    if ( first -> check(numba) )
    {
        tip -> setText("Congratz, you won! Reroll?");
    }
    else if ( first -> highlow() )  tip -> setText ("Too low! Try Again!");
    else tip -> setText ("Too high! Try Again!");

    counterAdding();

    display -> setText("");

}

void MainWindow::reroll()
{

    first -> randomize();
    tip -> setText ("Guess number from 1 to 100");
    display -> setText ("");
    counter -> clear();

}

void MainWindow::counterAdding()
{

    QString text;

    text = ( display -> text() );

    if ( first -> highlow() == 1 )  text += " is too Low";
     else if ( first -> highlow() == 0 ) text += " is too High";
      else text += " is Correct!";

    counter -> append(text);

}
