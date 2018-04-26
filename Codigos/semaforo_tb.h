#include "semaforo.h"

SC_MODULE(semaforo_tb){
    sc_out<bool> sensor, clk;
    sc_in<state_t> state, next_state;
    sc_in<color_t> autoestrada, via_lateral;

    void aciona();

    SC_CTOR(semaforo_tb){
        SC_THREAD(aciona);
    }
};
