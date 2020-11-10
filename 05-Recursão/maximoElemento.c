#include <stdlib.h>
#include <stdio.h>

void recursao(int *v, int *max, int *posicao) {
    if (*posicao == 8)
        return;
    if (*max < v[*posicao])
        *max = v[*posicao];
    (*posicao)++;
    printf("TempMax é: %d\n", *max);
    printf("TempPos é: %d\n", *posicao);
    recursao(v, &(*max), &(*posicao));
}

int main() {
    int v[8] = {1, 2, 3, 5, 4, 9, 8, 7};
    int i;
    int maximo = -1;

    for (i = 0; i < 8; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    i = 0;

    recursao(v, &maximo, &i);

    printf("**Maximo é: %d**", maximo);

	return 0;
}