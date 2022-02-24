#include <iostream>
#include <cstdio>
#include <cstring>
#include "buscaBinaria.hpp"
using namespace std;

int buscaBinariaRecursiva (int* vetor, int esquerda, int direita, int numero)
{
	if (direita>=1)
	{
		int meio = esquerda+(direita-esquerda)/2; //calcula o meio a cada recursao 
		
		if (vetor[meio] == numero) //compara com o elemento do meio do vetor
			return meio;
		
		if (vetor[meio]>numero) //compara se o numero se encontra a equerda do elemento do meio
			return buscaBinariaRecursiva (vetor, esquerda, meio-1, numero);
			
			return buscaBinariaRecursiva (vetor, meio+1, direita, numero);  
	}
	
	return -1;
}

int buscaBinariaIterativa (int* vetor, int esquerda, int direita, int numero)
{
	while (esquerda<=direita)
	{
		int meio = esquerda + (direita-esquerda)/2;
		
		if (vetor[meio] == numero)
			return meio;
		
		if (vetor[meio]<numero)
			esquerda = meio+1;
		else 
			direita = meio-1;
	}
	
	return -1;
}
