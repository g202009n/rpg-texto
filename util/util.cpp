#include "util.h"

short dado(short possibilidades){
    std::random_device rd;
    std::mt19937 gerador(rd());
    std::uniform_int_distribution<short> distrubuicao(1, possibilidades);
    return distrubuicao(gerador);
}