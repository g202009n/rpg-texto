// incompleto
#include "inimigos.h"

protogen p = protogen::escolherClasse();

inimigo::inimigo(short dano_ini, short vida_ini, short defesa_ini, string nome_ini, string descricao_ini, 
    short raridade_ini, short exp_drop) : nivel_ini(nivel_ini =  p.protogenGetterNivel() * dado(4)), 
    dano_ini(dano_ini * (1.4 * nivel_ini)), vida_ini(vida_ini * (1.3 * nivel_ini)), 
    defesa_ini(defesa_ini * (1.2 * nivel_ini)),  nome_ini(nome_ini), descricao_ini(descricao_ini), 
    raridade_ini(raridade_ini), exp_drop(exp_drop * (1.5 * nivel_ini)) {}

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
static inimigo_overtime cortador_de_garama(12, 21, 5, "cortador de grama", "ele ameaçou cortar a sua grama", 4, 60, 40, 5);
static inimigo_overtime rato(14, 24, 5, "rato", "um rato, ele esta muito arrumado para ser de rua", 2, 69, 45, 6);

inimigo_boss::inimigo_boss(short dano, short vida, short defesa, string nome, string descricao, short raridade, 
        short exp_drop, short chance_dano_overtime, short dano_overtime, ataque_secundario ataque_sec, 
        short chance_de_estun, short chance_de_desviar, short chance_de_defender, short escudo_ini) : 
        inimigo_overtime(dano, vida, defesa, nome, descricao, raridade, exp_drop, chance_dano_overtime, 
        dano_overtime) {
        
        this->ataque_sec.chance_ataque_secundario = ataque_sec.chance_ataque_secundario * (1.3 * nivel_ini);
        this->ataque_sec.dano_ataque_secundario = ataque_sec.dano_ataque_secundario * (1.4 * nivel_ini);
        this->ataque_sec.ataque_secundario_chance_overtime = ataque_sec.ataque_secundario_chance_overtime * (1.3 * nivel_ini);
        this->ataque_sec.ataque_secundario_dano_overtime = ataque_sec.ataque_secundario_dano_overtime * (1,4 * nivel_ini);
        this->chance_de_stun = chance_de_estun * (1.05 * nivel_ini);
        this->chance_de_desviar = chance_de_desviar * (1.05 * nivel_ini);
        this->chance_de_defender = chance_de_defender * (1.15 * nivel_ini);
        this->escudo_ini = escudo_ini * (1.1 * nivel_ini);

        if (ataque_sec.ataque_secundario_chance_overtime > 100) {
            ataque_sec.ataque_secundario_chance_overtime = 100;
        }
}