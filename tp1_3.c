#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main()
{

    srand(time(NULL));
    int i, j;
    int mt[N][M];
    int *ptrmt = &mt[0][0];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            *(ptrmt + i * N + j) = 1 + rand() % 100;

            printf("%2d  ", *(ptrmt + i * N + j));
        }
        printf("\n");
    }

    return 0;
}