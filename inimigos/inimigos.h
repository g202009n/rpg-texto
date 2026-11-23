// incompleto
#pragma once
#include "../util/util.h"
#include "../proto/proto.h"

class inimigo {
    protected:

    // variaveis
    short dano_ini;
    short vida_ini;
    short defesa_ini;
    short nivel_ini = 1;
    string nome_ini;
    string descricao_ini;
    short raridade_ini;
    short exp_drop;

    public:
    // getters
    short inimigoGetterDano();
    short inimigoGetterVida();
    short inimigoGetterDefesa();
    short inimigoGetterNivel();
    string inimigoGetterNome();
    string inimigoGetterDescricao();
    short inimigoGetterRaridade();

    // setters
    void setterVida(short valor);

    // ações
    void inimigoAtacar();
    void inimigoMorrer();

    void inimigoMiniBoss();

    inimigo(short dano, short vida, short defesa, string nome, string descricao, short raridade, short exp_drop);
};

class inimigo_overtime : public inimigo {
    protected:
    short chance_dano_overtime;
    short dano_overtime;

    public:
    inimigo_overtime(short dano, short vida, short defesa, string nome, string descricao, short raridade, 
        short exp_drop, short chance_dano_overtime, short dano_overtime);
};

class inimigo_boss : public inimigo_overtime {
    private:
    struct ataque_secundario{
        short chance_ataque_secundario;
        short dano_ataque_secundario;
        short ataque_secundario_chance_overtime;
        short ataque_secundario_dano_overtime;
    };

    ataque_secundario ataque_sec;
    short chance_de_stun;
    short chance_de_defender;
    short chance_de_desviar;
    short escudo_ini;
    public:
    inimigo_boss(short dano, short vida, short defesa, string nome, string descricao, 
        short raridade, short exp_drop, short chance_dano_overtime, short dano_overtime, 
        ataque_secundario ataque_sec, short chance_de_estun, short chance_de_desviar, short chance_de_defender, 
        short escudo);
};