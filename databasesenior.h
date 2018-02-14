#ifndef DATABASESENIOR_H
#define DATABASESENIOR_H

#include <QMap>
#include <QDebug>
#include <QObject>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlTableModel>

#include "objcolaborador.h"

class DatabaseSenior : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseSenior(QObject *parent = nullptr);

    bool conectar();
    QSqlTableModel *pesquisarColaboradorMod(QString);
    QMap<int, ObjColaborador *> pesquisarColaboradorMap(QString);

signals:
    void mensagemRetorno(int, QString, QString);

private slots:

private:
    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // DATABASESENIOR_H
