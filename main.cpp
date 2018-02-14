#include "workspace.h"
#include "dialoglogin.h"
#include <QApplication>

DialogLogin *login()
{
    static auto login = new DialogLogin(nullptr);
    return login;

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login()->show();
    login()->activateWindow();

    return a.exec();
}
