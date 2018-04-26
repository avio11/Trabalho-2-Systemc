#include "timer.h"

void timer::tempo(){
    while(true){
        if(time_length) wait(IL, SC_MS);
        else wait(IC, SC_MS);
        time_complete.write(1);
        wait(1, SC_MS);
        time_complete.write(0);
    }
}
