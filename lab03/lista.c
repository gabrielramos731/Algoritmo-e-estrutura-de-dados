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

    if(no_aux == pol){  //caso a lista esteja vazia  OK
      novo->prox = pol;
      novo->antec = pol->antec;
      pol->antec->prox = novo;
      pol->antec = novo;
    }
    else{  // caso não esteja vazia
      while(novo->valor.grau > no_aux->valor.grau){

        // grau novo é maior que todos da lista
        if(no_aux->prox == pol){  // insere no fim OK
          novo->prox = pol;
          novo->antec = pol->antec;
          pol->antec->prox = novo;
          pol->antec = novo;
          return;
        }
        no_aux = no_aux->prox;
    }
    novo->prox = no_aux;
    novo->antec = no_aux->antec;
    no_aux->antec->prox = novo;
    no_aux->antec = novo;
    }
  }
  else  //condição não atendida coef ou grau
    return;
}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera(Polinomio pol){

}

/* Computa a soma dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma(Polinomio res, Polinomio a, Polinomio b){

}

/* Computa a subtracao dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b){

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
  printf("]");
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_polinomio(Polinomio *ap_pol){

}
