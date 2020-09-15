#include <iostream>
using namespace std;
void criar_pilha(int *vetor, int *topo){
  for(int i=0;i<5;i++){
    vetor[i] = 0;
  }
  *topo = -1;
}
void exibir_pilha(int *vetor, int topo){
  for(int i = 4; i>-1; i--){
    printf("\nElemento %d = Valor: %d", i, vetor[i]);
    if(i==topo){
      printf("**TOPO**");
    }
    
  }
  printf("\n==================================\n");
}
bool pilha_vazia(int topo){
  return topo < 0;
}
void empilhar(int *vetor, int *topo, int  valor){

  if(!pilha_vazia(*topo)){
    *topo = *topo + 1;
    vetor[*topo] = valor;
  }
  
}
bool pilha_cheia(int topo){
  return topo >=4;
}

void desempilhar(int *vetor, int *topo){

  if(!pilha_cheia(*topo)){
    vetor[*topo] = 0;
    *topo = *topo - 1;

  }
  
}
int main() {
  int vetor[5];
  int topo;

  
  criar_pilha(vetor, &topo);
  


  empilhar(vetor, &topo, 5);
  exibir_pilha(vetor, topo);


  empilhar(vetor, &topo, 10);
  exibir_pilha(vetor, topo);


  empilhar(vetor, &topo, 15);
  exibir_pilha(vetor, topo);


  empilhar(vetor, &topo, 20);
  exibir_pilha(vetor, topo);


  empilhar(vetor, &topo, 25);
  exibir_pilha(vetor, topo);


  desempilhar(vetor, &topo);
  exibir_pilha(vetor, topo);

}
