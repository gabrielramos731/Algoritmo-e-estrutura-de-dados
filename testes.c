#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *v;
    int tam;
} lista;

void inicializa(lista * l);
void insereFim(lista * l, int num);
void insereInicio(lista * l, int num);
void remover(lista * l, int p);

int main(){

    lista l;
    inicializa(&l);
    insereFim(&l, 2);
    insereFim(&l, 3);
    insereFim(&l, 4);
    insereInicio(&l, 1);

    remover(&l, 1);

    for(int i=0; i<l.tam; i++)
        printf("%d ", l.v[i]);
}

void inicializa(lista * l){

    (*l).v = (int *) calloc(1000, sizeof(lista));  
    l->tam = 0; 
}

void insereFim(lista * l, int num){
    l->v[(l->tam++)] = num;
}

void insereInicio(lista * l, int num){

    for(int i=(l->tam+1); i!=0; i--)
        l->v[i] = l->v[i-1];
    l->v[0] = num;
    l->tam++;
}

void remover(lista * l, int p){
    for(int i=p; i<(l->tam-1); i++){
        l->v[i] = l->v[i+1];
    }
    l->tam--;
}

