#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main(){

    srand(time(NULL));
    int i;
    double vt[N];
    double *punteroV = vt;

    for(int i=0; i < N; i++){
        punteroV[i] = (i + (1 + rand()%100));
        printf("%.2f ", punteroV[i]);
    }

    return 0;
}
