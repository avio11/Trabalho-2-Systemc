#include "sistema.h"

int sc_main(int argc, char* argv[]){
    sistema sys("sys");
    sys.create_vcd();
    sc_start(50, SC_MS);
    sys.close_vcd();
    return 0;
}
