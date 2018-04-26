#include "semaforo_tb.h"

#define ciclos 20 //define quantos ciclos serao realizados em cada teste abaixo

void semaforo_tb::aciona(){

    int counter = ciclos;
    int temp = 0;   //temp alterna o valor de clk no loop while(counter--)

    sensor = 0;
    wait(1, SC_MS);
    cout << "Sensor: " << sensor << endl;
    while(counter--){
        if(temp){
            clk = 1;
            wait(1, SC_MS);
            temp = 0;
            //cout << "Autoestrada: " << autoestrada << " | " << "Via lateral: " << via_lateral << " " << sc_time_stamp() << endl;
            cout << "Estado: " << state << " " << sc_time_stamp() << endl;
        }
        else{
            clk = 0;
            wait(1, SC_MS);
            temp = 1;
            //cout << "Autoestrada: " << autoestrada << " | " << "Via lateral: " << via_lateral << " " << sc_time_stamp() << endl;
            cout << "Estado: " << state << " " << sc_time_stamp() << endl;
        }
    }

        counter = ciclos;


        sensor = 1;
        wait(1, SC_MS);
        cout << "Sensor: " << sensor << endl;
        while(counter--){
            if(temp){
                clk = 1;
                wait(1, SC_MS);
                temp = 0;
                //cout << "Autoestrada: " << autoestrada << " | " << "Via lateral: " << via_lateral << " " << sc_time_stamp() << endl;
                cout << "Estado: " << state << " " << sc_time_stamp() << endl;
            }
            else{
                clk = 0;
                wait(1, SC_MS);
                temp = 1;
                //cout << "Autoestrada: " << autoestrada << " | " << "Via lateral: " << via_lateral << " " << sc_time_stamp() << endl;
                cout << "Estado: " << state << " " << sc_time_stamp() << endl;
            }
        }
}
