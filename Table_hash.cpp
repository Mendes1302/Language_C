#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

#define N 127
using namespace std;


struct Aluno
{
    int RA;
    char nome[81];
    char email[41];
};

typedef Aluno* alunos[N];

int fhash(int RA)
{
    return (RA % N);
}

int buscar(alunos temp, int RA)
{
    int i = fhash(RA);
    while (temp[i] != NULL)
    {
        if (temp[i]-> RA == RA)
        {
            return i;
        }
        i = (i+1) % N;
    }
    return -1;
}

void incluir(alunos temp, int RA, char* nome, char* email)
{
    int i = fhash(RA);
    while (temp[i] != NULL)
    {
        if (temp[i]-> RA == RA)
        {
            break;
        }
        i = (i+1) % N;
    }
    if (temp[i]==NULL)
    {
        temp[i] = (Aluno*) malloc(sizeof(Aluno));
        temp[i] -> RA = RA;
    }
    //insert ou update.
    strcpy(temp[i]-> nome, nome);
    strcpy(temp[i]-> email, email);
}
int excluir (alunos temp, int RA)
{
    int i = fhash(RA);
    while (temp[i] != NULL)
    {
        if (temp[i]-> RA == RA)
        {
            temp[i] = NULL;
            return i;
            break;
        }
        i = (i+1) % N;
    }
    return -1;
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int x;
    alunos matriculados;
    for(x = 0; x<N; x++)
    {
        matriculados[x] = NULL;
    }
    int RA;
    char nome[81];
    char email[41];
    
    int escolha;
    
    while(escolha!=4)
    {
        printf("\nMENU\n1-Incluir\n2-Buscar\n3-Excluir\n4-FIM\n");
        scanf("%d", &escolha);
        if(escolha == 1)
        {
            printf("\nRA: "); scanf("%d", & RA);
            //fflush(stdin);
            
            printf("\nNOME: "); 
            scanf("%s", &nome);
            //fflush(stdin);
            
            printf("\nEmail: ");
            scanf("%s", &email);

            //fflush(stdin);
            incluir(matriculados, RA, nome, email);
        }
        else if (escolha == 2)
        {
            printf("\nRA: ");
            scanf("%d", &RA);
            x = buscar(matriculados, RA);
            if(x>=0)
            {
                printf("\nNOME: %s Email %s ", matriculados[x]->nome, matriculados[x]->email);
            }
            else
            {
                printf("RA:%d nao escontrado", RA);
            }
        }
        else if (escolha == 3)
        {
            printf("\nRA: ");
            scanf("%d", &RA);
            x = excluir(matriculados, RA);
            if(x>=0)
            {
                printf("\nRA: %d no elemento %d excluido com sucesso", RA, x);
            }
            else
            {
                printf("RA: %d nao escontrado", RA);
            }
        }
        else if (escolha == 4)
        {
            printf("FIM");
            break;
        }
        else
        {
            printf("ERRO na  ESCOLHA\n tente novamente!!!");
        }
    }
    
}
