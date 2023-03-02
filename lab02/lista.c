#include<stdlib.h>
#include "lista.h"

void inicializa_lista(Lista *ap_lista){
  
  No *no_cab = (No*)malloc(sizeof(No));
  *ap_lista = no_cab;
  no_cab->antec = no_cab;
  no_cab->prox = no_cab;
}

void insere_inicio(Lista ap_lista, TipoDado valor){

  No *novo = (No*)malloc(sizeof(No));
  novo->valor = valor;

  novo->prox = ap_lista->prox;
  novo->antec = ap_lista;
  ap_lista->prox = novo;
  novo->prox->antec = novo;
}

void insere_fim(Lista ap_lista, TipoDado valor){

  No *novo = (No*)malloc(sizeof(No));
  novo->valor = valor;

  novo->prox = ap_lista;
  novo->antec = ap_lista->antec;
  ap_lista->antec->prox = novo;
  ap_lista->antec = novo;
}

TipoDado remove_fim(Lista ap_lista){

  TipoDado val;
  No *no_aux = ap_lista->antec;

  if(ap_lista->prox != ap_lista){
    val = no_aux->valor;
    no_aux->antec->prox = ap_lista;
    ap_lista->antec = no_aux->antec;
    free(no_aux);
  }
  return val;
}

TipoDado remove_inicio(Lista ap_lista){

  No *no_aux = ap_lista->prox;
  TipoDado val;

  if (ap_lista->prox != ap_lista){
    val = ap_lista->prox->valor;
    ap_lista->prox = no_aux->prox;
    no_aux->prox->antec = ap_lista;
    free(no_aux);
  }
  return val;
}

int remove_ocorrencias(Lista ap_lista, TipoDado valor){

  int cont = 0;
  No *no_aux = ap_lista->prox;
  No *remove=no_aux;
    while(no_aux != ap_lista){
      if(no_aux->valor.coef == valor.coef && no_aux->valor.grau == valor.grau){
        no_aux->antec->prox = no_aux->prox;
        no_aux->prox->antec = no_aux->antec;
        remove=no_aux->prox;
        free(no_aux);
        no_aux=remove;
        cont++;
        continue;
      }
      no_aux = no_aux->prox;
      remove=no_aux;
    }
  return cont;
}

int busca(Lista lista, TipoDado valor){

  int pos = 0;
  No *no_aux = lista->prox;

  while(no_aux != lista){
    if(no_aux->valor.coef == valor.coef && no_aux->valor.grau ==  valor.grau)
      return pos;
    no_aux = no_aux->prox;
    pos++;
  }
  return -1;
}

int coeficiente_do_grau(Lista lista, int grau){

  No *no_aux = lista->prox;

  while(no_aux != lista){
    if(no_aux->valor.grau == grau)
      return no_aux->valor.coef;
    no_aux = no_aux->prox;
  }

  return 0;
}

void desaloca_lista(Lista *ap_lista){

  No *no_aux = (*ap_lista)->antec;

  while(no_aux != *ap_lista){
    (*ap_lista)->antec = (*ap_lista)->antec->antec;
    free(no_aux);
    no_aux = (*ap_lista)->antec;
  }
  free(*ap_lista);
}

void imprime(Lista lista){

  No *aux=(No*)malloc(sizeof(No));
  aux=lista->prox;

  printf("[");
  while(aux!=lista){
    printf("(%d,%d)",aux->valor.grau, aux->valor.coef);
    if(aux->prox!=lista)
      printf(",");
    aux=aux->prox;
  }
  printf("]\n");
}
