#include <stdio.h>
#include <stdlib.h>

#define N 5;

struct compu {
    int velocidad; 
    int anio; 
    int cantidad_nucleos; 
    char *tipo_cpu; 
};
   

void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);

int main(){

    struct compu pcs[N];


    return 0;
}