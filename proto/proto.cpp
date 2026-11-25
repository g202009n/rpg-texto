// incompleto
#include "proto.h"

//getters
string protogen::protogenGetterNome() {
    return nome_proto;
}

short protogen::protogenGetterVidaInicial() {
    return vida_inicial_proto;
}

short protogen::protogenGetterVida() {
    return vida_proto;
}

short protogen::protogenGetterEscudo() {
    return escudo_proto;
}

short protogen::protogenGetterAgilidade() {
    return agilidade;
}

short protogen::protogenGetterNivel() {
    return nivel_proto;
}

Classe protogen::protogenGetterClasse() {
    return classe;
}

short protogen::protogenGetterVariavelClasse() {
    return variavel_classe;
}

short protogen::protogenGetterTamanhoMochila() {
    return tamanho_mochila;
}

void protogen::protogenPrint() {
    cout << nome_proto;
    cout << "   vida: " << vida_proto;
    cout << "   escudo: " << escudo_proto;
    cout << "   agilidade: " << agilidade;
    cout << "   nivel: " << nivel_proto;
    cout << "   classe: " << classe;
    switch(classe){
        case silly:
            cout << "   estupides: " << variavel_classe;
            break;
        case random_bullshit:
            cout << "   criatividade: " << variavel_classe;
            break;
        case sniper:
            cout << "   precisão: " << variavel_classe;
            break;
        case indeciso:
            cout << "   poluição: " << variavel_classe;
            break;
        default:
            cout << "erro na seleção de força da classe";
            break;
    }
}

void protogen::protogenMochilaPrint(string lista) {
    for (short i = 0; i < sizeof(lista)/sizeof(string); i++) {
        cout << i+1 << "- " << mochila[i];
    }
}


// setters
void protogen::protogenSetterVidaInicial(short valor) {
    vida_inicial_proto = valor;
}

void protogen::protogenSetterVida(short valor) {
    if (valor > vida_inicial_proto){
        valor = vida_inicial_proto;
    }

    vida_proto = valor;
}

void protogen::protogenSetterEscudo(short valor) {
    escudo_proto = valor;
}

void protogen::protogenSetterAgilidade(short valor) {
    agilidade = valor;
}

void protogen::protogenSetterNivel(short valor) {
    nivel_proto = valor;
}

void protogen::protogenSetterVariavelClasse(short valor) {
    variavel_classe = valor;
}

void protogen::protogenSetterArma(/*arma aqui*/) {
    
}

void protogenSetterArmadura(/*armadura aqui*/) {

}

// talvez precise arruma mais tarde
void protogen::protogenMochilaSetter(short posicao, string item) {
    mochila[posicao] = item;
}


// ações



// outros
protogen::protogen(string nome_proto, short vida_inicial_proto, short escudo_proto, short agilidade, Classe classe, 
    short variavel_classe) {
    this->nome_proto = nome_proto;
    this-> vida_inicial_proto = vida_inicial_proto;
    vida_proto = vida_inicial_proto;
    this->escudo_proto = escudo_proto;
    this->agilidade = agilidade;
    this->classe = classe;
    this->variavel_classe = variavel_classe;
}

protogen protogen::escolherClasse() {
    short escolha_classe;
    char escolha_nome;
    bool certeza_nome = true;

    string nome_protogen;
    short inicial;
    short escudo;
    short agilidade;
    Classe c;
    short var_classe;

    cout << "qual classe deseja escolher?\n1- silly\n2- random bullshit\n3- sniper\n4- indeciso\nR: ";
    do {
        cin >> escolha_classe;
        if (escolha_classe < 1 || escolha_classe > 4) {
            cout << "numeros apenas entre 1 e 4";
        }
        cout << "\nR: ";
    } while(escolha_classe < 1 || escolha_classe > 4);

    cout << "qual o nome do seu protogen?\n";
    do {
        cin >> nome_protogen;
        cout << "o nome do seu protogen é " << escolha_nome << " isso esta certo? (s/n)";
        cin >> escolha_nome;
        if (escolha_nome=='n') {
            certeza_nome = false;
        }
    } while (!certeza_nome);

    switch(escolha_classe){
        case 1:
            inicial = 115;
            escudo = 25;
            agilidade = 15;
            c = silly;
            var_classe = 5;
            cout << "a classe do seu protogem é silly" << std::endl;
            break;
        case 2:
            inicial = 85;
            escudo = 15;
            agilidade = 20;
            c = random_bullshit;
            var_classe = 15;
            cout << "a classe do seu protogem é random bullshit" << std::endl;
            break;
        case 3:
            inicial = 80;
            escudo = 20;
            agilidade = 25;
            c = sniper;
            var_classe = 10;
            cout << "a classe do seu protogem é sniper" << std::endl;
            break;
        case 4:
            inicial = 95;
            escudo = 30;
            agilidade = 10;
            c = indeciso;
            var_classe = 25;
            cout << "a classe do seu personagem é indeciso" << std::endl;
            break;
        default:
            cout << std::endl << "ocorreu um erro na seleção de classe";
            exit(1);
    }

    protogen protogenC(nome_protogen, inicial, escudo, agilidade, c, var_classe);

    cout << std::endl;

    return protogenC;
}