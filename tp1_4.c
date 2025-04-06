#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

struct compu
{
    int velocidad;
    int anio;
    int cantidad_nucleos;
    char *tipo_cpu;
};

void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);

int main()
{
    srand(time(NULL));
    struct compu pcs[N];
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    //INICIALIZACION DEL ARREGLO PCS

    for(int i=0; i < N; i++){
        pcs[i].velocidad = 1 + rand()%3;  //valores enteros entre 1 y 3
        pcs[i].anio = 2015 + rand()%(2024 - 2015 + 1); // valores enteros desde 2015 hasta 2024
        pcs[i].cantidad_nucleos = 1 + rand()%8; //valores enteros entre 1 y 8
        pcs[i].tipo_cpu = tipos[rand()%6]; //valores entre 0 y 5 del arreglo tipos
    }

    return 0;
}