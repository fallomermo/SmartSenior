#ifndef OBJCOLABORADOR_H
#define OBJCOLABORADOR_H

#include <QObject>
#include <QString>

class ObjColaborador : public QObject
{
    Q_OBJECT
public:
    explicit ObjColaborador(QObject *parent = nullptr);

    QString getMatricula() const;
    void setMatricula(const QString &value);

    QString getCpf() const;
    void setCpf(const QString &value);

    QString getEmpresa() const;
    void setEmpresa(const QString &value);

    QString getFilial() const;
    void setFilial(const QString &value);

    QString getCnpj() const;
    void setCnpj(const QString &value);

    QString getNome() const;
    void setNome(const QString &value);

    QString getDataAdmissao() const;
    void setDataAdmissao(const QString &value);

    QString getDataNascimento() const;
    void setDataNascimento(const QString &value);

    QString getSexo() const;
    void setSexo(const QString &value);

    QString getSituacao() const;
    void setSituacao(const QString &value);

    QString getSetor() const;
    void setSetor(const QString &value);

    QString getCargo() const;
    void setCargo(const QString &value);

    QString getCep() const;
    void setCep(const QString &value);

    QString getEndereco() const;
    void setEndereco(const QString &value);

    QString getNumeroCelular() const;
    void setNumeroCelular(const QString &value);

    QString getNumeroComercial() const;
    void setNumeroComercial(const QString &value);

    QString getUF() const;
    void setUF(const QString &value);

    QString getCidade() const;
    void setCidade(const QString &value);

    QString getBairro() const;
    void setBairro(const QString &value);

    QString getEmailPessoal() const;
    void setEmailPessoal(const QString &value);

    QString getEmailComercial() const;
    void setEmailComercial(const QString &value);

private:
    QString matricula;
    QString cpf;
    QString empresa;
    QString filial;
    QString cnpj;
    QString nome;
    QString dataAdmissao;
    QString dataNascimento;
    QString sexo;
    QString situacao;
    QString setor;
    QString cargo;
    QString cep;
    QString endereco;
    QString numeroCelular;
    QString numeroComercial;
    QString UF;
    QString cidade;
    QString bairro;
    QString emailPessoal;
    QString emailComercial;
};

#endif // OBJCOLABORADOR_H
