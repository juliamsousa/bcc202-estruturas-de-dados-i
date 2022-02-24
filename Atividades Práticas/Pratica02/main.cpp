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
	char ab;
	
	do
	{	
		cout<<"**Menu inicial**"<<endl;
		cout<<"A - Atestado de matricula"<<endl;
		cout<<"B - Encargo didatico"<<endl;
		cout<<"C - Exponenciacao"<<endl;
		cin>>op;
		
		switch (op)
		{
			case 'A':
			{
				int u;
				
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
						
						case 1: 
						{		
							cout<<"**Criar atestado**"<<endl;
							cout<<"Digite o numero de disciplinas a serem cadastradas"<<endl;
							cin>>n;
							
							atestado = criarAtestado(n);
							
							preencheAtestado (atestado, n);	
						}
						break;
						
						case 2:
						{
							int p;
							
							cout<<"**Acesso a dados**"<<endl;
							cout<<"1 - Dados aluno"<<endl;
							cout<<"2 - Dados disciplinas"<<endl;
							cin>>p;
							
							switch (p)
							{
								case 1:
								{
									alterarAluno (atestado);
								} 
								break;
								
								case 2:
								{
									alterarDisciplinaAtestado (atestado);
								}
								break;
							}
						}
						break;
						
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
						
						case 1: 
						{
							
							
							cout<<"**Criar encargo**"<<endl;
							cout<<"Digite o numero de disciplinas a serem cadastradas"<<endl;
							cin>>n;
							
							encargo = criarEncargo(n);
							
							preencheEncargo (encargo, n);	
						}
						break;
						
						case 2:
						{
							int p;
							
							cout<<"**Acesso a dados**"<<endl;
							cout<<"1 - Dados professor"<<endl;
							cout<<"2 - Dados disciplinas"<<endl;
							cin>>p;
							
							switch (p)
							{
								case 1:
								{
									alterarProfessor (encargo);
								} 
								break;
								
								case 2:
								{
									alterarDisciplinaEncargo (encargo);
								}
								break;
							}
						}
						break;
						
						case 3:
						{
							imprimirEncargo(encargo, n);
						}
						break;
					}
				}while (u != 0);
			}	
			break;
			
			case 'C':
			{
				int x, n;
				
				cout<<"**Exponenciacao**"<<endl;
				cout<<"Digite os valores de x e n"<<endl;
				cin>>x>>n;	
				
				cout<<exponenciacaoRecursiva (x, n);
			}
			break;
		}
	}while (op == 'A' || op == 'B' || op == 'C');

	return 0;
} 
