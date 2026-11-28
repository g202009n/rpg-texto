#include "./inimigos_cones.h"
#include "../inimigos.h"

static inimigo rx_580(4, 9, 3, "rx 580", "uma rx 580 minerada ate o talo", 13, 25);
static inimigo mendigo(5, 12, 2, "mendigo", "espero q ele n tenha usado nada", 9, 30);
static inimigo normie(7, 15, 2, "normie", "uma pessoa normal", 6, 35);
static inimigo_overtime furry(9, 19, 3, "furry", "OWO", 6, 45, 30, 3);
static inimigo_overtime cortador_de_garama(12, 21, 5, "cortador de grama", "ele ameaçou cortar a sua grama", 4, 60, 40, 5);
static inimigo_overtime rato(14, 24, 5, "rato", "um rato, ele esta muito arrumado para ser de rua", 2, 69, 45, 6);

inimigo *clonarRx580() {
    return rx_580.clone();
}