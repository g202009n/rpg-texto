#include "util.h"
// o .cpp preicisa saber a função dentro da classe
#include "../proto/proto.h"
#include "../inimigos/inimigos.h"

short dado(short possibilidades){
    std::random_device rd;
    std::mt19937 gerador(rd());
    std::uniform_int_distribution<short> distrubuicao(0, possibilidades);
    return distrubuicao(gerador);
}

