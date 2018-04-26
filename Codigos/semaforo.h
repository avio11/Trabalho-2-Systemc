#include "systemc.h"

#define N_Methods 2

enum color_t {verde, amarelo, vermelho};
enum state_t {s0, s1, s2, s3};

SC_MODULE(semaforo){
    sc_in<bool> clk, sensor, time_complete; //clk=clock, time_comlete=sinal de retorno do modulo timer avisando que o wait da transicao de estado foi feita
    sc_out<bool> ativacao, time_length;     //ativacao=sinal que inicia a temporizacao, time_length indica se o wait deve durar Intervalo Longo ou IC
    sc_out<state_t> state, next_state;      //state=estado atual da fsm,
    sc_out<color_t> autoestrada, via_lateral;
    void att_logic();   //ĺogica de atualizacao de estado

    #if N_Methods == 3
    void ns_logic();    //lógica do próx. estado
    void output_logic();//logica de saida pro modulo monitor, apresenta as cores de cada semaforo
    #elif N_Methods == 2
    void ns_output_logic();
    #endif
    SC_CTOR(semaforo){
        SC_THREAD(att_logic);
        sensitive << clk.pos();

        #if N_Methods == 3
        SC_METHOD(ns_logic);
        sensitive << state << clk.pos();


        SC_METHOD(output_logic);
        sensitive << state;
        #elif N_Methods == 2
        SC_METHOD(ns_output_logic);
        sensitive << state << clk.pos();

        #endif // N_Methods
    }
};
