#include "semaforo.h"

void semaforo::att_logic(){
    while(true){
        ativacao.write(1);
        if((state==s0&&!sensor)||(state==s2)) time_length.write(1);
        else time_length.write(0);
        wait(1, SC_MS);
        ativacao.write(0);
        if(time_complete)    state.write(next_state);
    }
}
#if N_Methods == 3
void semaforo::ns_logic(){

    switch(state){
        case s0:
            if(sensor) next_state.write(s1);
            break;
        case s1:
            next_state.write(s2);
            break;
        case s2:
            next_state.write(s3);
            break;
        case s3:
            next_state.write(s0);
            break;
    }
}


void semaforo::output_logic(){
    switch(state){
        case s0:
            autoestrada.write(verde);
            via_lateral.write(vermelho);
            break;
        case s1:
            autoestrada.write(amarelo);
            via_lateral.write(vermelho);
            break;
        case s2:
            autoestrada.write(vermelho);
            via_lateral.write(verde);
            break;
        case s3:
            autoestrada.write(vermelho);
            via_lateral.write(amarelo);
            break;
    }
}
#elif N_Methods==2
void semaforo::ns_output_logic(){
    switch(state){
        case s0:
            autoestrada.write(verde);
            via_lateral.write(vermelho);
            if(sensor) next_state.write(s1);
            break;
        case s1:
            autoestrada.write(amarelo);
            via_lateral.write(vermelho);
            next_state.write(s2);
            break;
        case s2:
            autoestrada.write(vermelho);
            via_lateral.write(verde);
            next_state.write(s3);
            break;
        case s3:
            autoestrada.write(vermelho);
            via_lateral.write(amarelo);
            next_state.write(s0);
            break;
    }
}

#endif // N_Methods
