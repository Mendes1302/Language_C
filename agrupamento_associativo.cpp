#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>


using namespace std;

int main()
{
    int escolha;
    string nome, fone;
    
    setlocale(LC_ALL, "Portuguese");
    map<string, string> agenda;
    map<string, string>::iterator i;
    
    while(1)
    {
        printf("\n\nEscolha:\n1-inserir\n2-buscar\n3-listar\n4-sair\n");
        scanf("%d", &escolha);
        if(escolha == 1)
        {
            printf("Nome:");
            cin >> nome;
            
            
            printf("Telefone:");
            cin >> fone;
            //dicionario[nome]=fone; ou
            agenda.insert(make_pair(nome, fone));
        }
        else if(escolha == 2)
        {
            printf("BUSCAR\n");
            printf("NOME:");
            cin >> nome;
            i = agenda.find(nome);
            if(i != agenda.end())
            {
                cout << endl << "fone: " << (*i).second << endl;
            }
            else
            {
                cout << endl << "NÃO ENCONTRADO" << endl;
            }
        }
        else if(escolha == 3)
        {
            printf("LISTAGEM\n\n");
            i = agenda.begin();
            while(i != agenda.end())
            {
                cout << (*i).first << ":" << (*i).second << endl;
                i++;
            }
        }
        else if(escolha == 4)
        {
            printf("FIM");
            break;
        }
        else
        {
            printf("ERROR, tente novamente!!!");
        }
    }
    
    /*
    dicionario.insert(make_pair("quatro", "four"));*/
    
    
    
    
    
    

    return 0;
}
