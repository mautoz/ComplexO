#include <stdlib.h>
#include <stdio.h>

void recursao(int *v, int *max, int *posicao) {
    if (*posicao == 11)
        return;
    if (*max < v[*posicao])
        *max = v[*posicao];
    (*posicao)++;
    printf("TempMax é: %d\n", *max);
    printf("TempPos é: %d\n", *posicao);
    recursao(v, &(*max), &(*posicao));
}

int main() {
    int v[11] = {1, 2, 3, 5, 4, 9, 8, 7, 15, 100, 0};
    int i;
    int maximo = -1;

    // Imprimir o vetor
    for (i = 0; i < 11; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    i = 0;

    // Verifica recursivamente o maior elemento.
    recursao(v, &maximo, &i);

    printf("\n\n**Maximo é: %d**\n\n", maximo);

	return 0;
}