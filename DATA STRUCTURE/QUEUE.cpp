#include <iostream>
using  namespace std;

#define tam 10
int primeiro, ultimo, itens, valor;

//EMPTY LIST
void criar_fila(int *vetor)
{
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = 0;
    }
    primeiro = -1;
    ultimo = -1;
    itens = 0;
}

int fila_cheia()
{
    return (itens == tam);
}

//ADD TO QUEUE
void inserir_fila(int *vetor)
{
    if (!fila_cheia())
    {
        if (primeiro == -1)
        {
            primeiro = 0;
        }
        if(ultimo == tam-1)
        {
            ultimo = 0;
        }
        ultimo++;
        vetor[ultimo] = valor;
        itens++;
    }
    else
    {
        printf("LISTA CHEIA");
    }
}

//SHOW
void exibir_fila(int *vetor)
{
    for(int i = (tam-1); i >-1;i--)
    {
        printf("\n Elemento = %d: Valor %d",i, vetor[i]);

        if(i == primeiro)   
        {  
            printf(" PRIMEIRO");  
        }
        else    
        {   
            printf(" ULTIMO"); 
        }
    }
  printf("----------------------------");
  system("pause");
}

//REMOVE
int remover_fila(int *vetor)
{
      int retorno;

      retorno = vetor[primeiro];
      vetor[primeiro] = 0;
      primeiro++;
      if(primeiro == tam)
      {
            primeiro = 0;
      }
      itens--;
      return retorno;
}

int main()
{
      int vetor[tam];
      int tecla;

      criar_fila(vetor);

      while (tecla != 9)
      {
            system("cls");
            
            printf("\nEscolha: \n1 = Incluir na fila\n2 = Tirar da fila \n3 = Listar fila \n9 = Fim\n");
            scanf("%d", &tecla);
            
            if (tecla == 1)
            {
                  printf("Digite um valor:");
                  scanf("%d", &valor);
                  inserir_fila(vetor);
            }
            else if (tecla == 2)
            {
                printf("\n REMOVIDO O VALOR %d", remover_fila(vetor));
            }
            else if(tecla == 3)
            {
                exibir_fila(vetor);
            }
            else if (tecla == 9)
            {
                printf("\n FIM");
                break;
            }
      }
}
