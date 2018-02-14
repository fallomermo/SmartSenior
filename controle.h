#ifndef CONTROLE_H
#define CONTROLE_H

#include <QObject>
#include <QVariant>


#include "databasesenior.h"

class Controle : public QObject
{
    Q_OBJECT
public:
    explicit Controle(QObject *parent = nullptr);

signals:
    void statusConexao(bool);
    void retornoColaboradores(QSqlTableModel*);
    void retornoColaboradores(QMap<int, ObjColaborador *>);
    void mensagemRetorno(int, QString, QString);

public slots:
    void abrirConexao();
    void pesquisaColaboradoresMod(QString);
    void pesquisaColaboradoresMap(QString);
    void mensagemRetornoControle(int, QString, QString);

private:
    DatabaseSenior *db;
};

#endif // CONTROLE_H
