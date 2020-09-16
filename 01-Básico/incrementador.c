#include <stdio.h>
#include <stdlib.h>

int main () {
    printf(">> Incremento\n");

    int i = 0;

    // Quando usamos o i++, ele primero realiza a tarefa antes
    // do i = i + 1 e depois faz o incremento.
    printf("%d\n", i++);
    printf("%d\n\n", i);    

    // O ++i é o contrário, primeiro realiza o i = i + 1 e depois
    // faz a tarefa seguinte.
    printf("%d\n", ++i);
    printf("%d\n\n", i);    

    // Essa dica simples é útil para deixar o código mais enxuto
    // em situações como alterar uma posição em arranjo.
    // Ao invés de fazer:
    // A[i] = x;
    // i++;
    // Trocamos por:
    // A[i++] = x;

    // Para o decremento a regra é a mesma
    printf(">> Decremento\n");

    int j = 0;

    printf("%d\n", j--);
    printf("%d\n\n", j);

    printf("%d\n", --j);
    printf("%d\n\n", j);

    return 0;
}