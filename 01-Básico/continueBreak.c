#include <stdio.h>
#include <stdlib.h>

int main () {
    // Quando trabalhamos com laços, as vezes, queremos
    // que ou ele encerre o laço dada uma condição ou ele não
    // execute parte do código caso uma outra condição.
    // Para altarar um loop, existem o break e o continue.

    // O break, vcs conhecem do switch. Dentro de um laço,
    // quando chamado, interrompe o loop.
    printf(">> Break\n\n");
    for (int i = 0; i < 10; i++) {
        if (i == 5)
            break;
        printf("%d ", i);
    }
    printf("\n\n");

    printf(">> Break em loop aninhado\n\n");
    // Se for laços aninhados (nested loop), ele somente interrompe
    // o laço que faz parte
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 5)
                break;
            printf("(%d, %d) ", i, j);
        }
        printf("\n");
    }
    printf("\n\n");

    printf(">> Continue\n\n");
    // O continue, quando chamado, pula todo o código que existe
    // abaixo dele, mas não interrompe o loop:
    for (int i = 0; i < 10; i++) {
        if (i == 5)
            continue;
        printf("%d ", i);
    }
    printf("\n\n");

    return 0;
}