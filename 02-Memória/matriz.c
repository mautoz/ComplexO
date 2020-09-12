#include <stdio.h>
#include <stdlib.h>

int main () {
    int **matriz;
    int m, n;
    // Será uma matriz mxn

    do {
        printf("Digite o numero de linhas (1 ateh 10): ");
        scanf("%d", &m);
    } while (m <= 0 || m >= 10);
    printf("A matriz terah: %d linhas!\n", m);

    do {
        printf("Agora digite o numero de colunas (1 ateh 10): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 10);
    printf("A matriz terah: %d colunas!\n", n);

    // Alocando a memória da matriz
    matriz = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < m; i++) {
        matriz[i] = (int *)malloc(sizeof(int) * n);
    }

    // Inicializando a matriz
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            matriz[i][j] = i + j;
    }

    printf("A matriz %d x %d estah abaixo: \n\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) 
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("\n");

    return 0;
}