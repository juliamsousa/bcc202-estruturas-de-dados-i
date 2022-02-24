#include <iostream>
#include "atestadotad.hpp"
#include "alunotad.hpp"
#include "disciplinatad.hpp"
#include "encargotad.hpp"
#include "professortad.hpp"
#include "exponenciacaoRecursiva.hpp"
using namespace std;

int main ()
{
	Tatestado* atestado;
	Tencargo* encargo;
	char op;
	
	//repeticao para o menu inicial
	do
	{	
		cout<<"\n**Menu inicial**"<<endl;
		cout<<"A - Atestado de matricula"<<endl;
		cout<<"B - Encargo didatico"<<endl;
		cout<<"C - Exponenciacao"<<endl;
		cin>>op;
		
		switch (op)
		{
			case 'A':
			{
				int u;
				
				//opcao para manipular um atestado de matricula
				do
				{
					cout<<"**Atestado de Matricula**"<<endl;
					cout<<"1 - Criar novo atestado"<<endl;
					cout<<"2 - Acesso a dados"<<endl;
					cout<<"3 - Imprimir Atestado de matricula"<<endl;
					cout<<"0 - Sair do memu Atestado de Matricula"<<endl;
					cin>>u;
					
					switch (u)
					{
						int n;
						
						//opcao para criar um atestado
						case 1: 
						{		
							cout<<"**Criar atestado**"<<endl;
							cout<<"Digite o numero de disciplinas a serem cadastradas"<<endl;
							cin>>n;
							
							//funcao para alocar o atestado dinamicamente
							atestado = criarAtestado(n);
							
							//funcao para preencher os dados do atestado
							preencheAtestado (atestado, n);	
						}
						break;
						
						//opcao para acessar dados de um atestado
						case 2:
						{
							int p;
							
							cout<<"**Acesso a dados**"<<endl;
							cout<<"1 - Dados aluno"<<endl;
							cout<<"2 - Dados disciplinas"<<endl;
							cin>>p;
							
							switch (p)
							{
								//opcao para acessar dados de um aluno
								case 1:
								{
									alterarAluno (atestado);
								} 
								break;
								
								//opcao para alterar dados de disciplinas
								case 2:
								{
									alterarDisciplinaAtestado (atestado);
								}
								break;
							}
						}
						break;
						
						//opcao para imprimir os dados de um atestado
						case 3:
						{
							imprimirAtestado(atestado, n);
						}
					}
				}while (u != 0);
			}
			break;
			
			case 'B':
			{
				int u;
				
				//opcao para manipular um atestado de matricula
				do
				{
					cout<<"**Encargo Didatico**"<<endl;
					cout<<"1 - Criar novo encargo"<<endl;
					cout<<"2 - Acesso a dados"<<endl;
					cout<<"3 - Imprimir o encargo didatico"<<endl;
					cout<<"0 - Sair do menu Encargo Didatico"<<endl;
					cin>>u;
					
				
					switch (u)
					{
						int n;
						
						//opcao para criar um encargo didatico
						case 1: 
						{
							cout<<"**Criar encargo**"<<endl;
							cout<<"Digite o numero de disciplinas a serem cadastradas"<<endl;
							cin>>n;
							
							//funcao para alocar um atestado dinamicamente
							encargo = criarEncargo(n);
							
							//funcao para preenceher o encargo
							preencheEncargo (encargo, n);	
						}
						break;
						
						//opcao para acessar dados de um encargo
						case 2:
						{
							int p;
							
							cout<<"**Acesso a dados**"<<endl;
							cout<<"1 - Dados professor"<<endl;
							cout<<"2 - Dados disciplinas"<<endl;
							cin>>p;
							
							switch (p)
							{
								//opcao para acessar dados de um professor
								case 1:
								{
									alterarProfessor (encargo);
								} 
								break;
								
								//opcao para acessar dados de disciplinas
								case 2:
								{
									alterarDisciplinaEncargo (encargo);
								}
								break;
							}
						}
						break;
						
						//opcao para imprimir os dados de um encargo
						case 3:
						{
							imprimirEncargo(encargo, n);
						}
						break;
					}
				}while (u != 0);
			}	
			break;
			
			//opcao para realizar exponencial
			case 'C':
			{
				int x, n;
				
				cout<<"**Exponenciacao**"<<endl;
				cout<<"Digite os valores de x e n"<<endl;
				cin>>x>>n;	
				
				//chamada da funcao que realiza a exponenciacao
				cout<<exponenciacaoRecursiva (x, n)<<endl;
			}
			break;
		}
	}while (op == 'A' || op == 'B' || op == 'C');

	return 0;
} 
