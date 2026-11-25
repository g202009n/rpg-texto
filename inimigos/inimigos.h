// incompleto
#pragma once
#include "../util/util.h"
#include "../proto/proto.h"

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
    virtual short inimigoBossGetterChanceAtaqueSecundarioDanoOvertime();
    virtual short inimigoBossGetterChanceStun();
    virtual short inimigoBossGetterChanceDesviar();
    virtual short inimigoBossGetterChanceDefender();
    virtual short inimigoBossGetterEscudo();


    // setters
    void inimigoSetterDano(short valor);
    void inimigoSetterVida(short valor);
    void inimigoSetterDefesa(short valor);

    virtual void inimigoOvertimeSetterChanceOvertime(short valor);
    virtual void inimigoOvertimeSetterDanoOvertime(short valor);

    virtual void inimigoBossSetterDanoAtaqueSecundario(short valor);
    virtual void inimigoBossSetterDanoAtaqueSecundario(short valor);
    virtual void inimigoBossSetterEscudo(short valor);


    // ações
    void inimigoAtacar(protogen& p);
    void inimigoMorrer(protogen& p);

    // clone
    inimigo clone() const;

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
    short inimigoBossGetterChanceAtaqueSecundarioDanoOvertime() override;
    short inimigoBossGetterChanceStun() override;
    short inimigoBossGetterChanceDesviar() override;
    short inimigoBossGetterChanceDefender() override;
    short inimigoBossGetterEscudo() override;

    // setters
    void inimigoBossSetterDanoAtaqueSecundario(short valor) override;
    void inimigoBossSetterDanoAtaqueSecundario(short valor) override;
    void inimigoBossSetterEscudo(short valor) override;

    // ações
    void determinarAcaoBoss(inimigo& boss);
    void stunarIni(inimigo_boss& boss);
    void defenderIni(inimigo_boss& boss);
    void tipoDeAtaque(inimigo_boss& boss);
    void ataqueSecundario(inimigo_boss& boss);

    inimigo_boss (short dano_ini, short vida_ini, short defesa_ini, string nome_ini, string descricao_ini, 
        short raridade_ini, short exp_drop_ini, short chance_dano_overtime_ini, short dano_overtime_ini, 
        ataque_secundario_ini ataque_sec_ini, short chance_de_estun_ini, short chance_de_desviar_ini, 
        short chance_de_defender_ini, short escudo_ini);
};