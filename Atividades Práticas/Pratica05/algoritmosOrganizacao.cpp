#include <iostream>
using namespace std;

void bubbleSort (int* vetor, int tamanho)
{
	int aux;
	int movimentos;
	
	for (int i=0; i<tamanho-1; i++)
	{
		for (int j=1; j<tamanho-i; j++)
		{
			if (vetor[j] < vetor[j-1])
			{
				aux = vetor[j];
				vetor[j] = vetor [j-1];
				vetor [j-1] = aux; 
			}
		}
	}
}

