#pragma once
#include "../util/util.h"
#include "../proto/proto.h"

class inimigo {
    private:
    short dano;
    short vida;
    short defesa;
    short nivel;
    string nome;
    string descricao;
    short raridade;
    short exp_drop;

    short chance_dano_overtime;
    short dano_overtime;
    short chance_de_desvio;

    public:
    // getters
    void inimigoGetter();

    // setters
    template <typename T>
    void inimigoSetter(T &variavel, T valor);

    // ações
    void inimigoAtacar();
    void inimigoMorrer();

    inimigo(short dano, short vida, short defesa, string nome, string descricao, short raridade, short exp_drop);
};