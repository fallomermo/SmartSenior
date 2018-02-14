#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QMap>
#include <QAction>
#include <QWidget>
#include <QThread>
#include <QVariant>
#include <QModelIndex>
#include <QTableWidget>
#include <QMapIterator>
#include <QTableWidgetItem>

#include "controle.h"
#include "objcolaborador.h"
#include "dialogprogresso.h"

namespace Ui {
class WorkSpace;
}

class WorkSpace : public QWidget
{
    Q_OBJECT

public:
    explicit WorkSpace(QWidget *parent = 0);
    ~WorkSpace();

signals:
    void pesquisarModelColaboradores(QString);
    void fecharMensagemTela();
    void abrirConexaoBanco();

private slots:
    void pesquisar();
    void pesquisar(QString);
    void atualizarStatusConexao(bool);
    void habilitarPesquisa();
    void atualizarTabela(QMap<int, ObjColaborador *>);
    void itemSelecionado(QModelIndex);

private:
    Ui::WorkSpace *ui;
    Controle *controlador;

    QThread *threadMsg;
};

#endif // WORKSPACE_H
