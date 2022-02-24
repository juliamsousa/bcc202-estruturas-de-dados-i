#include <iostream>
#include <cstring>
#include <cstdio>
#include "funcoesrecursivas.hpp"
#inclde "imprimenaturais.hpp"
#include "funcoesElementoVetor.hpp"
#include "buscaBinaria.hpp"
using namespace std;

int main ()
{
	int op;
	
	do
	{
		cout<<"**Menu Geral**"<<endl;
		cout<<"0 - Sair"<<endl;
		cout<<"1 - Calculo potenciacao"<<endl;
		cout<<"2 - Inverter numero"<<endl;
		cout<<"3 - Converter decimal para binario"<<endl;
		cout<<"4 - Retornar menor elemento de um vetor"<<endl;
		cout<<"5 - Imprimir n numeros naturais"<<endl;
		cout<<"6 - Busca binaria"<<endl;
		cout<<"\nDigite a operacao desejada "<<endl;
		cin>>op;
		
		switch (op)
		{
			case 1:
				{
					int x, y;
					
					cout<<"Digite a base e o expoente"<<endl;
					cin>>x>>y;
					
					cout<<x<<"^"<<y<<calculaPotenciacao (x, y)<<endl;
				}
				break;
				
				case 2:
				{
					int n;
					
					cout<<"Digite o numero que se deseja inverter"<<endl;
					cin>>n;
					
					inverteNumero(n)<<endl;
				}
				break;
				
				case 3:
				{
					int n;
					
					cout<<"Digite o numero que se deseja converter para base binaria"<<endl;
					cin>>n;
					
					cout<<converteBinario (n)<<endl;
				}
				
				case 4:
				{
					int n;
					
					cout<<"Digite o tamanho do vetor"<<endl;
					cin>>n;
					
					int* vetor = new int [n];
					
					for (int i=0; i<n; i++)
					{
						cout<<"Digite o elemento do vetor "<<endl;
						cin>>vetor[i];
					}
					
					cout<<"Na forma iterativa: "<<endl;
					cout<<"Menor elemento: "<<menorElementoIterativo(vetor, n)<<endl;
					
					cout<<"Na forma recursiva"<<endl;
					cout<<"Menor elemento: "<<menorElementoRecursiva (vetor, n)<<endl;
				}
				break;
				
				case 5:
				{
					int n;
					
					cout<<"Digite o valor de n: "<<endl;
					cin>>n;
					
					cout<<"Na forma iterativa: "<<endl;
					imprimeNaturaisIterativa (n);
					cout<<endl;
					
					cout<<"na forma recursiva: "<<endl;
					imprimeNaturaisRecursiva(n);
					cout<<endl;
				}
				break;
				
				case 6:
				{
					int n, numero;
					
					cout<<"Digite o tamanho do vetor: "<<endl;
					cin>>n;
					
					int* vetor = new int[n];
					
					for (int i=0; i<n; i++)
					{
						cout<<"Digtie o elemento do vetor"<<endl;
						cin>>vetor[i];
					}
					
					cout<<"Digite o elemento a ser encontrado"<<endl;
					cin>>numero;
					
					
				}
		}
	
	} while (op != 0);
}
