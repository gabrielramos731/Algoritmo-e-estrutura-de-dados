#include<stdio.h>

int soma_divisores(int a) {

  int soma = 0;
  for(int i=1; i<=(a/2); i++){
    if(a % i == 0){
      soma+=i;
    }
  }
  return soma;

}

/** Define se a e b sao amigos. Dois inteiros sao amigos se a soma de
    todos os divisores próprios de um é igual ao outro e vice-versa.
    Exemplos: (220, 284), (1184, 1210), (2620, 2924).
    Retorna 0 se a e b nao sao amigos e 
    qualquer outro valor se a e b sao amigos. 
*/
int amigos(int a, int b) {

  if((soma_divisores(a) == b) && (soma_divisores(b) == a))
    return 1;
  else
    return 0;
}

int main() {

  int a, b;
  scanf("%d %d", &a, &b);

  if(amigos(a, b) == 1)
    printf("amigos\n");
  else
    printf("nao amigos\n");

  return 0;
}
