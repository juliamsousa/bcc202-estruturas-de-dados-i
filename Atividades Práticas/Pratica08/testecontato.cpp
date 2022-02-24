#include <iostream>
#include "Tcontato.hpp"
#include "arvoreBusca.hpp"
using namespace std;

int main ()
{
	arvNo* arv = criaNoArvore ();
	
	int op;
	
	do	
	{	
		cout<<"** REGISTRO DE CONTATOS **"<<endl;
		cout<<"1 - Cadastrar um contato"<<endl;
		cout<<"2 - Buscar um contato"<<endl;
		cout<<"3 - Remover um contato"<<endl;
		cout<<"4 - Imprimir a lista de contatos"<<endl;
		cout<<"5 - Apagar a lista de contatos"<<endl;
		
		cin>>op;
		
		switch (op)
		{
			case 1:
			{
				string nome;
				int dia, mes, ano;
				long int tel;
				Tcontato* pessoa = criaContato ();
				arvNo* no = criaNoArvore ();
				
				cout<<"Digite o nome do contato"<<endl;
				cin>>nome;
				cout<<"Digite o numero de telefone do contato"<<endl;
				cin>>tel;
				cout<<"Digite a data de aniversario do contato (dd/mm/aa)"<<endl;
				cin>>dia>>mes>>ano;
				
				preencheContato (pessoa, nome, tel, dia, mes, ano);
				
				preencheNoArvore (no, pessoa);
				
				arv = arvNoInsere (arv, no);
			} break;
			
			case 2:
			{
				string nome;
				Tcontato* pessoa;
				cout<<"Digite o nome do contato que deseja buscar"<<endl;
				
				pessoa = retornaInfo(buscaNoArv (arv, nome));
				imprimirContato (pessoa);
			} break;
			
			case 3:
			{
				string nome;
				Tcontato* pessoa;
				
				cout<<"Digite o nome do contato que deseja apagar"<<endl;
				cin>>nome;
				
				pessoa = retornaInfo (buscaNoArv (arv, nome));
				
				arvNoRetira (arv, pessoa);
			} break;
			
			case 4:
			{
				int a;
				
				cout<<"Escolha a forma de impressao"<<endl;
				cout<<"1 - Pre-Ordem"<<endl;
				cout<<"2 - Pos-Ordem"<<endl;
				cout<<"3 - Caminhamento Central"<<endl;
				
				switch (a)
				{
					case 1:
					{
						preOrdem (arv);
					} break;
					
					case 2:
					{
						posOrdem (arv);
					} break;
					
					case 3:
					{
						caminhaCentral (arv);
					}
				}
			} break;
		}
		
	} while (op != 0);
	
	return 0;
}
