#include <stdio.h>
#include <stdlib.h>

int main () {
    int *v;
    int tam;

    do {
        printf("Digite um tamanho de vetor (1 ateh 10): ");
        scanf("%d", &tam);
    } while (tam <= 0 || tam >= 10);
    printf("Voce escolheu: %d\n", tam);

    // Alocando memória para um vetor de int
    v = (int *)malloc(sizeof(int) * tam);

    // Inicializando o vetor
    for (int i = 0; i < tam; i++)
        v[i] = i;

    printf("Abaixo estah o vetor de 1 ateh %d:\n", tam);
    for (int i = 0; i < tam; i++)
        printf("%d ", i);
    printf("\n");

    return 0;
}