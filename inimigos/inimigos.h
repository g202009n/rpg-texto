// incompleto
#pragma once
#include "../util/util.h"

class protogen;

class inimigo {
    protected:
    // variaveis
    short dano_ini;
    short vida_ini;
    short defesa_ini;
    short nivel_ini = 1;
    string nome_ini;
    string descricao_ini;
    short raridade_ini;
    short exp_drop_ini;
    
    public:
    // getters
    short inimigoGetterDano();
    short inimigoGetterVida();
    short inimigoGetterDefesa();
    short inimigoGetterNivel();
    string inimigoGetterNome();
    string inimigoGetterDescricao();
    short inimigoGetterRaridade();
    short inimigoGetterExpDrop();

    virtual short inimigoOvertimeGetterChanceOvertime();
    virtual short inimigoOvertimeGetterDanoOvertime();

    virtual short inimigoBossGetterChanceAtaqueSecundario();
    virtual short inimigoBossGetterDanoAtaqueSecundario();
    virtual short inimigoBossGetterAtaqueSecundarioChanceOvertime();
    virtual short inimigoBossGetterAtaqueSecundarioDanoOvertime();
    virtual short inimigoBossGetterChanceStun();
    virtual short inimigoBossGetterChanceDesviar();
    virtual short inimigoBossGetterChanceDefender();
    virtual short inimigoBossGetterEscudo();


    // setters
    void inimigoSetterDano(short valor);
    void inimigoSetterVida(short valor);
    void inimigoSetterDefesa(short valor);
    void inimigoSetterNivel(short valor);
    void inimigoSetterExpDrop(short valor);

    void atualizarDadosInimigos(inimigo& ini);
    
    virtual void inimigoOvertimeSetterChanceOvertime(short valor);
    virtual void inimigoOvertimeSetterDanoOvertime(short valor);

    virtual void inimigoBossSetterChanceAtaqueSecundario(short valor);
    virtual void inimigoBossSetterDanoAtaqueSecundario(short valor);
    virtual void inimigoBossSetterChanceAtaqueSecundarioOvertime(short valor);
    virtual void inimigoBossSetterDanoAtaqueSecundarioOvertime(short valor);
    virtual void inimigoBossSetterChanceStun(short valor);
    virtual void inimigoBossSetterChanceDesviar(short valor);
    virtual void inimigoBossSetterChanceDefender(short valor);
    virtual void inimigoBossSetterEscudo(short valor);


    // ações
    void inimigoAtacar(protogen& p);
    void inimigoMorrer(protogen& p);

    // clone
    virtual inimigo *clone() const;

    //outros
    void listaDeChances();

    inimigo(short dano_ini, short vida_ini, short defesa_ini, string nome_ini, string descricao_ini, 
        short raridade_ini, short exp_drop_ini);
};

class inimigo_overtime : public inimigo {
    protected:
    short chance_dano_overtime_ini;
    short dano_overtime_ini;

    public:
    // getters
    short inimigoOvertimeGetterChanceOvertime() override;
    short inimigoOvertimeGetterDanoOvertime() override;

    // setters
    void inimigoOvertimeSetterChanceOvertime(short valor) override;
    void inimigoOvertimeSetterDanoOvertime(short valor) override;

    // clone
    inimigo *clone() const override;

    inimigo_overtime(short dano_ini, short vida_ini, short defesa_ini, string nome_ini, string descricao_ini, 
        short raridade_ini, short exp_drop_ini, short chance_dano_overtime_ini, short dano_overtime_ini);
};

class inimigo_boss : public inimigo_overtime {
    private:
    struct ataque_secundario_ini{
        short chance_ataque_secundario_ini;
        short dano_ataque_secundario_ini;
        short ataque_secundario_chance_overtime_ini;
        short ataque_secundario_dano_overtime_ini;
    };

    ataque_secundario_ini ataque_sec_ini;
    short chance_de_stun_ini;
    short chance_de_desviar_ini;
    short chance_de_defender_ini;
    short escudo_ini;
    
    public:
    // getters
    short inimigoBossGetterChanceAtaqueSecundario() override;
    short inimigoBossGetterDanoAtaqueSecundario() override;
    short inimigoBossGetterAtaqueSecundarioChanceOvertime() override;
    short inimigoBossGetterAtaqueSecundarioDanoOvertime() override;
    short inimigoBossGetterChanceStun() override;
    short inimigoBossGetterChanceDesviar() override;
    short inimigoBossGetterChanceDefender() override;
    short inimigoBossGetterEscudo() override;

    // setters
    void inimigoBossSetterChanceAtaqueSecundario(short valor) override;
    void inimigoBossSetterDanoAtaqueSecundario(short valor) override;
    void inimigoBossSetterChanceAtaqueSecundarioOvertime(short valor) override;
    void inimigoBossSetterDanoAtaqueSecundarioOvertime(short valor) override;
    void inimigoBossSetterChanceStun(short valor) override;
    void inimigoBossSetterChanceDesviar(short valor) override;
    void inimigoBossSetterChanceDefender(short valor) override;
    void inimigoBossSetterEscudo(short valor) override;

    // ações
    void determinarAcaoBoss(inimigo& boss);
    void stunarIni(inimigo_boss& boss);
    void defenderIni(inimigo_boss& boss);
    void tipoDeAtaque(inimigo_boss& boss);
    void ataqueSecundario(inimigo_boss& boss);

    // clone
    inimigo *clone() const override;

    inimigo_boss (short dano_ini, short vida_ini, short defesa_ini, string nome_ini, string descricao_ini, 
        short raridade_ini, short exp_drop_ini, short chance_dano_overtime_ini, short dano_overtime_ini, 
        ataque_secundario_ini ataque_sec_ini, short chance_de_estun_ini, short chance_de_desviar_ini, 
        short chance_de_defender_ini, short escudo_ini);
};