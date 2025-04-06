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

    //INVOCACION DE LAS FUNCIONES
    listarPCs(pcs, cantidad);
    mostrarMasVieja(pcs, cantidad);
    mostrarMasVeloz(pcs, cantidad);

    free(pcs);

    return 0;
}

void listarPCs(struct compu pcs[], int cantidad){
    printf("-----PCS Y SUS DATOS-----\n\n");

    for(int i = 0; i < cantidad; i++){
        printf("\nPC %d:\n", i + 1);
        printf("\nVelocidad: %d GHz\nAnio: %d\nCantidad de nucleos: %d\nTipo de CPU: %s\n\n", pcs[i].velocidad, pcs[i].anio, pcs[i].cantidad_nucleos, pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad){
    
    struct compu pcVieja;

    pcVieja = pcs[0]; //asumo que la primera PC es la mas vieja

    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].anio < pcVieja.anio) {
            pcVieja = pcs[i]; 
        }
    }

    printf("\n\n----- PC MAS VIEJA -----\n");
    printf("Velocidad: %d GHz\n", pcVieja.velocidad);
    printf("Anio: %d\n", pcVieja.anio);
    printf("Cantidad de nucleos: %d\n", pcVieja.cantidad_nucleos);
    printf("Tipo de CPU: %s\n", pcVieja.tipo_cpu);
}

void mostrarMasVeloz(struct compu pcs[], int cantidad){
    struct compu pcVieja;

    pcVieja = pcs[0]; //asumo que la primera PC es la mas veloz

    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].velocidad > pcVieja.velocidad) {
            pcVieja = pcs[i]; 
        }
    }

    printf("\n\n----- PC MAS VELOZ -----\n");
    printf("Velocidad: %d GHz\n", pcVieja.velocidad);
    printf("Anio: %d\n", pcVieja.anio);
    printf("Cantidad de nucleos: %d\n", pcVieja.cantidad_nucleos);
    printf("Tipo de CPU: %s\n", pcVieja.tipo_cpu);
}