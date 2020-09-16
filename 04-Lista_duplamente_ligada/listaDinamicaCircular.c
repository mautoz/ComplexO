/**************************************************/
/* Lista sem nó cabeça duplamente ligada Circular */
/**************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista {
    int chave;
    Lista *ant, *prox;
};

void inicializar(Lista **l) {
    printf("Inicializando a lista!\n");
    *l = NULL;
}

// Inserção genérica, sem se preocupar com ordem ou repetição
// Tentem criar uma nova que evite repetição e seja ordenada.
void inserir(Lista **l, int ch) {
    // Inserção de um elemento em uma lista inicialmente vazia
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    nova->chave = ch;
    if(*l == NULL) {
        printf("Inserindo o primeiro elemento...\n");
        *l = nova;
        nova->ant = *l;
        nova->prox = *l;
        return;
    }

    // Se chegou aqui, então *l != NULL, isto é, a lista contém
    // ao menos um elemento.
    printf("Inserindo mais elementos...\n");
    Lista *aux = *l;
    // Buscamos o último elemento da lista que, por ser circular,
    // apontará para o primeiro elemento.
    while(aux->prox != *l)
        aux = aux->prox;

    aux->prox = nova;
    nova->ant = aux;
    nova->prox = *l;
    (*l)->ant = nova;
}

int buscaElemento(Lista *l, int ch) {
    if(l == NULL)
        return 0;

    Lista *aux = l;

    do {
        if(aux->chave == ch)
            return 1;
        aux = aux->prox;
    } while(aux != l);

    return 0;
}

// Imprimi no sentido horário
void imprimirHorario(Lista *l) {
    if(l == NULL) {
        printf("A lista estah vazia!\n");
        return;
    }

    Lista *aux = l;
    printf("Elementos da lista: ");
    do{
        printf("%d ", aux->chave);
        aux = aux->prox;
    } while(aux != l);
    printf("\n");
}

// Imprimi no sentido anti-horário
void imprimirAntiHorario(Lista *l) {
    if(l == NULL) {
        printf("A lista estah vazia!\n");
        return;
    }

    Lista *aux = l->ant;
    printf("Elementos da lista: ");

    do {
        printf("%d ", aux->chave);
        aux = aux->ant;
    } while(aux != l->ant);
    printf("\n");
}

int main() {
    Lista *p;

    inicializar(&p);
    // Inseri ordenado para ficar bonito na impressão
    inserir(&p, 1);
    imprimirHorario(p);
    imprimirAntiHorario(p);
    inserir(&p, 2);
    imprimirHorario(p);
    imprimirAntiHorario(p);
    inserir(&p, 3);
    imprimirHorario(p);
    imprimirAntiHorario(p);
    inserir(&p, 4);
    imprimirHorario(p);
    imprimirAntiHorario(p);
    inserir(&p, 5);
    imprimirHorario(p);
    imprimirAntiHorario(p);
    inserir(&p, 6);
    imprimirHorario(p);
    imprimirAntiHorario(p);

    int num = 8;
    if(buscaElemento(p, num))
        printf("Existe o elemento!\n");
    else 
        printf("Nao existe o elemento.\n");
    
    return 0;
}