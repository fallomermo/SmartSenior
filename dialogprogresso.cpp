#include "dialogprogresso.h"
#include "ui_dialogprogresso.h"

DialogProgresso::DialogProgresso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogProgresso)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    QMovie *movie = new QMovie(":/rc/interface/loading.gif");

    ui->label->setMovie(movie);
    movie->start();
}

DialogProgresso::~DialogProgresso()
{
    delete ui;
}

void DialogProgresso::fechar()
{
    this->close();
}
