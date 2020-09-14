#include <stdio.h>
#include <stdlib.h>

typedef struct StrNo {
    int info;
    struct StrNo *prox;
} No;

void inicializaLista(No **l) {
    *l = NULL;
}

int ehVazia(No *l) {
    if (l == NULL)
        return 0;
    return 1; 
}

// Essa função só faz sentido se a lista estiver ordenada
int buscaListaOrdena(No **l, int i) {
    if (*l == NULL)
        return 0;

    No *aux = *l;

    while(aux != NULL && i > aux->info)
        aux = aux->prox;

    if (aux != NULL && aux->info == i) return 1;
    
    return 0;
}

No* buscaInfo(No **l, int i) {
    No* anterior = *l;
    No* atual = (*l)->prox;

    while(atual != NULL && i > atual->info) {
        anterior = anterior->prox;
        atual = atual->prox;
    }

    if(atual != NULL && atual->info == i) return NULL;

    return anterior;
}


// Essa função insere sem se preocupar com ordem
// Está funcionando, mas não sendo utilizada!
void inserir(No **l, int i) {    
    No *novo = (No *)malloc(sizeof(No));
    novo->info = i;
    novo->prox = NULL;
    
    if(*l == NULL) {  
        printf("Primeiro elemento!\n");      
        *l = novo;
        return;
    }
    
    printf("Demais elementos!\n");
    No *aux = *l;
    while(aux->prox != NULL)
        aux = aux->prox;
    aux->prox = novo;    
}

// Muito parecida com a ideia do professor, mas o uso dos ponteiros é levemente
// diferente! Acho que é uma boa maneira de ver que não existe uma única forma
// de fazer os exercícios.
void inserirOrdenado(No **l, int i) {
    No *novo = (No *)malloc(sizeof(No));
    novo->info = i;
    if(*l == NULL) {
        novo->prox = NULL;
        *l = novo;
        return;
    }

    No *anterior = buscaInfo(&(*l), i);

    if (anterior == NULL)
        return;
    
    novo->prox = anterior->prox;
    anterior->prox = novo;
}


void imprime(No *l) {
    No *aux;
    if(l == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    printf("Elementos da Lista: ");
    for(aux = l; aux != NULL; aux = aux->prox)
        printf("%d ", aux->info);
    printf("\n");
}

int main () {
    No *n;
    printf("Inicializando a lista!\n");
    inicializaLista(&n);

    printf("Inserindo ordenado e imprimindo!\n");
    inserirOrdenado(&n, 1);
    imprime(n);
    inserirOrdenado(&n, 3);
    imprime(n);
    inserirOrdenado(&n, 5);
    imprime(n);
    inserirOrdenado(&n, 4);
    imprime(n);
    inserirOrdenado(&n, 10);
    imprime(n);
    inserirOrdenado(&n, 8);
    imprime(n);

    // Testando se o num está na lista
    int num = 7;
    printf("O elemento %d estah na lista?\n", num);
    if(buscaListaOrdena(&n, num))
        printf("Sim, estah!\n");
    else
        printf("Nao estah!\n");

    return 0;
}