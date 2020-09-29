#include <iostream>
using namespace std;

# define tamanho 10
int first, last , itens, total;

void criar_fila(int *vetor){

  for(int i = 0; i < tamanho; i++){
    vetor[i] = 0;
  }
  first = -1;
  last = -1;
  itens  = 0;
  total = 0;
}
void inserir_fila(int *vetor){
  if(total == tamanho){
    printf("FILA CHEIA AGUARDE...");
  }else{
    if(first == -1){
      itens = 1;
      first = 0;
  }else{
      itens = vetor[last] + 1;
    }
    if (last == tamanho - 1){
      last = - 1;
    }
    last++;
    vetor[last]  = itens;
    total++;
    printf("\nSENHA GERADA: %d\n", vetor[last]);
    
  }
}
void exibir_fila(int *vetor){

  for(int i = (tamanho - 1); i > - 1; i--){
   printf("\n SENHA = %d", vetor[i]);
   if (i == first){printf("PROXIMO");}
   if(i == last){printf("ULTIMO");}
 }
 printf("\n\n+++++++++++++++++++++++++++++++");
}

void chamar_proximo(int *vetor){
  int retorno;

  retorno = vetor[first];
  vetor[first] = 0;
  first++;
  if(first == tamanho-1){
    first = 0;
  }
  total--;
  printf("SENHA gerada: %d", retorno);
 
}

int main(void) {
  int vetor[tamanho], escolha;
  criar_fila(vetor);

  while(escolha != 4){
    printf("\n[1] Gerar Senha\r\n");
    printf("[2] Chamar proximo\r\n");
    printf("[3] Mostar senhas\r\n");
    printf("[4] Fim\r\n");
    scanf("%d", &escolha);
    if (escolha == 1){
      inserir_fila(vetor);
    }else if (escolha == 2){
      chamar_proximo(vetor);
    }else if(escolha == 3){
      exibir_fila(vetor);
    }
  }
}
