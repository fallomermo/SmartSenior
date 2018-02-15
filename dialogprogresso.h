#ifndef DIALOGPROGRESSO_H
#define DIALOGPROGRESSO_H

#include <QDialog>
#include <QMovie>

namespace Ui {
class DialogProgresso;
}

class DialogProgresso : public QDialog
{
    Q_OBJECT

public:
    explicit DialogProgresso(QWidget *parent = 0);
    ~DialogProgresso();

private slots:
    void fechar();

private:
    Ui::DialogProgresso *ui;
};

#endif // DIALOGPROGRESSO_H
