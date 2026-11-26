#include "util.h"
#include "../inimigos/inimigos.h"
#include "../proto/proto.h"

protogen p = protogen::escolherClasse();

short dado(short possibilidades){
    std::random_device rd;
    std::mt19937 gerador(rd());
    std::uniform_int_distribution<short> distrubuicao(0, possibilidades);
    return distrubuicao(gerador);
}

void atualizarDadosInimigos(inimigo& ini) {
    ini.inimigoSetterNivel(p.protogenGetterNivel() + dado(3));
    ini.inimigoSetterDano(ini.inimigoGetterDano() * floor(ini.inimigoGetterNivel() * 1.3));
    ini.inimigoSetterVida(ini.inimigoGetterVida() * floor(ini.inimigoGetterNivel() * 1.3));
    ini.inimigoSetterDefesa(ini.inimigoGetterDefesa() * floor(ini.inimigoGetterNivel() * 1.2));
    ini.inimigoSetterExpDrop(ini.inimigoGetterExpDrop() * floor(ini.inimigoGetterNivel() * 1.3));

    if (inimigo_overtime *ini_over = dynamic_cast<inimigo_overtime*>(&ini)) {
        ini.inimigoOvertimeSetterChanceOvertime(ini.inimigoOvertimeGetterChanceOvertime() * floor(ini.inimigoGetterNivel() * 1.2));
        if (ini.inimigoOvertimeGetterChanceOvertime() > 100) {
            ini.inimigoOvertimeSetterDanoOvertime(100);
        }
        ini.inimigoOvertimeSetterDanoOvertime(ini.inimigoOvertimeGetterDanoOvertime() * floor(ini.inimigoGetterNivel() * 1.2));
    }

    if (inimigo_boss *ini_boss = dynamic_cast<inimigo_boss*>(&ini)) {
        ini.inimigoBossSetterChanceAtaqueSecundario(ini.inimigoBossGetterChanceAtaqueSecundario() * floor(ini.inimigoGetterNivel() * 1.3));
        if (ini.inimigoBossGetterChanceAtaqueSecundario() > 100) {
            ini.inimigoBossSetterChanceAtaqueSecundario(100);
        }
        ini.inimigoBossSetterDanoAtaqueSecundario(ini.inimigoBossGetterDanoAtaqueSecundario() * floor(ini.inimigoGetterNivel() * 1.3));
        ini.inimigoBossSetterChanceAtaqueSecundarioOvertime(ini.inimigoBossGetterChanceAtaqueSecundario() * floor(ini.inimigoGetterNivel() * 1.2));
        if (ini.inimigoBossGetterAtaqueSecundarioChanceOvertime() > 100) {
            ini.inimigoBossSetterChanceAtaqueSecundarioOvertime(100);
        }
        ini.inimigoBossSetterDanoAtaqueSecundarioOvertime(ini.inimigoBossGetterAtaqueSecundarioDanoOvertime() * floor(ini.inimigoGetterNivel() * 1.2));
        ini.inimigoBossSetterChanceStun(ini.inimigoBossGetterChanceStun() * floor(ini.inimigoGetterNivel() * 1.05));
        ini.inimigoBossSetterChanceDesviar(ini.inimigoBossGetterChanceDesviar() * floor(ini.inimigoGetterNivel() * 1.05));
        ini.inimigoBossSetterChanceDefender(ini.inimigoBossGetterChanceDefender() * floor(ini.inimigoGetterNivel() * 1.15));
        ini.inimigoBossSetterEscudo(ini.inimigoBossGetterEscudo() * floor(ini.inimigoGetterNivel() * 1.1));
    }
}