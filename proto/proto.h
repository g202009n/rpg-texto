#pragma once
#include "../util/util.h"
#include "../armas/armas.h"
#include "../inimigos/inimigos.h"

enum Classe {silly = 0, random_bullshit = 1, sniper = 2, indeciso = 3};

// classes:
// silly
// random bullshit
// sniper
// indeciso

class protogen {
    private:

    inimigo inimigo;
    inimigo_overtime inimigo_overtime;
    inimigo_boss inimigo_boss;

    // variaveis
    string nome_proto;
    short vida_inicial_proto;
    short vida_proto;
    short escudo_proto;
    short agilidade;
    short nivel_proto;
    Classe classe;
    short variavel_classe;

    string arma;
    string armadura;
    std::vector<std::string> mochila;
    short tamanho_mochila = 5;
    string bullshit_bag[3];
    short exp = 0;

    public:
    // getters
    string protogenGetterNome();
    short protogenGetterVidaInicial();
    short protogenGetterVida();
    short protogenGetterEscudo();
    short protogenGetterAgilidade();
    short protogenGetterNivel();
    Classe protogenGetterClasse();
    short protogenGetterVariavelClasse();
    short protogenGetterTamanhoMochila();
    string protogenGetterArma();
    string protogenGetterArmadura();

    void protogenPrint();
    void protogenMochilaPrint(string lista);

    // setters
    void protogenSetterVidaInicial(short valor);
    void protogenSetterVida(short valor);
    void protogenSetterEscudo(short valor);
    void protogenSetterAgilidade(short valor);
    void protogenSetterNivel(short valor);
    void protogenSetterVariavelClasse(short valor);
    void protogenSetterArma(/*colocar arma aqui*/);
    void protogenSetterArmadura(/*colocar armadura aqui*/);

    void protogenMochilaSetter(short posicao, string item);
    void protogenSubirDeNivel();

    // ações
    short bater(short agilidade, short nivel, char classe, short variavel_classe, string arma);
    short defender(short escudo, short nivel, char classe, short variavel_classe, string arma = "");
    void inspecionarPersonagem();
    void inspecionarInimigo();
    void usarItem();
    void pegarArma(string arma);
    void pegarArmadura(string armadura);
    void pegarItem(short tamanho_mochila);
    void descartarItem();
    void inspecionarItem(string item);
    void inspecionarInimigo();
    void fugir();

    // outros
    protogen(string nome, short vida_inicial, short escudo, short agilidade, Classe classe, short variavel_classe);

    static protogen escolherClasse();
};