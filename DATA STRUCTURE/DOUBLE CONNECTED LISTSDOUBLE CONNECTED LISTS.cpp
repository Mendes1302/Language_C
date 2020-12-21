#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Contatinho 
{	
    char nome [40];
    char whatsapp[20];
    struct Contatinho * anterior;
    struct Contatinho * proximo;
} contatos;

contatos* inserir(contatos *recebido)
{
    char nome[40];
    char whatsapp[20];

    system("cls");
    printf("\nDigite um nome:");
    scanf(" %[^\n]s", &nome);

    printf("\nDigite um whatsapp:");
    scanf(" %[^\n]s", &whatsapp);//  %[^\n]s nao zoar string

    contatos *novo;
    novo = (contatos *)malloc(sizeof(contatos));
    
    strcpy( novo->nome, nome);
    strcpy( novo->whatsapp, whatsapp);
    
    novo->anterior = NULL;
    novo->proximo = recebido;
    
    if(recebido != NULL)
    {
        recebido->anterior = novo;
    }
	
    recebido = novo;
    return recebido;

}
contatos* inserirPosicao(contatos *recebido)
{	
	char nome[40];
	char whatsapp[20];
	
	int posicao;
	int contador = 1;
	
	contatos *p = recebido;
	contatos *temp;

	system("cls");
	printf("\nDigite um nome:");
	scanf(" %[^\n]s", &nome);

	printf("\nDigite um whatsapp:");
	scanf(" %[^\n]s", &whatsapp);

	printf("\nDigite a pocicao:");
	scanf("%d", &posicao);

	while(contador != posicao)
	{
		p = p->proximo;
		contador++;
	}

	temp = (contatos *)malloc(sizeof(contatos));
	temp = p->proximo;

	contatos *novo;
	novo = (contatos *)malloc(sizeof(contatos));

	strcpy( novo->nome, nome);
	strcpy( novo->whatsapp, whatsapp);

	novo->anterior = p;
	novo->proximo = temp;

	temp->anterior = novo;
	p->proximo = novo;
	return recebido;

}
contatos* inserirfinal(contatos *recebido)
{
	char nome[40];
	char whatsapp[20];

	int posicao;
	int contador = 1;

	contatos *p = recebido;
	contatos *temp;


	system("cls");
	
	printf("\nDigite um nome:");
	scanf(" %[^\n]s", &nome);
	printf("\nDigite um whatsapp:");
	scanf(" %[^\n]s", &whatsapp);

	while( p->proximo != NULL)
	{
		p = p->proximo;
		contador++;
	}

	contatos *novo;
	novo = (contatos *)malloc(sizeof(contatos));
	
	strcpy( novo->nome, nome);
	strcpy( novo->whatsapp, whatsapp);
	
	novo->anterior = p;
	novo->proximo = NULL;
	
	p->proximo = novo;

	return recebido;
}



void listar(contatos *recebido)
{
	if(recebido != NULL)
	{
		printf("\nNome: %s ==> Whatsapp: %s\n", recebido->nome, recebido->whatsapp);
		listar(recebido->proximo);
	}
}

contatos* excluir(contatos *recebido)
{

	  system("cls");
	  char nome[40];
	  
	  contatos* ant =  NULL;
	  contatos* p = recebido;

	  system("cls");
	  printf("\nDigite um nome para excluir:");
	  scanf(" %[^\n]s", &nome);

	  while( p!=NULL && strcmp(p->nome, nome) != 0)
	  {
			ant = p;
			p = p->proximo;
	  }
	  if(p!=NULL)
	  {	
			if(ant==NULL)
			{
			 	recebido = p-> proximo;
			}
			else
			{
			 	p->anterior->proximo = p->proximo;
			}
			if(p->proximo =NULL){
			 	p->proximo->anterior = p->anterior;
			}
	  }
}

int main(void) 
{
	  contatos * meusContatos;
	  meusContatos = (contatos *) malloc(sizeof(struct Contatinho));
	  meusContatos = NULL;
	  meusContatos = inserir(meusContatos);
	  meusContatos = inserir(meusContatos);
	  
	  listar(meusContatos);
	  getch();

	  meusContatos = inserirPosicao(meusContatos);
	  listar(meusContatos);
	  getch();

	  meusContatos = inserirfinal(meusContatos);
	  listar(meusContatos);
	  getch();

	  meusContatos = excluir(meusContatos);
	  listar(meusContatos);
	  getch();

	  return 0;
}
