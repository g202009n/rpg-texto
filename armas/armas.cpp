#include "armas.h"

arma::arma(short dano, string nome, string descricao, short raridade) 
    : dano(dano), nome(nome), descricao(descricao), raridade(raridade){}

// melees
melees::melees(short dano, string nome, string descricao,  short raridade, short peso, short protecao) 
    : arma(dano, nome, descricao, raridade) {
    this->peso = peso;
    this->protecao = protecao;
}

// soma das raridades: 21
melees soco(2, "soco", "um soco, oq vc esperava?", 0, 0, 1);
melees graveto(3, "graveto", "um graveto que vc encontrou no chão",8, 1, 3);
melees cabo(5, "cabo", "um cabo de PC, isso doi...", 5, 2, 1);
melees espada_de_brinquedo(6, "espada de brinquedo", "uma espada feita de plastico, porem ainda é meio dura",4, 3, 4);
melees cano_de_metal(7, "cano de metal", "não derrube ao menos que vc queria q seus ouvidos explodam'", 3, 5, 7);
melees gato(10, "gato", "um gato, ele prativamente ataca por vc",1, 9, 3);

// bullshit
bullshit::bullshit(short dano, string nome, string descricao, short raridade, short preco_bullshit, short chance_overtime, short dano_overtime, short chance_stun) 
    : arma(dano, nome, descricao, raridade) {
        this->preco_bullshit = preco_bullshit;
        this->chance_overtime = chance_overtime;
        this->dano_overtime = dano_overtime;
        this->chance_stun = chance_stun;
}

bullshit tampa_de_garrafa(2, "tampa de garrafa", "uma tampa de garrafa um pouco afiada", 0, 1, 0, 0, 0);
bullshit gato(3, "gato", "tem chance de arranhar e causar sangramento no inimigo", 8, 2, 3, 0, 0);
bullshit amendoim(1, "amendoim", "tem chance de causa alergia no inimigo", 5, 3, 40, 7, 20);
bullshit caco_de_vidro(3, "caco de vidro", "alta chance de causar sangramento no inimigo", 4, 4, 70, 3, 0);
bullshit areia(1, "areia", "tem chance de cegar o inimigo, fazendo ele ficar stunado", 3, 5, 20, 1, 55);
bullshit raquete_eletrica(7, "raquete eletrica", "da um grande dano e tem chance de deixar o inimigo stunado", 1, 7, 70, 3, 80);

//rifles de precisão
rifleDePrecisao::rifleDePrecisao(short dano, string nome, string descricao, short raridade, short peso, short precisao)
    : arma(dano, nome, descricao, raridade) {
        this->peso = peso;
        this->precisao = precisao;
}

rifleDePrecisao elastico(4, "elastico", "um elastico velho que vc achou na rua", 0, 5, 2);
rifleDePrecisao besta_palito_de_dente(6, "besta de palito de dente", "uma besta que atira palitos de dente, meio obvio", 8, 9, 4);
rifleDePrecisao catapulta_de_genga(8, "catapulta de jenga", "uma mini catapulta que joga peças de jenga",5, 6, 9);
rifleDePrecisao estilingue_de_brita(11, "estilingue de brita", "um estilingue que... taca brita",3, 13, 6);
rifleDePrecisao rpg_de_confete(15, "rpg de confete", "é um laçador de confetes, so que maior", 1, 15, 10);

// lixos
lixo::lixo(short dano, string nome, string descricao, short raridade, short protecao, short poluicao, short intoxicacao) 
    : arma(dano, nome, descricao, raridade)  {
        this->protecao = protecao;
        this->poluicao = poluicao;
        this->intoxicacao = intoxicacao;
}

lixo sacola_plastica(1, "sacola plastica", "uma sacola de supermercado comum",0, 1, 2, 2);
lixo pilha(2, "pilha", "uma pilha estourada",8, 4, 5, 6);
lixo placa_mae_velha(5, "placa mãe velha", "uma placa mãe velha pra cacete",5, 4, 8, 4);
lixo escapamento_de_carro(8, "escapamento de carro", "um escapamento de um peugeout",3, 9, 9, 5);
lixo hudson_hornet(11, "hudson hornet", "um carro",1, 13, 12, 7);