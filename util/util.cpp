#include "util.h"
#include "../inimigos/inimigos.h"
#include "../proto/proto.h"

protogen p = protogen::escolherClasse();

short dado(short possibilidades){
    std::random_device rd;
    std::mt19937 gerador(rd());
    std::uniform_int_distribution<short> distrubuicao(1, possibilidades);
    return distrubuicao(gerador);
}

void atualizarDadosInimigos(inimigo& ini, protogen p) {
    ini.inimigoBo
}