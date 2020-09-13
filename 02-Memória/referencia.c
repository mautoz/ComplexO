#include <stdio.h>
#include <stdlib.h>

void func1(int *n) {
    *n = 1;
}

void func2(int m) {
    m = 1;
}

int main () {
    int num = 0;
    // Tem um gif na pasta que ilustra bem o conceito de passar
    // o valor e passar por referência

    // Como funciona quando passa o endereço da variável
    printf("Antes de func1: %d\n", num);
    func1(&num);
    printf("Antes de func1: %d\n", num);  

    // Quando passamos apenas o valor
    printf("Antes de func2: %d\n", num);
    func1(&num);
    printf("Antes de func2: %d\n", num);

    return 0;
}