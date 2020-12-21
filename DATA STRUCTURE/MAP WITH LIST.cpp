#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

struct Car
{
    string nome;
    string placa;
};

int main()
{
    int i = 0, chave, opcao = 0;
    char nome[50], placa[25];
    
    map<int, Car>Carros;
    Car CARROS;

    do
    {
        printf("\nSelecione:\n1-ADD\n2-LIST\n3-REMOVE\n4-END\n");
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 1:
                printf("Nome do cliente:");
                scanf("%s", &nome);
			
                printf("\nPlaca:");
                scanf("%s", &placa);
			
                CARROS.nome = nome;
                CARROS.placa = placa;
                Carros[(Carros.size()+1)] = CARROS;
			
                opcao = 0;
                break;
            case 2:
                for(i=1; i <= Carros.size(); i++)
                {
                    if(Carros.find(i)!=Carros.end())
                    {
                        cout << "\n***CLIENTE" << ": " << Carros[i].nome;
                        cout << "\n***PLACA" << ": " <<  Carros[i].placa << endl;
                    }
                }
                opcao = 0;
                break;
				
            case 3:
                printf("\nNumero da placa para remover:");
                scanf("%s", &placa);
			
                for(i=1; i <= Carros.size(); i++)
                {
                    if(Carros.find(i)!=Carros.end())
                    {
                        if(Carros[i].placa==placa) 
			{
                        	Carros.erase(Carros.find(i));
                        	printf("\nREMOVIDO COM SUCESSO!!\n");
			}
                    }
                }
				
                opcao = 0;
                break;
        }
    } while (opcao!=4);
    return 0;
}
