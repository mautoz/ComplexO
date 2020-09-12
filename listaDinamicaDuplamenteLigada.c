/**************************************************************/
/* Lista sem nó cabeça duplamente ligada                      */
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista {
    int chave;
    Lista *ant, *prox;
};

void inserirInicio(Lista **l, int ch) {
    Lista *nova = (Lista *)malloc(sizeof(Lista));

    nova->chave = ch;
    // Como será inserido no início, o ant apontará para NULL
    nova->ant = NULL;

    if (*l == NULL) {
        nova->prox = NULL;
        *l = nova;
        return;
    }

    // Caso não seja vazia, ele tem ao menos um elemento
    // O novo elemento vai para o início e o antigo primeiro 
    // elemento vira o segundo
    (*l)->ant = nova;
    nova->prox = *l;
    // Lista l agora começa no vo elemento
    *l = nova;
}

void imprimirInicio(Lista *l) {
    if (l == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    printf("Imprimindo do Inicio para o fim: ");

    Lista *aux;

    for (aux = l; aux != NULL;  aux = aux->prox) {
        printf("%d ", aux->chave);
    }
    printf("\n");
}

void imprimirFim(Lista *l) {
    if (l == NULL) {
        printf("A lista estah vazia!\n");
        return;
    }

    printf("Imprimindo do fim para o inicio: ");

    Lista *aux, *fim = l;

    while (fim->prox != NULL) 
        fim = fim->prox;

    for (aux = fim; aux != NULL; aux = aux->ant) {
        printf("%d ", aux->chave);
    }
    printf("\n");
}

int main () {
    Lista *p = NULL;

    inserirInicio(&p, 1);
    imprimirInicio(p);
    inserirInicio(&p, 2);
    inserirInicio(&p, 3);
    inserirInicio(&p, 7);
    inserirInicio(&p, 6);
    imprimirInicio(p);
    imprimirFim(p);

    return 0;
}