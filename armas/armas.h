#pragma once
#include "../util/util.h"

class arma {
    protected:
    short dano;
    string nome;
    string descricao;
    short raridade;

    public:
    arma(short dano, string nome, string descricao, short raridade);
};

class melees : public arma {
    private:
    short peso;
    short protecao;

    public:
    melees (short dano, string nome, string descricao, short raridade, short peso, short protecao);
};

class bullshit : public arma {
    private:
    short preco_bullshit;
    short chance_overtime;
    short dano_overtime;
    short chance_stun;

    public:
    bullshit(short dano, string nome, string descricao, short raridade, short preco_bullshit, short chance_overime, short dano_overtime, short chance_stun);
};

class rifleDePrecisao : public arma {
    private:
    short peso;
    short precisao;

    public:
    rifleDePrecisao(short dano, string nome, string descricao, short raridade, short peso, short precicao);
};

class lixo : public arma {
    private:
    short protecao;
    short poluicao;
    short intoxicacao;

    public:
    lixo(short dano, string nome, string descricao, short raridade, short protecao, short poluicao, short intoxicacao);
};