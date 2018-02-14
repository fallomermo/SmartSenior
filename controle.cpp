#include "controle.h"

Controle::Controle(QObject *parent) : QObject(parent) {}

void Controle::abrirConexao()
{
    db = new DatabaseSenior;
    emit statusConexao(db->conectar());
}

void Controle::pesquisaColaboradoresMod(QString filtro)
{
    qDebug() << "instanciando objeto 'DatabaseSenior' na classe 'Controle' ";
    db = new DatabaseSenior;
    connect(db, SIGNAL(mensagemRetorno(int,QString,QString)), this, SLOT(mensagemRetornoControle(int,QString,QString)));
    emit retornoColaboradores(db->pesquisarColaboradorMod(filtro));
}

void Controle::pesquisaColaboradoresMap(QString filtro)
{
    qDebug() << "instanciando objeto 'DatabaseSenior' na classe 'Controle' ";
    db = new DatabaseSenior;
    connect(db, SIGNAL(mensagemRetorno(int,QString,QString)), this, SLOT(mensagemRetornoControle(int,QString,QString)));
    qRegisterMetaType<QMap<int, ObjColaborador*>>("__tempMap");
    emit retornoColaboradores(db->pesquisarColaboradorMap(filtro));
}

void Controle::mensagemRetornoControle(int tipo, QString titulo, QString mensagem)
{
    emit mensagemRetorno(tipo, titulo, mensagem);
}
