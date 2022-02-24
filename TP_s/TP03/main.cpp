#include <iostream>
#include "listaAluno.hpp"
#include "alunotad.hpp"

using namespace std;

int main ()
{
	int n;
	
	Lista* lista = criaLista();
	
	do
	{
		cout<<"Menu Inicial"<<endl;
		cout<<"1 - Inserir um aluno na lista"<<endl;
		cout<<"2 - Retirar um aluno da lista"<<endl;
		cout<<"3 - Verificar se a lista de alunos esta vazia"<<endl;
		cout<<"4 - Verificar se um aluno pertence a lista"<<endl;
		cout<<"5 - Imprimir alunos da lista"<<endl;
		cout<<"0 - Sair do menu"<<endl;
		cin>>n;
		
		switch (n)
		{
			case 1:
			{
				int v;
				
				Taluno* aluno = criarAluno();
				
				long double cpf;
				char nome [50];
				long int matricula;
				char curso [30];
				int dia, mes, ano;
				
				cout<<"Digite o cpf do aluno."<<endl;
				cin>>cpf;
				cout<<"Digite o nome do aluno."<<endl;
				cin>>nome;
				cout<<"Digite a matricula do aluno."<<endl;
				cin>>matricula;
				cout<<"Digite o curso do aluno."<<endl;
				cin>>curso;
				cout<<"Digite a data de ingresso (dd/mm//aa)."<<endl;
				cin>>dia>>mes>>ano;
				
				preencheAluno(aluno, cpf, nome, matricula, curso, dia, mes, ano);
				
				insereOrdenadoLista (lista, aluno);			
			}
			break;
			
			case 2:
			{
				long int v;
			
				cout<<"Digite a matricula do aluno a ser retirado"<<endl;
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
				
				cout<<"Digite a matricula do aluno procurado"<<endl;
				cin>>v;
				
				n = listaPertence (lista, v);
				
				if (n==1)
					cout<<"O aluno esta contido na lista"<<endl;
				else 
					cout<<"O aluno nao esta contido na lista"<<endl;
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
