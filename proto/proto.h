#pragma once
#include "../util/util.h"
#include "../armas/armas.h"
#include "../inimigos/inimigos.h"

enum Classe {silly = 0, random_bullshit = 1, sniper = 2, indeciso = 3};

class protogen {
    private:

    // variaveis
    string nome_proto;
    short vida_inicial_proto;
    short vida_proto;
    short escudo_proto;
    short agilidade;
    short nivel_proto;
    Classe classe;
    short variavel_classe;

    arma *arma_equipada = nullptr;
    string *armadura_equipada;
    std::vector<string> mochila;
    short tamanho_mochila = 5;
    string bullshit_bag[3];
    short exp = 0;

    short inimigos_abatidos = 0;
    inimigo *inimigo_atual = nullptr;

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
    inimigo getterInimigoAtual();

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
    void setterInimigoAtual(/*colocar inimigo aqui*/);

    void protogenMochilaSetter(short posicao, string item);

    // ações
    short bater(short agilidade, short nivel, char classe, short variavel_classe /*colocar arma aqui*/);
    short defender(short escudo, short nivel, char classe, short variavel_classe /*colocar arma aqui*/);
    void inspecionarPersonagem();
    void inspecionarInimigo(inimigo& ini);
    void usarItem();
    void pegarArma(/*colocar arma*/);
    void pegarArmadura(/*colocar armadura*/);
    void pegarItem(short tamanho_mochila);
    void descartarItem();
    void inspecionarItem(/*colocar item*/);
    void protogenSubirDeNivel(inimigo& ini);
    void fugir();

    // outros
    static protogen escolherClasse();
    void randomizarInimigo(inimigo& ini);

    protogen(string nome, short vida_inicial, short escudo, short agilidade, Classe classe, short variavel_classe);
};