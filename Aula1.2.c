#include <stdio.h>
#include <stdlib.h>
typedef struct celulaLista{
  int inform;
  struct celulaLista * proxima;
}celula;

int main(void) {
  int opcao = 0;
  celula *pLista;
  //funçoes:
  void initLista(celula **pRecebido);
  void inserirLista(celula **pRecebido);
  void listarLista(celula **pRecebido);
  void ExcluirLista(celula **pRecebido);

  pLista = (celula *)malloc(sizeof(struct celulaLista));

  //inicializar a lista:
  initLista(&pLista);

  for(;;){
    printf("\n1 - Inserir");
    printf("\n2 - Listar");
    printf("\n3 - Excluir");
    printf("\n4 - Sair\n");
    scanf("%d", &opcao);
    switch (opcao){
      case 1:
        inserirLista(&pLista);
        break;
      case 2:
        listarLista(&pLista);
        break;
      case 3:
        ExcluirLista(&pLista);
        break;
      case 4:
        exit(0);
    }
  }
  return 0;
}
void initLista(celula **pRecebido){
  (*pRecebido)->proxima = NULL;
}
void inserirLista(celula **pRecebido){
  celula * temporaria;
  int valor;

  printf("\nDigite um valor:");
  scanf("%d", &valor);
  temporaria = (celula *)malloc(sizeof(celula));
  temporaria->inform = valor;
  //de traz para frente
  temporaria->proxima = (*pRecebido)->proxima;
  (*pRecebido)->proxima = temporaria;
}
void listarLista(celula **pRecebido){
  celula * temporaria;
  int valor;

  if((*pRecebido)->proxima == NULL){
    printf("SEM VALORES NA LISTA\n");
  }else{
    temporaria = (celula *)malloc(sizeof(celula));
    temporaria = (*pRecebido)->proxima;
    while(temporaria != NULL){
      printf("VALOR: %d\n", temporaria->inform);
      temporaria = temporaria->proxima;
    }
  }
}
void ExcluirLista(celula **pRecebido){
  celula * temporaria;

  if((*pRecebido)->proxima == NULL){
    printf("SEM VALORES NA LISTA\n");
  }else{
    temporaria = (*pRecebido)->proxima;
    (*pRecebido)->proxima = temporaria->proxima;
    free(temporaria);
  }
}
