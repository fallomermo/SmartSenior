#include "objcolaborador.h"

ObjColaborador::ObjColaborador(QObject *parent) : QObject(parent)
{

}

QString ObjColaborador::getMatricula() const
{
    return matricula;
}

void ObjColaborador::setMatricula(const QString &value)
{
    matricula = value;
}

QString ObjColaborador::getCpf() const
{
    return cpf;
}

void ObjColaborador::setCpf(const QString &value)
{
    cpf = value;
}

QString ObjColaborador::getEmpresa() const
{
    return empresa;
}

void ObjColaborador::setEmpresa(const QString &value)
{
    empresa = value;
}

QString ObjColaborador::getFilial() const
{
    return filial;
}

void ObjColaborador::setFilial(const QString &value)
{
    filial = value;
}

QString ObjColaborador::getCnpj() const
{
    return cnpj;
}

void ObjColaborador::setCnpj(const QString &value)
{
    cnpj = value;
}

QString ObjColaborador::getNome() const
{
    return nome;
}

void ObjColaborador::setNome(const QString &value)
{
    nome = value;
}

QString ObjColaborador::getDataAdmissao() const
{
    return dataAdmissao;
}

void ObjColaborador::setDataAdmissao(const QString &value)
{
    dataAdmissao = value;
}

QString ObjColaborador::getDataNascimento() const
{
    return dataNascimento;
}

void ObjColaborador::setDataNascimento(const QString &value)
{
    dataNascimento = value;
}

QString ObjColaborador::getSexo() const
{
    return sexo;
}

void ObjColaborador::setSexo(const QString &value)
{
    sexo = value;
}

QString ObjColaborador::getSituacao() const
{
    return situacao;
}

void ObjColaborador::setSituacao(const QString &value)
{
    situacao = value;
}

QString ObjColaborador::getSetor() const
{
    return setor;
}

void ObjColaborador::setSetor(const QString &value)
{
    setor = value;
}

QString ObjColaborador::getCargo() const
{
    return cargo;
}

void ObjColaborador::setCargo(const QString &value)
{
    cargo = value;
}

QString ObjColaborador::getCep() const
{
    return cep;
}

void ObjColaborador::setCep(const QString &value)
{
    cep = value;
}

QString ObjColaborador::getEndereco() const
{
    return endereco;
}

void ObjColaborador::setEndereco(const QString &value)
{
    endereco = value;
}

QString ObjColaborador::getNumeroCelular() const
{
    return numeroCelular;
}

void ObjColaborador::setNumeroCelular(const QString &value)
{
    numeroCelular = value;
}

QString ObjColaborador::getNumeroComercial() const
{
    return numeroComercial;
}

void ObjColaborador::setNumeroComercial(const QString &value)
{
    numeroComercial = value;
}

QString ObjColaborador::getUF() const
{
    return UF;
}

void ObjColaborador::setUF(const QString &value)
{
    UF = value;
}

QString ObjColaborador::getCidade() const
{
    return cidade;
}

void ObjColaborador::setCidade(const QString &value)
{
    cidade = value;
}

QString ObjColaborador::getBairro() const
{
    return bairro;
}

void ObjColaborador::setBairro(const QString &value)
{
    bairro = value;
}

QString ObjColaborador::getEmailPessoal() const
{
    return emailPessoal;
}

void ObjColaborador::setEmailPessoal(const QString &value)
{
    emailPessoal = value;
}

QString ObjColaborador::getEmailComercial() const
{
    return emailComercial;
}

void ObjColaborador::setEmailComercial(const QString &value)
{
    emailComercial = value;
}
