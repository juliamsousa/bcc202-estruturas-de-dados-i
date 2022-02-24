#include <iostream>
#include <ctime>
#include <time.h>
#include "geraVetor.hpp"
#include "heapsort.hpp"
#define tamanho 100
using namespace std;

int main ()
{
	int* vetorCrescente;
	int* vetorDecrescente;
	int* vetorAleatorio;
	int* comp;
	int* trades;
	double* tempo;
	
	*comp = 0;
	*trades = 0;
	
	vetorAleatorio = geraVetorAleatorio (tamanho);
	vetorCrescente = geraVetorCrescente (tamanho);
	vetorDecrescente = geraVetorDecrescente (tamanho);
	
	heapSort (vetorCrescente, tamanho, comp, trades, tempo);
	imprimeVetor (tamanho, vetorCrescente);
	cout<<"TROCAS: "<<*trades<<endl;
	cout<<"COMPARACOES: "<<*comp<<endl;
	cout<<"TEMPO: "<<*tempo<<endl;
	cout<<endl;
		
	heapSort (vetorDecrescente, tamanho, comp, trades, tempo);
	imprimeVetor (tamanho, vetorDecrescente);
	cout<<"TROCAS: "<<*trades<<endl;
	cout<<"COMPARACOES: "<<*comp<<endl;
	cout<<"TEMPO: "<<*tempo<<endl;
	cout<<endl;
	
	heapSort (vetorAleatorio, tamanho, comp, trades, tempo);
	imprimeVetor (tamanho, vetorAleatorio);
	cout<<"TROCAS: "<<*trades<<endl;
	cout<<"COMPARACOES: "<<*comp<<endl;
	cout<<"TEMPO: "<<*tempo<<endl;
	cout<<endl;
		
	desalocaVetor(vetorAleatorio);
	desalocaVetor(vetorCrescente);
	desalocaVetor(vetorDecrescente);
	
	return 0;
}
