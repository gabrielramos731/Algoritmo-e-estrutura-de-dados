#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int val;
    struct No *prox;
} No;

typedef struct{
    No *inicio;  //vai ser NULL se a lista estiver vazia ou apontar para o primeiro No
} lista;

void iniciaLista(lista *listaEn);
void inserirInicio(lista *listaEn, int val);
void inserirFim(lista *listaEn, int val);
void imprimirLista(lista *listaEn);

int main(){

    lista listaEn;
    iniciaLista(&listaEn);
    inserirInicio(&listaEn, 5);
    inserirInicio(&listaEn, 7);
    inserirInicio(&listaEn, 9);
    inserirFim(&listaEn, 1);
    imprimirLista(&listaEn);
}

void iniciaLista(lista *listaEn){

    listaEn->inicio = NULL;
    listaEn->tam = 0;
}

void inserirInicio(lista *listaEn, int val){

    No *novoNo = (No *) malloc(sizeof(No));
    novoNo->val = val;
    novoNo->prox = listaEn->inicio;  //último nó não aponta para ninguem

    listaEn->inicio = novoNo;  //passa o endereço de memória do nó inserido para inicio
    listaEn->tam++;
}

void inserirFim(lista *listaEn, int val){

    No *no, *novoNo = (No *) malloc(sizeof(No));
    novoNo->val = val;
    novoNo->prox = NULL;

    if(listaEn->inicio == NULL)  //lista estava vazia
        listaEn->inicio = novoNo;
    else{
        no = listaEn->inicio;  //é um no que apontara para cada no
        while(no->prox != NULL)
            no = no->prox;  //atualiza o no
        no->prox = novoNo;
    }
}

void imprimirLista(lista *listaEn){
    
    No *inicio = listaEn->inicio;
    while(inicio != NULL){
        printf("%d ", inicio->val);
        inicio = inicio->prox;
    }
}
