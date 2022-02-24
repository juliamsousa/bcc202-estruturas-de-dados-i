#include <iostream>
#include <ctime>
#include <time.h>
#include "geraVetor.hpp"
#include "shellquick.hpp"
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
	
	int op;
	
	cout<<"Digite a opcao desejada"<<endl;
	cout<<"1 - Shell Sort"<<endl;
	cout<<"2 - Quick Sort"<<endl;
	cout<<"0 - Sair do menu"<<endl;
	cin>>op;
	
	do
	{
		switch (op)
		{
			
			case 1: 
			{	
				cout<<"* Shell Sort *"<<endl;
	
				
				vetorAleatorio = geraVetorAleatorio(tamanho);
				vetorCrescente = geraVetorCrescente(tamanho);
				vetorDecrescente = geraVetorDecrescente(tamanho);
				
				shellSort(vetorAleatorio, tamanho, comp, trades, tempo);
				cout<<"* Vetor Aleatorio *"<<endl;
				imprimeVetor(tamanho, vetorAleatorio);
				cout<<endl;
				cout<<"COMPARACOES: "<<*comp<<endl;
				cout<<"TROCAS: "<<*trades<<endl;
				cout<<"TEMPO: "<<*tempo<<endl;
				
				shellSort(vetorCrescente, tamanho, comp, trades, tempo);
				cout<<"* Vetor Crescente *"<<endl;
				imprimeVetor(tamanho, vetorCrescente);
				cout<<endl;
				cout<<"COMPARACOES: "<<*comp<<endl;
				cout<<"TROCAS: "<<*trades<<endl;
				cout<<"TEMPO: "<<*tempo<<endl;
				
				shellSort(vetorDecrescente, tamanho, comp, trades, tempo);
				cout<<"* Vetor Decrescente *"<<endl;
				imprimeVetor(tamanho, vetorDecrescente);
				cout<<endl;
				cout<<"COMPARACOES: "<<*comp<<endl;
				cout<<"TROCAS: "<<*trades<<endl;
				cout<<"TEMPO: "<<*tempo<<endl;
			}
			break;
			
			case 2: 
			{	
				cout<<"* Quick Sort *"<<endl;
	
				
				vetorAleatorio = geraVetorAleatorio(tamanho);
				vetorCrescente = geraVetorCrescente(tamanho);
				vetorDecrescente = geraVetorDecrescente(tamanho);
				
				quickSort(vetorAleatorio, tamanho, comp, trades, tempo);
				cout<<"* Vetor Aleatorio *"<<endl;
				imprimeVetor(tamanho, vetorAleatorio);
				cout<<endl;
				cout<<"COMPARACOES: "<<*comp<<endl;
				cout<<"TROCAS: "<<*trades<<endl;
				cout<<"TEMPO: "<<*tempo<<endl;
				
				quickSort(vetorCrescente, tamanho, comp, trades, tempo);
				cout<<"* Vetor Crescente *"<<endl;
				imprimeVetor(tamanho, vetorCrescente);
				cout<<endl;
				cout<<"COMPARACOES: "<<*comp<<endl;
				cout<<"TROCAS: "<<*trades<<endl;
				cout<<"TEMPO: "<<*tempo<<endl;
				
				quickSort(vetorDecrescente, tamanho, comp, trades, tempo);
				cout<<"* Vetor Decrescente *"<<endl;
				imprimeVetor(tamanho, vetorDecrescente);
				cout<<endl;
				cout<<"COMPARACOES: "<<*comp<<endl;
				cout<<"TROCAS: "<<*trades<<endl;
				cout<<"TEMPO: "<<*tempo<<endl;
			}
			break;
		}
		
		cout<<"Digite a opcao desejada"<<endl;
		cout<<"1 - Shell Sort"<<endl;
		cout<<"2 - Quick Sort"<<endl;
		cout<<"0 - Sair do menu"<<endl;
		cin>>op;
		
	} while (op!=0);
	
	desalocaVetor(vetorAleatorio);
	desalocaVetor(vetorCrescente);
	desalocaVetor(vetorDecrescente);
	
	return 0;
	
}
