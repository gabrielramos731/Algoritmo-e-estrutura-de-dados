#include<stdio.h>
// #include<string.h>
#include<stdlib.h>

typedef struct No_aux {
  int valor;
  struct No_aux * proximo;
} No;
typedef No * Lista;

void inicializa_lista(Lista * ap_lista){

  *ap_lista = NULL;
}

void insere_fim(Lista *ap_lista, int valor){

  No *no_aux, *novoNo = (No *) malloc(sizeof(No));
  novoNo->proximo = NULL;
  novoNo->valor = valor;

  if(*ap_lista == NULL)  //lista vazia
    *ap_lista = novoNo;
  else{
    no_aux = *ap_lista;
    while(no_aux->proximo != NULL)
      no_aux = no_aux->proximo;  //no_aux aponta para o próximo no
    no_aux->proximo = novoNo;  //último no aponta para novoNo
  }
}

void insere_inicio(Lista *ap_lista, int valor){

  No *novoNo = (No *) malloc(sizeof(No));
  novoNo->valor = valor;

  novoNo->proximo = *ap_lista;  //novoNo aponta para antigo primeiro NO
  *ap_lista = novoNo;  //cabeça da lista aponta para o novoNo
}

int remove_fim(Lista *ap_lista){

  int val;

  Lista *inicio = ap_lista;
  
  while((*inicio)->proximo != NULL)
    inicio = &((*inicio)->proximo);
  
  val = (*inicio)->valor;
  *inicio = NULL;
  return val;
}

int remove_inicio(Lista *ap_lista){

  int x;
  No *no_aux = *ap_lista;

  *ap_lista = no_aux->proximo;  //ap_lista aponta para o segundo
  x = no_aux->valor;
  free(no_aux);

  return x;  
}

// Não ta funcionando
int remove_ocorrencias(Lista *ap_lista, int valor){
  
  int cont = 0;
  No *atual = *ap_lista;
  No *no_anterior = NULL;

  while(atual != NULL){
    if(atual->valor == valor && *ap_lista == atual){  //caso seja o primeiro
      if(atual->proximo == NULL){  //primeiro e único
        *ap_lista = NULL;
        free(atual);
        return cont + 1;
      }
      atual = atual->proximo;
      free(*ap_lista);
      *ap_lista = atual;
      cont++;
    }
    else{
      no_anterior = atual;
      atual = atual->proximo;
      if(atual->valor == valor){
        if(atual->proximo == NULL)
          
        free(no_anterior->proximo);
        cont++;
      }
    }
  }
  return cont;
}

int busca(Lista lista, int valor){

  int cont = 0;
  No *no_aux = lista;

  while(no_aux != NULL){
    if(no_aux->valor == valor)
      return cont;
    cont++;
    no_aux = no_aux->proximo;
  }
  return -1;
}

void imprime(Lista lista){

    printf("(");
    while(lista != NULL){
        if(lista->proximo != NULL)
          printf("%d,", lista->valor);
        else
          printf("%d", lista->valor);
        lista = lista->proximo;
    }
    printf(")");
}

void desaloca_lista(Lista *ap_lista){
  
  No *no_atual = *ap_lista;

  while(no_atual != NULL){
    No *no_proximo = no_atual->proximo;
    free(no_atual);
    no_atual = no_proximo;
  }
  *ap_lista = NULL;
}

int main(){
  int x, conta, posicao;
  char comando[300];
  Lista l;
  inicializa_lista(&l);
  while(scanf("%s", comando) == 1) {
    if (strcmp(comando, "insere_inicio") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      insere_inicio(&l, x);
      printf("Inserido %d no inicio.\n", x);
    }else if (strcmp(comando, "insere_fim") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      insere_fim(&l, x);
      printf("Inserido %d no fim.\n", x);
    }else if (strcmp(comando, "remove_inicio") == 0) {
      x = remove_inicio(&l);
      printf("Removido %d do inicio.\n", x);      
    }else if (strcmp(comando, "remove_fim") == 0) {
      x = remove_fim(&l);
      printf("Removido %d do fim.\n", x);      
    }else if (strcmp(comando, "remove_ocorrencias") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      conta = remove_ocorrencias(&l, x);
      printf("Removidas %d ocorrencias de %d.\n", conta, x);      
    }
    else if (strcmp(comando, "busca") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      posicao = busca(l, x);
      if (posicao == -1) {
	printf("Valor %d nao encontrado na lista.\n", x);
      }else {
	printf("Valor %d encontrado na posicao %d.\n", x, posicao);            
      }
    }else if (strcmp(comando, "libera") == 0){
      desaloca_lista(&l);
      printf("\nLiberado");
    }
    else if (strcmp(comando, "imprime") == 0) {
      imprime(l);
    }
    else {
      printf("Comando invalido.\n");
      return 2;
    }
  }
}