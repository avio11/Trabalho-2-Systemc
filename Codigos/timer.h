#include "systemc.h"

#define IL 2
#define IC 1

SC_MODULE(timer){
    sc_in<bool> clk, ativacao;
    sc_in<bool> time_length;
    sc_out<bool> time_complete;

    void tempo();

    SC_CTOR(timer){
        SC_THREAD(tempo);
    }

};
