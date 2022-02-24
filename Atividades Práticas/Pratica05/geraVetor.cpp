#include <iostream>
#include <cstdlib>
#include "geraVetor.hpp"
using namespace std;
 
int* geraVetorAleatorio (int tamanho)
{
	int* vetor = new int [tamanho];
	
	for (int i=0; i<tamanho; i++)
		vetor[i] = rand()%1000001;
	
	return vetor;
}

int* geraVetorCrescente (int tamanho)
{
	int* vetor = new int [tamanho];	
	
	for (int i=0; i<tamanho; i++) 
		vetor[i] = i;
	
	return vetor;
}

int* geraVetorDecrescente (int tamanho)
{
	int* vetor = new int [tamanho];	
	
	for (int i=0; i<tamanho; i++) 
		vetor[i] = 1000000-i;
	
	return vetor;
}

void imprimeVetor (int size, int* vector)
{
	for (int i=0; i<size; i++) 
		cout<<vector[i]<<" ";

	cout<<endl;
}

void desalocaVetor (int* vetor)
{
	delete[] vetor;
}

