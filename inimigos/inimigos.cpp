// incompleto
#include "inimigos.h"

protogen p = protogen::escolherClasse();

inimigo::inimigo(short dano, short vida, short defesa, string nome, string descricao, short raridade, 
    short exp_drop) : nivel(nivel = p.protogenGetterNivel() * 1.5 * dado(4)), dano(dano * (1.4 * nivel)), 
    vida(vida * (1.3 * nivel)), defesa(defesa * (1.2 * nivel)),  nome(nome), descricao(descricao), 
    raridade(raridade), exp_drop(exp_drop * (1.5 * nivel)) {}

inimigo_overtime::inimigo_overtime(short dano, short vida, short defesa, string nome, string descricao, 
    short raridade, short exp_drop, short chance_dano_overtime, short dano_overtime)
    : inimigo(dano, vida, defesa, nome, descricao, raridade, exp_drop), 
    chance_dano_overtime(chance_dano_overtime ),dano_overtime(dano_overtime) {
    if (chance_dano_overtime > 100) {
        chance_dano_overtime = 100;
    }
}

static inimigo rx_580(4, 9, 3, "rx 580", "uma rx 580 minerada ate o talo", 13, 25);
static inimigo mendigo(5, 12, 2, "mendigo", "espero q ele n tenha usado nada", 10, 30);
static inimigo normie(7, 15, 2, "normie", "uma pessoa normal", 8, 35);
static inimigo_overtime furry(9, 19, 3, "furry", "OWO", 6, 45, 30, 3);
static inimigo_overtime cortador_de_garama(12, 21, 5, "cortador de grama", "ele ameaçou cortar a sua grama", 
    4, 60, 40, 5);
static inimigo_overtime rato(14, 24, 5, "rato", "um rato, ele esta muito arrumado para ser de rua", 2, 69, 45, 6);

inimigo_boss::inimigo_boss(short dano, short vida, short defesa, string nome, string descricao, short raridade, 
        short exp_drop, short chance_dano_overtime, short dano_overtime, ataque_secundario ataque_sec, 
        short chance_de_estun, short chance_de_desviar, short chance_de_defender, short escudo) 
        : inimigo_overtime(dano, vida, defesa, nome, descricao, raridade, exp_drop, chance_dano_overtime, 
        dano_overtime) {
        
        this->ataque_sec.chance_ataque_secundario = ataque_sec.chance_ataque_secundario * (1.3 * nivel);
        this->ataque_sec.dano_ataque_secundario = ataque_sec.dano_ataque_secundario * (1.4 * nivel);
        this->ataque_sec.ataque_secundario_chance_overtime = ataque_sec.ataque_secundario_chance_overtime * (1.3 * nivel);
        this->ataque_sec.ataque_secundario_dano_overtime = ataque_sec.ataque_secundario_dano_overtime * (1,4 * nivel);
        this->chance_de_stun = chance_de_estun;
        this->chance_de_desviar = chance_de_desviar;
        this->chance_de_defender = chance_de_defender;
        this->escudo = escudo;
}