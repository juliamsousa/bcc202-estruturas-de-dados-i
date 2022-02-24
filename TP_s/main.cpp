#include "lista.hpp"
#include <iostream>
using namespace std;
int main (){
	int op, v, aux=0;
	Lista* lista;
	lista= lista_criar();
	do{
		cout<<"\nMENU DE ACESSO \n1.Inserir \n2.Inserir Ordenado \n3.Retirar \n4.Verificar \n5.Imprimir \n0. Sair"<<endl;
		cin>>op;
		switch (op){
			case 1:
				cout<<"\nValor que deseja inserir: ";
				cin>>v;
				lista_inserir (lista,v);
				break;
			case 2:
				cout<<"\nValor que deseja inserir: ";
				cin>>v;
				lista_insere_ordenado (lista,v);
				break;
			case 3:
				cout<<"\nDigite o valor que deseja retirar: ";
				cin>>v;
				lista_retirar (lista,v);
				break;	
			case 4:
				cout<<"\nDeseja o valor que deseja verificar> ";
				cin>>v;
				aux= lista_pertence (lista,v);
				if (aux==1)
					cout<<"\nPertecem a lista"<<endl;
				else
					cout<<"\nNão pertecem a lista"<<endl;
				break;
				
			case 5:
				lista_imprime (lista);
				break;
			
		}
	}while (op!=0);
return 0;
}
