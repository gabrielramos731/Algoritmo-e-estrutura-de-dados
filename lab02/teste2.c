#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
  int grau;
  int coef;
}TipoDado;

typedef struct No_aux {
  TipoDado valor;
  struct No_aux * antec;  
  struct No_aux * prox;
} No;
typedef No * Lista;

void inicializa_lista(Lista * ap_lista);
void insere_fim(Lista ap_lista, TipoDado valor);
void insere_inicio(Lista ap_lista, TipoDado valor);
TipoDado remove_fim(Lista ap_lista);
TipoDado remove_inicio(Lista ap_lista);
int remove_ocorrencias(Lista ap_lista, TipoDado valor);
int busca(Lista lista, TipoDado valor);
int coeficiente_do_grau(Lista lista, int grau);
void desaloca_lista(Lista *ap_lista);
void imprime(Lista lista);

int main() {
  int conta, posicao, grau, coef;
  char comando[300];
  Lista l;
  TipoDado dado;
  inicializa_lista(&l);
  while(scanf("%s", comando) == 1) {
    if (strcmp(comando, "insere_inicio") == 0) {
      if(scanf("%d%d", &dado.grau, &dado.coef) != 2) return 1;
      insere_inicio(l, dado);
      printf("Inserido (%d,%d) no inicio.\n", dado.grau, dado.coef);
     }else if (strcmp(comando, "insere_fim") == 0) {
      if(scanf("%d%d", &dado.grau, &dado.coef) != 2) return 1;
      insere_fim(l, dado);
      printf("Inserido (%d,%d) no fim.\n", dado.grau, dado.coef);
    }else if (strcmp(comando, "remove_inicio") == 0) {
      dado = remove_inicio(l);
      printf("Removido (%d,%d) do inicio.\n", dado.grau, dado.coef);      
    }else if (strcmp(comando, "remove_fim") == 0) {
      dado = remove_fim(l);
      printf("Removido (%d,%d) do fim.\n", dado.grau, dado.coef);      
    }else if (strcmp(comando, "remove_ocorrencias") == 0) {
      if(scanf("%d%d", &dado.grau, &dado.coef) != 2) return 1;
      conta = remove_ocorrencias(l, dado);
      printf("Removidas %d ocorrencias de (%d,%d).\n", conta, dado.grau, dado.coef);      
    }
    else if (strcmp(comando, "busca") == 0) {
      if(scanf("%d%d", &dado.grau, &dado.coef) != 2) return 1;
      posicao = busca(l, dado);
      if (posicao == -1) {
	printf("Valor (%d,%d) nao encontrado na lista.\n", dado.grau, dado.coef);
      }else {
	printf("Valor (%d,%d) encontrado na posicao %d.\n", dado.grau, dado.coef, posicao);     
      }
    }else if (strcmp(comando, "coeficiente_do_grau") == 0) {
      if(scanf("%d", &grau) != 1) return 1;
      coef = coeficiente_do_grau(l, grau);
      printf("Coeficiente de grau %d = %d.\n", grau, coef);
    }
    else if (strcmp(comando, "imprime") == 0) {
      imprime(l);
     }else {
      printf("Comando invalido.\n");
      return 2;
    }
  }
  desaloca_lista(&l);
  return 0;
}

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
  free(ap_lista);
}

void imprime(Lista lista){

  No *aux=(No*)malloc(sizeof(No));
  aux=lista->prox;
  printf("\n[");
  while(aux!=lista){
     printf("(%d,%d)",aux->valor.grau,aux->valor.coef);
    if(aux->prox!=lista){
      printf(",");
    }
    aux=aux->prox;
  }
  printf("]\n");
}
