/**********************************************/
/* Lista sem nó cabeça com inserção no início */
/**********************************************/

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
    // Lista vazia! nada para ser feito!
    if (*l == NULL) {
        printf("Nao ha o que remover no inicio! A lista jah estah vazia\n");
        return;
    }

    // Lista auxiliar criada para não perder o ponteiro
    // do início da lista
    Lista *aux = *l;

    // A lista agora aponta para o segundo elemento
    *l = (*l)->prox;

    // Liberamos a memória
    free(aux);
}

void removerFim(Lista **l) {
    // Verficia se a lista não está vazia 
    if (*l == NULL) {
        printf("Nao ha o que remover do fim! A lista jah estah vazia\n");
        return;
    }

    // Lista só tem um elemento?
    if ((*l)->prox == NULL) {
        (*l) = NULL;
        return;
    }
    // Caso o código chegue nessa linha, a lista não é vazia
    // e possui mais de um elemento

    // Primeiro elemento da lista l
    Lista *anterior = *l;
    // Segundo elemento da lista l
    Lista *atual = (*l)->prox;

    // Percorre a lista e quando atual->prox == NULL quer dizer
    // que o atual está no fim da lista e o anterior é o penúltimo
    // isso ajuda pois iremos remover o último elemento.
    while (atual->prox != NULL) {
        anterior = anterior -> prox;
        atual = atual ->prox;
    }

    anterior->prox = NULL;
    free(atual);
}

void imprimir(Lista *l) {
    Lista *aux;

    if (l == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

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
    removerFim(&p);
    imprimir(p);
    removerFim(&p);
    imprimir(p);
    removerFim(&p);
    imprimir(p);
    removerFim(&p);
    imprimir(p);
    removerFim(&p);
    imprimir(p);
    removerInicio(&p);
    imprimir(p);
    removerFim(&p);
    imprimir(p);
    removerInicio(&p);
    imprimir(p);

    return 0;
}