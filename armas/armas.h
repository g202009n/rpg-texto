#pragma once
#include "../util/util.h"
#include "../proto/proto.h"

class arma {
    protected:
    short dano;
    string nome;
    string descricao;
    short raridade;

    public:
    // clone
    virtual arma *clone() const = 0;
    virtual ~arma() = default;

    arma(short dano, string nome, string descricao, short raridade);
};

class melees : public arma {
    private:
    short peso;
    short protecao;

    public:
    // clone
    arma *clone() const override;

    melees (short dano, string nome, string descricao, short raridade, short peso, short protecao);
};

class bullshit : public arma {
    private:
    short preco_bullshit;
    short chance_overtime;
    short dano_overtime;
    short chance_stun;

    public:
    // clone
    arma *clone() const override;

    bullshit(short dano, string nome, string descricao, short raridade, short preco_bullshit, short chance_overime, short dano_overtime, short chance_stun);
};

class rifle_de_precisao : public arma {
    private:
    short peso;
    short precisao;

    public:
    // clone
    arma *clone() const override;

    rifle_de_precisao(short dano, string nome, string descricao, short raridade, short peso, short precicao);
};

class lixo : public arma {
    private:
    short protecao;
    short poluicao;
    short intoxicacao;

    public:
    // clone
    arma *clone() const override;

    lixo(short dano, string nome, string descricao, short raridade, short protecao, short poluicao, short intoxicacao);
};