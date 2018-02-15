#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QDialog>
#include <QFileInfo>
#include <QIODevice>
#include <QJsonArray>
#include <QTextStream>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonDocument>

#include "workspace.h"


namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = 0);
    ~DialogLogin();

    QJsonDocument *getJsonDocument() const;
    void setJsonDocument(QJsonDocument *value);

    QString getJsonFile() const;
    void setJsonFile(const QString &value);

private slots:
    void focusCampoUsuario();
    void focusCampoSenha();
    void focusBotaoEntrar();
    void autenticarUsuario();
    QJsonObject objectFromString(const QString& in);

private:
    Ui::DialogLogin *ui;
    WorkSpace *work;
    QJsonDocument *jsonDocument;
    QString jsonFile;
};

#endif // DIALOGLOGIN_H
