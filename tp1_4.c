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
    int cantidad = 5;
    struct compu *pcs = malloc(cantidad * sizeof(struct compu));
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    //INICIALIZACION DEL ARREGLO PCS

    for(int i=0; i < N; i++){
        pcs[i].velocidad = 1 + rand()%3;  //valores enteros entre 1 y 3
        pcs[i].anio = 2015 + rand()%(2024 - 2015 + 1); // valores enteros desde 2015 hasta 2024
        pcs[i].cantidad_nucleos = 1 + rand()%8; //valores enteros entre 1 y 8
        pcs[i].tipo_cpu = tipos[rand()%6]; //valores entre 0 y 5 del arreglo tipos
    }

    free(pcs);

    return 0;
}

void listarPCs(struct compu pcs[], int cantidad){
    printf("-----PCS Y SUS DATOS-----\n\n");

    for(int i = 0; i < cantidad; i++){
        printf("\nPC %d:\n", i + 1);
        printf("\nVelocidad: %d\nAnio: %d\nCantidad de nucleos: %d\nTipo de CPU: %s", pcs[i].velocidad, pcs[i].anio, pcs[i].cantidad_nucleos, pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad){
    int masVieja=0;
    char PC[10];

    for(int i=0; i < cantidad; i++){
        if(masVieja == 0 || masVieja < pcs[i].anio){
            masVieja = pcs[i].anio;
            PC[10] = pcs[i].tipo_cpu;
        }
    }

    printf("\n\nLa PC mas vieja encontrada es: %s, salio en el anio %d", PC[10], masVieja);

}

