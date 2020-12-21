#include <stdio.h>
#define alturaMaxima 225


typedef struct
{
	  int peso;
	  int altura;
} PesoAltura;

int main(void)
{
	  PesoAltura pessoal;	  
	  pessoal.peso = 80;
	  pessoal.altura = 185;
	  
	  printf("Peso = %i, Altura = %i.", pessoal.peso, pessoal.altura);
	  
	  if (pessoal.altura > alturaMaxima)
	  {
			printf(" Altura acima da MAXIMA\n");
	  }
	  else
	  {
			printf(" Altura abaixo da MAXIMA\n");
	  }
	  return 0;
}
