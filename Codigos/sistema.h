#include "semaforo_tb.h"
#include "timer.h"

SC_MODULE(sistema){
    sc_signal<bool> clk, sensor, time_length, ativacao, time_complete;
    sc_signal<state_t> state, next_state;
    sc_signal<color_t> autoestrada, via_lateral;

    sc_trace_file* wave;
    void create_vcd(){
        wave = sc_create_vcd_trace_file("wave_2_methods");
        wave->set_time_unit(1,SC_MS);

        sc_trace(wave, clk, "clk");
        sc_trace(wave, sensor, "sensor");
        sc_trace(wave, state, "state");
        sc_trace(wave, ativacao, "ativacao");
        sc_trace(wave, time_complete, "time_complete");
    }
    void close_vcd(){
        sc_close_vcd_trace_file(wave);
        cout << "Criou wave.vcd" << endl;
    }

    semaforo s;
    semaforo_tb s_tb;
    timer t;

    SC_CTOR(sistema) : s("s"), s_tb("s_tb"), t("t"){
        s.clk(clk);
        s_tb.clk(clk);
        s.sensor(sensor);
        s_tb.sensor(sensor);
        s.state(state);
        s_tb.state(state);
        s.next_state(next_state);
        s_tb.next_state(next_state);
        s.autoestrada(autoestrada);
        s_tb.autoestrada(autoestrada);
        s.via_lateral(via_lateral);
        s_tb.via_lateral(via_lateral);

        t.clk(clk);
        s.ativacao(ativacao);
        t.ativacao(ativacao);
        s.time_length(time_length);
        t.time_length(time_length);
        s.time_complete(time_complete);
        t.time_complete(time_complete);

    }


};
