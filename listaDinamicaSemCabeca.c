/**************************************************************/
/* Lista sem nó cabeça com inserção no início                 */
/* Compilação:                                                */
/* $ gcc -o listaDinamicaSemCabeca listaDinamicaSemCabeca.c   */
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct lista Lista;

struct lista {
    int chave;
    Lista *prox;
};

void inserirInicio(Lista **l, int ch) {
    // Cria um elemento auxiliar do tipo lista
    // aloca o espaço
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    // Recebe chave
    novo->chave = ch;

    // Caso a lista seja NULL, isto é, vazia
    // o prox aponta para NULL
    if (*l == NULL)
        novo->prox = NULL;
    // Caso já existam elementos, o elemento será
    // inserido no inicio da fila e o seu prox deve apontar
    // para o inicio
    else
        novo->prox=*l;

    // No final acertamos o ponteiro para o novo inicio da lista
    *l=novo;
}

void inserirFim(Lista **l, int ch) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    // o novo elemnto recebe o ch e o prox NULL
    // pois será inserido no fim da lista
    novo->chave = ch;
    novo->prox = NULL;

    // Lista vazia, insere o primeiro elemento
    if (*l == NULL) {
        novo->prox = NULL;
    }
    // Precisamos inserir no fim
    else {
        Lista *aux = *l;

        while(aux->prox != NULL)
            aux = aux->prox;

        aux->prox = novo;
    }
}

void removerInicio(Lista **l) {
    if (*l == NULL) {
        printf("A lista jah estah vazia\n");
        return;
    }

    Lista *aux = *l;

    *l = (*l)->prox;

    free(aux);
}

void removerFim(Lista **l) {
    if (*l == NULL) {
        printf("A lista jah estah vazia\n");
        return;
    }

    Lista *aux = *l;

    while (aux->prox != NULL)
        aux = aux->prox;

}

void imprimir(Lista *l) {
    Lista *aux;

    for(aux=l; aux!=NULL; aux=aux->prox) {
        printf("%d ", aux->chave);
    }
    printf("\n");
}

int main () {
    Lista *p = NULL;

    removerInicio(&p);
    inserirInicio(&p, 1);
    inserirInicio(&p, 2);
    inserirInicio(&p, 5);
    inserirInicio(&p, 4);
    imprimir(p);
    inserirFim(&p, 7);
    imprimir(p);
    removerInicio(&p);
    imprimir(p);
    inserirFim(&p, 9);
    inserirFim(&p, 8);
    imprimir(p);

    return 0;
}