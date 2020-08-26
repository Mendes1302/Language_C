
#include <stdlib.h>
#include <stdio.h>
// Listas encadeadas
struct node
{
  int nData;
  struct node *pLink;
};

void display( struct node *p)
{

  printf("Mostrando a lista: \n");
  if(p)
  { 
    do
    {
      printf("%d", p ->nData);
      p = p->pLink;
    }
    while(p);
  } else{
    printf("Lista vazia");
  }
}
int main(void)
{

  struct node *pNode1 = NULL;
  struct node *pNode2 = NULL;
  struct node *pNode3 = NULL;

  pNode1 = (struct node*) malloc(sizeof(struct node*));
  pNode1->nData = 100;

  pNode2 = (struct node*) malloc(sizeof(struct node*));
  pNode2->nData = 200;

  pNode3 = (struct node*) malloc(sizeof(struct node*));
  pNode3->nData = 300;

    
  pNode1->pLink = pNode2;
  pNode2->pLink = pNode3;
  pNode3->pLink = NULL;

  display(pNode1);
  return 0;

}
