#include "dialoglogin.h"
#include "ui_dialoglogin.h"

DialogLogin::DialogLogin(QWidget *parent) : QDialog(parent), ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
    connect(ui->campoUsuario, SIGNAL(returnPressed()), this, SLOT(focusCampoUsuario()));
    connect(ui->campoSenha, SIGNAL(returnPressed()), this, SLOT(focusCampoSenha()));
    connect(ui->botaoEntrar, SIGNAL(clicked(bool)), this, SLOT(focusBotaoEntrar()));
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::focusCampoUsuario()
{
    ui->campoSenha->setFocus();
}

void DialogLogin::focusCampoSenha()
{
    ui->botaoEntrar->setFocus();
}

void DialogLogin::focusBotaoEntrar()
{
    this->autenticarUsuario();
}

void DialogLogin::autenticarUsuario()
{
    QString u = "admin";
    QString p = "@adminadmin";

    if(u == ui->campoUsuario->text() && p == ui->campoSenha->text())
    {
        work = new WorkSpace(nullptr);
        work->showMaximized();
        this->close();
    } else {
        QMessageBox::critical(this, tr("Falha na Autenticação"), QString("Usuário e/ou Senha Inválidos!"), "    OK    ");
        ui->campoUsuario->clear();
        ui->campoSenha->clear();
        ui->campoUsuario->setFocus();
    }
}

QJsonObject DialogLogin::objectFromString(const QString &in)
{
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());

    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            obj = doc.object();
        }
        else
        {
            qDebug() << "Documento raiz não é um objeto Json" << endl;
        }
    }
    else
    {
        qDebug() << "JSON Inválido...\n" << in << endl;
    }
    return obj;
}

QString DialogLogin::getJsonFile() const
{
    return jsonFile;
}

void DialogLogin::setJsonFile(const QString &value)
{
    jsonFile = value;
}

QJsonDocument *DialogLogin::getJsonDocument() const
{
    return jsonDocument;
}

void DialogLogin::setJsonDocument(QJsonDocument *value)
{
    jsonDocument = value;
}
