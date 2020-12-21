#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

struct Pratos
{
    string nome;
    string ingredientes;
};

int main()
{
    int i = 0, chave, opcao = 0;
    char desc[15], ingr[50];
    
    map<int, Pratos>MapaPratos;
    Pratos receita;
    
    do
    {
        printf("\nSelecione:\n1-ADD\n2-LIST\n3-REMOVE\n4-END\n");
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 1:
                printf("Nome do prato:");
                scanf("%s", &desc);
				
                printf("\nIngredientes:");
                scanf("%s", &ingr);
				
                receita.nome = desc;
                receita.ingredientes = ingr;
                MapaPratos[(MapaPratos.size()+1)] = receita;
                opcao = 0;
				
                break;
            case 2:
                for(i=1; i <= MapaPratos.size(); i++)
                {
                    if(MapaPratos.find(i)!=MapaPratos.end())
                    {
                        cout << "\n***PRATO" << i << ": " << MapaPratos[i].nome;
                        cout << "\n***PRATO" << i << ": " <<  MapaPratos[i].ingredientes << endl;
                    }
                }
                opcao = 0;
                break;
            case 3:
                printf("\nNumero do prato para remover:");
                scanf("%d", &chave);
				
                if(MapaPratos.find(chave)==MapaPratos.end())
                {
                    printf("\nPrato nao existe\n");
                }
                else
                {
                    MapaPratos.erase(MapaPratos.find(chave));
                    printf("\nREMOVIDO COM SUCESSO!!\n");
                    
                }
				
                opcao = 0;
                break;
            default:
                break;
        
        }
    } while (opcao!=4);
    return 0;
}
