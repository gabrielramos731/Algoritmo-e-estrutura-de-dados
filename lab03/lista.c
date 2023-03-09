#include<stdlib.h>
#include "polinomio.h"

/* Inicializa um polinômio vazio. */
void inicializa_polinomio(Polinomio * ap_pol){

  No *no_cab = (No*) malloc(sizeof(No));

  *ap_pol = no_cab;
  no_cab->prox = no_cab;
  no_cab->antec = no_cab;
}

/* Define que o coeficiente de grau grau do polinomio pol eh igual a coef. Deve manter os 
 * coeficientes ordenados por grau. */
void define_coeficiente(Polinomio pol, int grau, int coef){

  if(grau >= 0 && coef != 0){
    No *novo = (No*) malloc(sizeof(No));
    No *no_aux = pol->prox;

    novo->valor.coef = coef;
    novo->valor.grau = grau;

    while(novo->valor.grau > no_aux->valor.grau){
      if(no_aux->prox == pol){  // grau novo é maior que todos da lista
        novo->prox = pol;
        novo->antec = pol->antec;
        pol->antec->prox = novo;
        pol->antec = novo;
        return;
      }
      no_aux = no_aux->prox;
  }
  novo->prox = no_aux;  //encontrou um grau maior que novo.grau
  novo->antec = no_aux->antec;
  no_aux->antec->prox = novo;
  no_aux->antec = novo;
  }
}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera(Polinomio pol){

  No *no_aux = pol->antec;

  while(no_aux != pol){
    pol->antec = pol->antec->antec;
    free(no_aux);
    no_aux = pol->antec;
  }
  pol->prox = pol;
}

/* Computa a soma dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma(Polinomio res, Polinomio a, Polinomio b){

  zera(res);
  No *no_aux_a = a->prox;
  No *no_aux_b = b->prox;

  int soma_coef;
  
  while(no_aux_a != a || no_aux_b != b){
    if(no_aux_a->valor.grau == no_aux_b->valor.grau){
      soma_coef = no_aux_a->valor.coef + no_aux_b->valor.coef;
      if(soma_coef != 0)
        define_coeficiente(res, no_aux_a->valor.grau, soma_coef);
      no_aux_a = no_aux_a->prox;
      no_aux_b = no_aux_b->prox;    
    }                                                                       
    else if((no_aux_a->valor.grau < no_aux_b->valor.grau) || (no_aux_b == b && no_aux_a != a)){  // se a for no cabeça, adiciona o restante de b
      define_coeficiente(res, no_aux_a->valor.grau, no_aux_a->valor.coef);
      no_aux_a = no_aux_a->prox;
    }
    else if ((no_aux_b->valor.grau < no_aux_a->valor.grau) || (no_aux_a == a && no_aux_b != b)){ // se b for no cabeça, adiciona o restante de a
      define_coeficiente(res, no_aux_b->valor.grau, no_aux_b->valor.coef);
      no_aux_b = no_aux_b->prox;
    }
  }
}

/* Computa a subtracao dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b){  // problema no caso 3
  
  zera(res);
  No *no_aux_a = a->prox;
  No *no_aux_b = b->prox;

  int soma_coef;
  
  while(no_aux_a != a || no_aux_b != b){
    if(no_aux_a->valor.grau == no_aux_b->valor.grau){
      soma_coef = no_aux_a->valor.coef - no_aux_b->valor.coef;
      if(soma_coef != 0)
        define_coeficiente(res, no_aux_a->valor.grau, soma_coef);
      no_aux_a = no_aux_a->prox;
      no_aux_b = no_aux_b->prox;    
    }                                                                       
    else if((no_aux_a->valor.grau < no_aux_b->valor.grau) || (no_aux_b == b && no_aux_a != a)){  // se a for no cabeça, adiciona o restante de b
      define_coeficiente(res, no_aux_a->valor.grau, no_aux_a->valor.coef);
      no_aux_a = no_aux_a->prox;
    }
    else if ((no_aux_b->valor.grau < no_aux_a->valor.grau) || (no_aux_a == a && no_aux_b != b)){ // se b for no cabeça, adiciona o restante de a
      define_coeficiente(res, no_aux_b->valor.grau, no_aux_b->valor.coef);
      no_aux_b = no_aux_b->prox;
    }
  }
}

/* /\* Computa a multiplicacao dos polinomios a e b colocando o resultado em res.  */
/*  * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. *\/ */
/* void multiplica(Polinomio res, Polinomio a, Polinomio b); */

/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,-2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau 3 com valor -2 e o de
 * grau 10 com valor 5. 
 */
void imprime(Polinomio pol){

  printf("[");
  No *no_aux = pol->prox;
  while(pol != no_aux){
    printf("(%d,%d)", no_aux->valor.grau, no_aux->valor.coef);
    no_aux = no_aux->prox;
    if(no_aux != pol)
      printf(",");
  }
  printf("]\n");
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_polinomio(Polinomio *ap_pol){

  No *no_aux = (*ap_pol)->antec;

  while(no_aux != (*ap_pol)){
    (*ap_pol)->antec = (*ap_pol)->antec->antec;
    free(no_aux);
    no_aux = (*ap_pol)->antec;
  }
  free(*ap_pol);
}
