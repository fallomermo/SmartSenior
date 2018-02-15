#include "workspace.h"
#include "ui_workspace.h"

WorkSpace::WorkSpace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkSpace)
{
    ui->setupUi(this);

    QStringList labels = {"Empresa","CNPJ","Filial","CPF","Matricula","Nome","Nascimento","Admissão","Situação","Setor","Cargo","Endereço","Nº Celular","Nº Comercial","E-mail Pessoal","E-mail Comercial", "Cidade/UF","Bairro"};
    ui->tabelaResultados->setColumnCount(labels.count());
    ui->tabelaResultados->setHorizontalHeaderLabels(labels);

    QThread *processo = new QThread(nullptr);
    controlador = new Controle(nullptr);
    connect(this, SIGNAL(abrirConexaoBanco()),
            controlador, SLOT(abrirConexao()));
    connect(this, SIGNAL(pesquisarModelColaboradores(QString)),
            controlador, SLOT(pesquisaColaboradoresMap(QString)));
    connect(controlador, SIGNAL(retornoColaboradores(QMap<int,ObjColaborador*>)),
            this, SLOT(atualizarTabela(QMap<int,ObjColaborador*>)));
    connect(controlador, SIGNAL(statusConexao(bool)),
            this, SLOT(atualizarStatusConexao(bool)));
    connect(ui->campoPesquisa, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(pesquisar(QString)));
    connect(processo, SIGNAL(finished()),
            controlador, SLOT(deleteLater()));
    connect(ui->tabelaResultados, SIGNAL(clicked(QModelIndex)),
            this, SLOT(itemSelecionado(QModelIndex)));
    controlador->moveToThread(processo);
    processo->start(QThread::NormalPriority);

    emit abrirConexaoBanco();
}

WorkSpace::~WorkSpace()
{
    delete ui;
}

void WorkSpace::pesquisar()
{
    qDebug() << "executando métido 'WorkSpace::pesquisar()' ";
    if(ui->campoPesquisa->currentText().length() < 4) {
        QMessageBox::information(this, tr("Informação!"), QString("Número insuficiente de caracteres para pesquisa!"
                                                                  "\nO mínimo é 4."), "   OK   ");
        return;
    }
    ui->tabelaResultados->clearSelection();
    DialogProgresso *mensagemTela = new DialogProgresso(this);
    mensagemTela->setWindowModality(Qt::ApplicationModal);
    connect(this, SIGNAL(fecharMensagemTela()), mensagemTela, SLOT(fechar()));
    mensagemTela->show();


    QString where = " AND ";
    QStringList filtro = QStringList() << "  ( numemp like '%"+ui->campoPesquisa->currentText().trimmed()+"%' "
                                       << " or numcpf like '%"+ui->campoPesquisa->currentText().trimmed()+"%' "
                                       << " or numcad like '%"+ui->campoPesquisa->currentText().trimmed()+"%' "
                                       << " or razsoc like '%"+ui->campoPesquisa->currentText().trimmed()+"%' "
                                       << " or nomfil like '%"+ui->campoPesquisa->currentText().trimmed()+"%' "
                                       << " or codfil like '%"+ui->campoPesquisa->currentText().trimmed()+"%' "
                                       << " or nomfun like '%"+ui->campoPesquisa->currentText().trimmed()+"%' "
                                       << " or titcar like '%"+ui->campoPesquisa->currentText().trimmed()+"%' "
                                       << " or nomloc like '%"+ui->campoPesquisa->currentText().trimmed()+"%')";
    foreach (QString str, filtro) {
        where.append(str);
    }
    emit pesquisarModelColaboradores(where);
}

void WorkSpace::pesquisar(QString info)
{
    qDebug() << "executando métido 'WorkSpace::pesquisar()' ";
    if(ui->campoPesquisa->currentText().length() < 4) {
        QMessageBox::information(this, tr("Informação!"), QString("Número insuficiente de caracteres para pesquisa!"
                                                                  "\nO mínimo é 4."), "   OK   ");
        return;
    }
    DialogProgresso *mensagemTela = new DialogProgresso(this);
    connect(this, SIGNAL(fecharMensagemTela()), mensagemTela, SLOT(fechar()));
    mensagemTela->setWindowModality(Qt::ApplicationModal);
    mensagemTela->show();

    QString where = " AND ";
    QStringList filtro = QStringList() << "  ( numemp like '%"+info+"%' "
                                       << " or numcpf like '%"+info+"%' "
                                       << " or numcad like '%"+info+"%' "
                                       << " or razsoc like '%"+info+"%' "
                                       << " or nomfil like '%"+info+"%' "
                                       << " or codfil like '%"+info+"%' "
                                       << " or nomfun like '%"+info+"%' "
                                       << " or titcar like '%"+info+"%' "
                                       << " or nomloc like '%"+info+"%')";
    foreach (QString str, filtro) {
        where.append(str);
    }
    emit pesquisarModelColaboradores(where);
}

void WorkSpace::atualizarStatusConexao(bool status)
{
    qDebug() << "status conexão : " << status;
    if(status) {
        ui->painelDashPlayer->setPixmap(QPixmap(":/rc/interface/database_connected_64.png"));
        ui->painelDashPlayer->setToolTip("Conectado!");
        this->habilitarPesquisa();
    } else {
        ui->painelDashPlayer->setPixmap(QPixmap(":/rc/interface/database_disconnected_64.png"));
        ui->painelDashPlayer->setToolTip("Base de Dados Desconectado!");
    }
}

void WorkSpace::habilitarPesquisa()
{
    ui->campoPesquisa->setEnabled(true);
    ui->campoPesquisa->setFocus();
}

void WorkSpace::atualizarTabela(QMap<int, ObjColaborador *> m)
{
    QMapIterator<int, ObjColaborador*> i(m);
    int linha = 0;
    ui->tabelaResultados->setRowCount(m.count());
    m.clear();
    while (i.hasNext()) {
        i.next();
        ObjColaborador *o = i.value();
        for (int coluna = 0; coluna < ui->tabelaResultados->columnCount(); ++coluna) {
            switch (coluna) {
            case 0: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getEmpresa())); break;
            case 1: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getCnpj())); break;
            case 2: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getFilial())); break;
            case 3: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getCpf())); break;
            case 4: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getMatricula())); break;
            case 5: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getNome())); break;
            case 6: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getDataNascimento())); break;
            case 7: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getDataAdmissao())); break;
            case 8: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getSituacao())); break;
            case 9: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getSetor())); break;
            case 10: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getCargo())); break;
            case 11: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getEndereco())); break;
            case 12: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getNumeroCelular())); break;
            case 13: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getNumeroComercial())); break;
            case 14: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getEmailPessoal())); break;
            case 15: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getEmailComercial())); break;
            case 16: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getCidade()+"/"+o->getUF())); break;
            case 17: ui->tabelaResultados->setItem(linha, coluna, new QTableWidgetItem(o->getBairro())); break;
            }
        }
        linha++;
    }
    ui->tabelaResultados->resizeColumnsToContents();
    if(ui->tabelaResultados->rowCount() > 0) {
        ui->tabelaResultados->setCurrentCell(0, 0);
        this->itemSelecionado(ui->tabelaResultados->currentIndex());
    }
    emit fecharMensagemTela();
}

void WorkSpace::itemSelecionado(QModelIndex i)
{
    for (int coluna = 0; coluna < ui->tabelaResultados->columnCount(); ++coluna) {
        switch (coluna) {
        case 0: ui->campoEmpresa->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 1: ui->campoCNPJ->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 2: ui->campoFilial->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 3: ui->campoCPF->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 4: ui->campoMatricula->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 5: ui->campoNome->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 6: ui->campoDataNascimento->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 7: ui->campoDataAdmissao->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 8: ui->campoSituacao->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 9: ui->campoSetor->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 10: ui->campoCargo->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 11: ui->campoLogradouro->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 12: ui->campoNumeroCelular->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 13: ui->campoNumeroComercial->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 14: ui->campoEmailPessoal->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 15: ui->campoEmailComercial->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 16: ui->campoCidadeUF->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        case 17: ui->campoBairro->setText(ui->tabelaResultados->item(i.row(), coluna)->text()); break;
        }
    }
}
