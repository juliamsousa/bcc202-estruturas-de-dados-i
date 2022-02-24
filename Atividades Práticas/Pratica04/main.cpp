#include <iostream>
#include "lista.hpp"

using namespace std;

int main ()
{
	int n;
	
	Lista* lista = criaLista();
	
	do
	{
		cout<<"Menu Inicial"<<endl;
		cout<<"1 - Inserir elementos na lista"<<endl;
		cout<<"2 - Retirar elementos da lista"<<endl;
		cout<<"3 - Verificar se a lista esta vazia"<<endl;
		cout<<"4 - Verificar se um item pertence a lista"<<endl;
		cout<<"5 - Imprimir elementos da lista"<<endl;
		cout<<"0 - Sair do menu"<<endl;
		cin>>n;
		
		switch (n)
		{
			case 1:
			{
				int v;
				
				cout<<"Digite o inteiro desejado"<<endl;
				cin>>v;
				
				insereOrdenadoLista(lista, v);			
			}
			break;
			
			case 2:
			{
				int v;
			
				cout<<"Digite o elemento a ser retirado"<<endl;
				cin>>v;
				
				retiraLista (lista, v);
			}
			break;
			
			case 3:
			{
				int n;
				
				n = listaVazia (lista);
				
				if (n==1)
					cout<<"A lista esta vazia"<<endl;
				else
					cout<<"A lista nao esta vazia"<<endl;	
			}
			break;
			
			case 4:
			{
				int v, n;
				
				cout<<"Digite o inteiro desejado"<<endl;
				cin>>v;
				
				n = listaPertence (lista, v);
				
				if (n==1)
					cout<<"O item esta contido na lista"<<endl;
				else 
					cout<<"O item nao esta contido na lista"<<endl;
			}
			break;
			
			case 5:
			{
				if (listaVazia(lista) == 0)
					listaImprime (lista);
				else
					cout<<"A lista esta vazia"<<endl;
			}
		}
	} while (n!=0);

	return 0;
}
