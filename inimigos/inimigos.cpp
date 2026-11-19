#include "inimigos.h"

inimigo::inimigo(short dano, short vida, short defesa, string nome, string descricao, short raridade, short exp_drop) {
    protogen p = protogen::escolherClasse();
    
    nivel = p.protogenGetterNivel() * (0.6 * dado(4));
    this->dano = dano * (0.4 * nivel);
    this->vida = vida * (0.3 * nivel);
    this->defesa = defesa * (0.2 * nivel);
    this->nome = nome;
    this->descricao = descricao;
    this->raridade = raridade;
    this->exp_drop = exp_drop * (0.5 * nivel);
}

inimigo normie(7, 15, 2, "normie", "uma pessoa comum", 10, 40);