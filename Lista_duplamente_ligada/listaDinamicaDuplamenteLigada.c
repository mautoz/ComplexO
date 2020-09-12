/*****************************************/
/* Lista sem nó cabeça duplamente ligada */
/*****************************************/

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

    // Caso a lista esteja vazia
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

void inserirFim(Lista **l, int ch) {
    Lista *nova = (Lista *)malloc(sizeof(Lista));

    nova->chave = ch;
    // Será adicionado no fim, então prox deve ser NULL 
    nova->prox = NULL;

    //Caso a lista seja vazia
    if (*l == NULL) {
        nova->ant = NULL;
        *l = nova;
        return;
    }

    Lista *aux = *l;

    // Procurar o fim da lista
    while (aux->prox != NULL)
        aux = aux->prox;

    aux->prox = nova;
    nova->ant = aux;
}

void imprimirInicio(Lista *l) {
    if(l == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    printf("Imprimindo do Inicio para o fim: ");

    Lista *aux;

    for(aux = l; aux != NULL;  aux = aux->prox) {
        printf("%d ", aux->chave);
    }
    printf("\n");
}

void imprimirFim(Lista *l) {
    if(l == NULL) {
        printf("A lista estah vazia!\n");
        return;
    }

    printf("Imprimindo do fim para o inicio: ");

    Lista *aux, *fim = l;

    // Ir para o fim da lista
    while(fim->prox != NULL) 
        fim = fim->prox;

    //Fim da lista foi achado, agora podemos percorrer do fim para o início
    for(aux = fim; aux != NULL; aux = aux->ant) {
        printf("%d ", aux->chave);
    }
    printf("\n");
}

int main() {
    Lista *p = NULL;

    inserirInicio(&p, 1);
    imprimirInicio(p);
    inserirInicio(&p, 2);
    inserirInicio(&p, 3);
    inserirInicio(&p, 7);
    inserirInicio(&p, 6);
    imprimirInicio(p);
    imprimirFim(p);
    inserirFim(&p, 7);
    inserirFim(&p, 8);
    inserirFim(&p, 9);
    imprimirInicio(p);
    imprimirFim(p);

    return 0;
}