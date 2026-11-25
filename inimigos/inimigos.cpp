// incompleto
#include "inimigos.h"

protogen p = protogen::escolherClasse();

// objetos

inimigo::inimigo(short dano_ini, short vida_ini, short defesa_ini, string nome_ini, string descricao_ini, 
    short raridade_ini, short exp_drop_ini) : nivel_ini(nivel_ini =  p.protogenGetterNivel() * dado(4)), 
    dano_ini(dano_ini * (1.4 * nivel_ini)), vida_ini(vida_ini * (1.3 * nivel_ini)), 
    defesa_ini(defesa_ini * (1.2 * nivel_ini)),  nome_ini(nome_ini), descricao_ini(descricao_ini), 
    raridade_ini(raridade_ini), exp_drop_ini(exp_drop_ini * (1.5 * nivel_ini)) {
        if (p.protogenGetterNivel() + 3 < nivel_ini) {
            nivel_ini = p.protogenGetterNivel() + 3;
        }
    }

inimigo_overtime::inimigo_overtime(short dano_ini, short vida_ini, short defesa_ini, string nome_ini, string descricao_ini, 
        short raridade_ini, short exp_drop_ini, short chance_dano_overtime_ini, short dano_overtime_ini)
    : inimigo(dano_ini, vida_ini, defesa_ini, nome_ini, descricao_ini, raridade_ini, exp_drop_ini), 
    chance_dano_overtime_ini(chance_dano_overtime_ini), dano_overtime_ini(dano_overtime_ini) {
    if (chance_dano_overtime_ini > 100) {
        chance_dano_overtime_ini = 100;
    }
}

inimigo rx_580(4, 9, 3, "rx 580", "uma rx 580 minerada ate o talo", 13, 25);
inimigo mendigo(5, 12, 2, "mendigo", "espero q ele n tenha usado nada", 10, 30);
inimigo normie(7, 15, 2, "normie", "uma pessoa normal", 8, 35);
inimigo_overtime furry(9, 19, 3, "furry", "OWO", 6, 45, 30, 3);
inimigo_overtime cortador_de_garama(12, 21, 5, "cortador de grama", "ele ameaçou cortar a sua grama", 4, 60, 40, 5);
inimigo_overtime rato(14, 24, 5, "rato", "um rato, ele esta muito arrumado para ser de rua", 2, 69, 45, 6);

inimigo_boss::inimigo_boss(short dano_ini, short vida_ini, short defesa_ini, string nome_ini, string descricao_ini, 
        short raridade_ini, short exp_drop_ini, short chance_dano_overtime_ini, short dano_overtime_ini, 
        ataque_secundario_ini ataque_sec_ini, short chance_de_estun_ini, short chance_de_desviar_ini, 
        short chance_de_defender_ini, short escudo_ini) : 
        inimigo_overtime(dano_ini, vida_ini, defesa_ini, nome_ini, descricao_ini, raridade_ini, exp_drop_ini, 
        chance_dano_overtime_ini, dano_overtime_ini) {
        
        this->ataque_sec_ini.chance_ataque_secundario_ini = ataque_sec_ini.chance_ataque_secundario_ini * (1.3 * nivel_ini);
        this->ataque_sec_ini.dano_ataque_secundario_ini = ataque_sec_ini.dano_ataque_secundario_ini * (1.4 * nivel_ini);
        this->ataque_sec_ini.ataque_secundario_chance_overtime_ini = ataque_sec_ini.ataque_secundario_chance_overtime_ini * (1.3 * nivel_ini);
        this->ataque_sec_ini.ataque_secundario_dano_overtime_ini = ataque_sec_ini.ataque_secundario_dano_overtime_ini * (1,4 * nivel_ini);
        this->chance_de_stun_ini = chance_de_estun_ini * (1.05 * nivel_ini);
        this->chance_de_desviar_ini = chance_de_desviar_ini * (1.05 * nivel_ini);
        this->chance_de_defender_ini = chance_de_defender_ini * (1.15 * nivel_ini);
        this->escudo_ini = escudo_ini * (1.1 * nivel_ini);

        if (ataque_sec_ini.ataque_secundario_chance_overtime_ini > 100) {
            ataque_sec_ini.ataque_secundario_chance_overtime_ini = 100;
        }
}

inimigo_boss trator(21, 50, 5, "trator", "acho bom vc n ficar perto dele", 1, 120, 0, 0, {35, 18, 65, 11}, 25, 5, 25, 11);
inimigo_boss jare(29, 40, 4, "jare", "a mordida dele doi um pouco, recomendo toma cuidado onde vc bota sua calda", 1, 135, 55, 4, {45, 23, 80, 6}, 15, 5, 35, 12);
inimigo_boss idk(20, 70, 5, "idk ;w;", "minha criatividade acabo aqui ;w;", 1, 145, 65, 7, {55, 18, 85, 7}, 20, 25, 35, 9);


// funções

// getters
short inimigo::inimigoGetterDano() {
    return dano_ini;
}

short inimigo::inimigoGetterVida() {
    return vida_ini;
}

short inimigo::inimigoGetterDefesa() {
    return defesa_ini;
}

short inimigo::inimigoGetterNivel() {
    return nivel_ini;
}

string inimigo::inimigoGetterNome() {
    return nome_ini;
}

string inimigo::inimigoGetterDescricao() {
    return descricao_ini;
}

short inimigo::inimigoGetterRaridade() {
    return raridade_ini;
}

short inimigo::inimigoGetterExpDrop() {
    return exp_drop_ini;
}

short inimigo_overtime::inimigoOvertimeGetterChanceOvertime() {
    return chance_dano_overtime_ini;
}

short inimigo_overtime::inimigoOvertimeGetterDanoOvertime() {
    return dano_overtime_ini;
}

short inimigo_boss::inimigoBossGetterChanceAtaqueSecundario () {
    return ataque_sec_ini.dano_ataque_secundario_ini;
}

short inimigo_boss::inimigoBossGetterDanoAtaqueSecundario () {
    return ataque_sec_ini.dano_ataque_secundario_ini;
}

short inimigo_boss::inimigoBossGetterChanceAtaqueSecundarioDanoOvertime () {
    return ataque_sec_ini.ataque_secundario_chance_overtime_ini;
}

short inimigo_boss::inimigoBossGetterChanceAtaqueSecundarioDanoOvertime () {
    return ataque_sec_ini.ataque_secundario_dano_overtime_ini;
}

short inimigo_boss::inimigoBossGetterChanceStun () {
    return chance_de_stun_ini;
}

short inimigo_boss::inimigoBossGetterChanceDesviar() {
    return chance_de_desviar_ini;
}

short inimigo_boss::inimigoBossGetterChanceDefender() {
    return chance_de_defender_ini;
}

short inimigo_boss::inimigoBossGetterEscudo() {
    return escudo_ini;
}

// setters
void inimigo::inimigoSetterDano(short valor) {
    dano_ini = valor;
}

void inimigo::inimigoSetterVida(short valor) {
    vida_ini = valor;
}

void inimigo::inimigoSetterDano(short valor) {
    dano_ini = valor;
}

void inimigo::inimigoSetterDefesa(short valor) {
    defesa_ini = valor;
}

void inimigo_overtime::inimigoOvertimeSetterChanceOvertime(short valor) {
    chance_dano_overtime_ini = valor;
}

void inimigo_overtime::inimigoOvertimeSetterDanoOvertime(short valor) {
    dano_overtime_ini = valor;
}

void inimigo_boss::inimigoBossSetterEscudo(short valor) {
    escudo_ini = valor;
}