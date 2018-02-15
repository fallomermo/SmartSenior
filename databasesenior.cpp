#include "databasesenior.h"

DatabaseSenior::DatabaseSenior(QObject *parent) : QObject(parent) {}

bool DatabaseSenior::conectar()
{
    QString connectString;
    db = QSqlDatabase::addDatabase("QODBC");
    connectString.append("DRIVER={SQL Server};");
    connectString.append("Server=192.168.6.4,1433;");
    connectString.append("DATABASE=vetorh;");
    connectString.append("UID=sa;");
    connectString.append("PWD=rhsenior123;");
    connectString.append("WSID=;");
    db.setDatabaseName(connectString);
    bool ok = false;

    if(db.open()) ok = true; return ok;
}

QSqlTableModel* DatabaseSenior::pesquisarColaboradorMod(QString filtro)
{
    qDebug() << "executando metodo 'DatabaseSenior::pesquisarColaborador()' na classe 'DatabaseSenior' ";
    model = new QSqlTableModel(this, db);
    model->setTable("view_cadastro_colaborador");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setFilter(filtro);
    if(model->select()) {
        qDebug() << "query executada...";
        return model;
    } else {
        QString mensagem = QString("Impossível realizar a consulta! \n").arg(model->lastError().text());
        emit mensagemRetorno(1, "Erro SQL", mensagem);
    }
    return model;
}

QMap<int, ObjColaborador *> DatabaseSenior::pesquisarColaboradorMap(QString filtro)
{
    qDebug() << "executando metodo 'DatabaseSenior::pesquisarColaborador()' na classe 'DatabaseSenior' ";
    QMap<int, ObjColaborador *> m;
    QString comando = QString(" SELECT razsoc, "
                              "        numcgc, "
                              "        nomfil, "
                              "        numcpf, "
                              "        numcad, "
                              "        endcpl, "
                              "        nomfun, "
                              "        CONVERT(VARCHAR(10), datadm, 103)       datadm, "
                              "        CONVERT(VARCHAR(10), datnas, 103)       datnas, "
                              "        dessit, "
                              "        nomloc, "
                              "        titcar, "
                              "        Cast(dditel AS SYSNAME) + '' "
                              "        + Cast(dddtel AS SYSNAME) + '' + numtel numpes, "
                              "        Cast(nmddi2 AS SYSNAME) + '' "
                              "        + Cast(nmddd2 AS SYSNAME) + '' + nmtel2 numcom, "
                              "        emapar, "
                              "        emacom, "
                              "        codest, "
                              "        nomcid, "
                              "        nombai "
                              " FROM   view_cadastro_colaborador "
                              " WHERE  sitafa NOT IN ( 7, 8, 34 ) "
                              " %0 ").arg(filtro);
    qDebug() << "comando criado com sucesso!\n" << comando;
    QSqlQuery consulta;
    consulta.prepare(comando);
    qDebug() << "executando query";
    if(consulta.exec()) {
        int row = 0;
        qDebug() << "query executada com sucesso!";
        consulta.setForwardOnly(true);
        while (consulta.next()) {
            row++;
            ObjColaborador *o = new ObjColaborador;
            o->setEmpresa(consulta.value("razsoc").toString());
            o->setCnpj(consulta.value("numcgc").toString());
            o->setFilial(consulta.value("nomfil").toString());
            o->setCpf(consulta.value("numcpf").toString());
            o->setMatricula(consulta.value("numcad").toString());
            o->setEndereco(consulta.value("endcpl").toString());
            o->setNome(consulta.value("nomfun").toString());
            o->setDataAdmissao(consulta.value("datadm").toString());
            o->setDataNascimento(consulta.value("datnas").toString());
            o->setSituacao(consulta.value("dessit").toString());
            o->setSetor(consulta.value("nomloc").toString());
            o->setCargo(consulta.value("titcar").toString());
            o->setNumeroCelular(consulta.value("numpes").toString());
            o->setNumeroComercial(consulta.value("numcom").toString());
            o->setCidade(consulta.value("nomcid").toString());
            o->setBairro(consulta.value("nombai").toString());
            o->setUF(consulta.value("codest").toString());
            o->setEmailPessoal(consulta.value("emapar").toString());
            o->setEmailComercial(consulta.value("emacom").toString());
            qDebug() << "registro " << o->getNome();
            m.insert(row, o);
        }
    } else {
        qDebug() << consulta.lastError().text();
        qDebug() << consulta.lastError().text();
        qDebug() << consulta.lastError().text();
        emit mensagemRetorno(1, "Erro SQL!", consulta.lastError().text());
    }
    return m;
}
