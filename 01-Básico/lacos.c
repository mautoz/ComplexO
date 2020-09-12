#include <stdio.h>
#include <stdlib.h>

int main () {
    int i;
    printf(">> Imprimindo de 1 a 10!\n\n");

    // Básico, igual ao que vocês devem ter visto no JAVA
    
    printf("> For: \n");
    
    for(i = 0; i < 10; i++)
        printf("%d ", (i+1));
    printf("\n\n");


    printf("> While: \n");

    // Mesma ideia do for, com o tempo vocês decidirão quando
    // um é melhor que o outro. 
    i = 1;
    while (i <= 10)
        printf("%d ", i++);
    printf("\n\n"); 


    printf("> Do/While: \n");

    // Parecido com o while, mas o while testa a condição desde
    // o início, já o Do executa a primeira e só depois começa a testar.
    i = 1;
    do {
        printf("%d ", i++);
    } while (i <= 10);
    printf("\n");

    return 0;
}