#include <iostream>
#include "geraVetor.hpp"
#include "algoritmosOrdenacao.hpp"
#define tamanhoVetor 100
using namespace std;

int main ()
{
	int* vetorCrescente;
	int* vetorDecrescente;
	int* vetorAleatorio;
	
	int op;
	
	cout<<"Digite a opcao desejada"<<endl;
	cout<<"1 - Bubble Sort"<<endl;
	cout<<"2 - Selection Sort"<<endl;
	cout<<"3 - Insertion Sort"<<endl;
	cout<<"4 - Merge Sort"<<endl;
	cout<<"5 - Shell Sort"<<endl;
	cout<<"6 - Quick Sort"<<endl;
	cout<<"0 - Sair do menu"<<endl;
	cin>>op;
	
	do
	{
		switch (op)
		{
			case 1: 
			{	
				cout<<"* Bubble Sort *"<<endl;
			
				vetorAleatorio = geraVetorAleatorio(tamanho);
				vetorCrescente = geraVetorCrescente(tamanho);
				vetorDecrescente = geraVetorDecrescente(tamanho);
				
				bubbleSort(vetorAleatorio, tamanho);
				cout<<"* Vetor aleatorio *"<<endl;
				imprimeVetor(tamanho, vetorAleatorio);
		
				bubbleSort(vetorCrescente, tamanho);
				cout<<"* Vetor crescente *"<<endl;
				imprimeVetor(tamanho, vetorCrescente);
		
				bubbleSort(vetorDecrescente, tamanho);
				cout<<"* Vetor decrescente *"<<endl;
				imprimeVetor(tamanho, vetorDecrescente);
			}
			break;
			
			case 2:
			{	
				cout<<"* Selection Sort *"<<endl;
			
				
				vetorAleatorio = geraVetorAleatorio(tamanho);
				vetorCrescente = geraVetorCrescente(tamanho);
				vetorDecrescente = geraVetorDecrescente(tamanho);
				
				selectionSort(vetorAleatorio, tamanho);
				selectionSort(vetorCrescente, tamanho);
				selectionSort(vetorDecrescente, tamanho);
				
				imprimeVetor(tamanho, vetorAleatorio);
				cout<<endl;
				imprimeVetor(tamanho, vetorCrescente);
				cout<<endl;
				imprimeVetor(tamanho, vetorDecrescente);
				cout<<endl;
			}
			break;
			
			case 3: 
			{	
				cout<<"* Insertion Sort *"<<endl;
	
				
				vetorAleatorio = geraVetorAleatorio(tamanho);
				vetorCrescente = geraVetorCrescente(tamanho);
				vetorDecrescente = geraVetorDecrescente(tamanho);
				
				insertionSort(vetorAleatorio, tamanho);
				insertionSort(vetorCrescente, tamanho);
				insertionSort(vetorDecrescente, tamanho);
				
				imprimeVetor(tamanho, vetorAleatorio);
				cout<<endl;
				imprimeVetor(tamanho, vetorCrescente);
				cout<<endl;
				imprimeVetor(tamanho, vetorDecrescente);
				cout<<endl;
			}
			break;
			
			case 4:
			{	
				cout<<"* Merge Sort *"<<endl;
				
				int t;
				
				cout<<"Digite a opcao desejada"<<endl;
				cout<<"1 - Forma recursiva"<<endl;
				cout<<"2 - Forma iterativa"<<endl;
				cin>>t;
				
				switch (t)
				{
					case 1:
					{
						cout<<"* Forma Iterativa"<<endl;
						
						vetorAleatorio = geraVetorAleatorio(tamanho);
						vetorCrescente = geraVetorCrescente(tamanho);
						vetorDecrescente = geraVetorDecrescente(tamanho);
						
						mergeSortIterativo(vetorAleatorio, tamanho);
						mergeSortIterativo(vetorCrescente, tamanho);
						mergeSortIterativo(vetorDecrescente, tamanho);
						
						imprimeVetor(tamanho, vetorAleatorio);
						cout<<endl;
						imprimeVetor(tamanho, vetorCrescente);
						cout<<endl;
						imprimeVetor(tamanho, vetorDecrescente);
						cout<<endl;
					}
					break;
					
					case 2:
					{
						cout<<"* Forma Recursiva"<<endl;
						
						vetorAleatorio = geraVetorAleatorio(tamanho);
						vetorCrescente = geraVetorCrescente(tamanho);
						vetorDecrescente = geraVetorDecrescente(tamanho);
						
						mergeSortRecursivo(vetorAleatorio, tamanho);
						mergeSortRecursivo(vetorCrescente, tamanho);
						mergeSortRecursivo(vetorDecrescente, tamanho);
						
						imprimeVetor(tamanho, vetorAleatorio);
						cout<<endl;
						imprimeVetor(tamanho, vetorCrescente);
						cout<<endl;
						imprimeVetor(tamanho, vetorDecrescente);
						cout<<endl;
					}
					break;
				}
			}
			break;
			
			case 5: 
			{	
				cout<<"* Shell Sort *"<<endl;
	
				
				vetorAleatorio = geraVetorAleatorio(tamanho);
				vetorCrescente = geraVetorCrescente(tamanho);
				vetorDecrescente = geraVetorDecrescente(tamanho);
				
				shellSort(vetorAleatorio, tamanho);
				shellSort(vetorCrescente, tamanho);
				shellSort(vetorDecrescente, tamanho);
				
				imprimeVetor(tamanho, vetorAleatorio);
				cout<<endl;
				imprimeVetor(tamanho, vetorCrescente);
				cout<<endl;
				imprimeVetor(tamanho, vetorDecrescente);
				cout<<endl;
			}
			break;
			
			case 6: 
			{	
				cout<<"* Quick Sort *"<<endl;
	
				
				vetorAleatorio = geraVetorAleatorio(tamanho);
				vetorCrescente = geraVetorCrescente(tamanho);
				vetorDecrescente = geraVetorDecrescente(tamanho);
				
				quickSort(vetorAleatorio, tamanho);
				quickSort(vetorCrescente, tamanho);
				quickSort(vetorDecrescente, tamanho);
				
				imprimeVetor(tamanho, vetorAleatorio);
				cout<<endl;
				imprimeVetor(tamanho, vetorCrescente);
				cout<<endl;
				imprimeVetor(tamanho, vetorDecrescente);
				cout<<endl;
			}
			break;
			
			cout<<"Digite a opcao desejada"<<endl;
			cout<<"1 - Bubble Sort"<<endl;
			cout<<"2 - Selection Sort"<<endl;
			cout<<"3 - Insertion Sort"<<endl;
			cout<<"4 - Merge Sort"<<endl;
			cout<<"5 - Shell Sort"<<endl;
			cout<<"6 - Quick Sort"<<endl;
			cout<<"0 - Sair do menu"<<endl;
			cin>>op;
		}
	} while (op!=0);
	
	desalocaVetor(vetorAleatorio);
	desalocaVetor(vetorCrescente);
	desalocaVetor(vetorDecrescente);
	
	return 0;
	
}
