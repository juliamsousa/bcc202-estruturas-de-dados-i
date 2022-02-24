#include <iostream>
#include "alunotad.hpp"
#include "professortad.hpp"
#include "disciplinatad.hpp"
using namespace std;

int main ()
{
	int op; 
	int talunos = 0; 
	int tprofessor = 0; 
	int tdisciplina = 0;
	
	Taluno** aluno = new Taluno*;
	Tprofessor** professor = new Tprofessor*;
	Tdisciplina** disciplina = new Tdisciplina*;
	
	cout<<"**MENU DE ACESSO**"<<endl;
	cout<<"1 - Aluno"<<endl;
	cout<<"2 - Professor"<<endl;
	cout<<"3 - Disciplina"<<endl;
	cout<<"0 - Sair do programa"<<endl;
			
	cin>>op;
	
	while (op != 0)
	{
		switch (op)
		{
			case 1: 
			{
				int t;
				
				do
				{
					cout<<"**Opcao aluno**"<<endl;
					cout<<"1 - Cadastrar alunos"<<endl;
					cout<<"2 - Alterar dados"<<endl;
					cout<<"3 - Acessar dados"<<endl;
					cout<<"4 - Imprimir dados na tela"<<endl;
					cout<<"0 - Sair do menu aluno"<<endl<<endl;
				
					cin>>t;
				
					switch (t)
					{
						case 1:
						{
							int dia, mes, ano;
							long double cpf;
							long int matricula;
							char nome [50];
							char curso [30];
						
							cout<<"**Cadastro de alunos**"<<endl;
							cout<<"Digite o numero de alunos a serem cadastrados: "<<endl;
							cin>>talunos;
						
							for (int i=0; i<talunos; i++)
							{
								cout<<"Digite o nome do aluno: "<<i+1<<endl;
								cin>>nome;
								cout<<"Digite o CPF do aluno: "<<i+1<<endl;
								cin>>cpf;
								cout<<"Digite a matricula do aluno: "<<i+1<<endl;
								cin>>matricula;
								cout<<"Digite o curso do aluno: "<<i+1<<endl;
								cin>>curso;
								cout<<"Digite a data de ingresso (dia/mes/ano): "<<endl;
								cin>>dia>>mes>>ano;
							
								aluno[i] = criarAluno(cpf, nome, matricula, curso, dia, mes, ano);
							
								cout<<"Aluno "<<i+1<<" cadastrado com sucesso!"<<endl<<endl;
							}
						}
						break;
					
						case 2:
						{
							int a;
						
							cout<<"**Alterar dados**"<<endl;
							cout<<"21 - Alterar o CPF "<<endl;
							cout<<"22 - Alterar o nome"<<endl;
							cout<<"23 - Alterar a matricula"<<endl;
							cout<<"24 - Alterar o curso"<<endl;
							cout<<"25 - Alterar a data de ingresso"<<endl;
						
							cin>>a;
						
							switch (a)
							{
								case 21:
								{
									int n;
									long double cpf;
								
									cout<<"Digite a posicao do aluno desejado: "<<endl;
									cin>>n;
									cout<<"Digite o CPF: "<<endl;
									cin>>cpf;
								
									inserirCPFAluno(aluno[n-1], cpf);
								}
								break;
								
								case 22:
								{
									int n;
									char nome[50];
								
									cout<<"Digite a posicao do aluno desejado: "<<endl;
									cin>>n;
									cout<<"Digite o nome: "<<endl;
									cin>>nome;
								
									inserirNomeAluno(aluno[n-1], nome);
								}
								break;
							
								case 23:
								{
									int n;
									long int matricula;
										
									cout<<"Digite a posicao do aluno desejado: "<<endl;
									cin>>n;
									cout<<"Digite a matricula: "<<endl;
									cin>>matricula;
								
									inserirMatriculaAluno(aluno[n-1], matricula);
								}
								break;
							
								case 24:
								{
									int n;
									char curso [30];
									
									cout<<"Digite a posicao do aluno desejado: "<<endl;
									cin>>n;
									cout<<"Digite o curso: "<<endl;
									cin>>curso;
									
									inserirCursoAluno(aluno[n-1], curso);
								}
								break;
							
								case 25:
								{
									int dd, mm, yy, n;
									
									cout<<"Digite a posicao do aluno desejado: "<<endl;
									cin>>n;
									cout<<"Digite a data de ingresso (dia/mes/ano): "<<endl;
									cin>>dd, mm, yy;
									
									inserirDataAluno(aluno[n-1], dd, mm, yy);
								}
							}
						}
						break;
					
						case 3: 
						{
							int b;
							
							cout<<"**Acesso a dados**"<<endl;;
							cout<<"31 - Acessar o CPF "<<endl;
							cout<<"32 - Acessar o nome"<<endl;
							cout<<"33 - Acessar a matricula"<<endl;
							cout<<"34 - Acessar o curso"<<endl;
							cout<<"35 - Acesar a data de ingresso"<<endl;
							
							cin>>b;
							
							switch (b)
							{
								case 31:
								{
									int n;
									
									cout<<"Digite a posicao do aluno desejado: "<<endl;
									cin>>n;
									
									cout<<"CPF: "<<acessarCPFAluno (aluno[n-1])<<endl;
								}
								break;
								
								case 32:
								{
									char nome [50];
									int n;
									
									cout<<"Digite a posicao do aluno desejado: "<<endl;
									cin>>n;
									
									acessarNomeAluno (aluno[n-1], nome);
									
									cout<<"Nome: "<<nome<<endl;	
								}
								break;
								
								case 33:
								{
									int n;
									
									cout<<"Digite a posicao do aluno desejado: "<<endl;
									cin>>n;
									
									cout<<"Matricula: "<<acessarMatriculaAluno(aluno[n-1])<<endl;	
								}		
								break;
								
								case 34:
								{
									int n;
									char curso[30];
									
									cout<<"Digite a poscicao do aluno desejado: "<<endl;
									cin>>n;
									
									acessarCursoAluno (aluno[n-1], curso);
									
									cout<<"Curso: "<<curso<<endl;
								}
								break;
								
								case 35:
								{
									int n, d, m, a;
									
									cout<<"Digite a posicao do aluno desejado: "<<endl;
									cin>>n;
									
									acessarDataAluno (aluno[n-1], &d, &m, &a);
									
									cout<<"Data de ingresso: "<<d<<"/"<<m<<"/"<<a<<endl;
								}
								break;
							}		
						}
						break;
					
						case 4: 
						{
							int c;
							
							cout<<"**Imprimir dados**"<<endl;
							cout<<"41 - Imprimir os dados de um aluno"<<endl;
							cout<<"42 - Imprimir os dados de todos os alunos"<<endl;	
							
							cin>>c;
							
							switch (c)
							{
								case 41:
								{
									int n;
									
									cout<<"Digite a posicao do aluno desejado: "<<endl;
									cin>>n;
									
									imprimirAluno(aluno[n-1]);
								}
								break;
								
								case 42:
								{	
									for (int i=0; i<talunos; i++)
									{
										imprimirAluno(aluno[i]);
										cout<<endl<<endl;
									}
								}
								break;
							}
						}
						break;	
					}	
				}while (t != 0);
			}
			break;
			
			case 2:
			{
				int t;
				
				do 
				{
					cout<<"**Opcao professor**"<<endl;
					cout<<"1 - Cadastrar professores"<<endl;
					cout<<"2 - Alterar dados"<<endl;
					cout<<"3 - Acessar dados"<<endl;
					cout<<"4 - Imprimir dados na tela"<<endl;
					cout<<"0 - Sair do menu professor"<<endl<<endl;
					
					cin>>t;
				
					switch (t)
					{
						case 1:
						{
							long double cpf;
							char nome [50];
							char departamento [30];
							
							cout<<"**Cadastro de professores**"<<endl;
							cout<<"Digite o numero de professores a serem cadastrados: "<<endl;
							cin>>tprofessor;
							
							for (int i=0; i<tprofessor; i++)
							{
								cout<<"Digite o nome do professor: "<<i+1<<endl;
								cin>>nome;
								cout<<"Digite o CPF do professor: "<<i+1<<endl;
								cin>>cpf;
								cout<<"Digite o departamento do professor: "<<i+1<<endl;
								cin>>departamento;
								
								professor[i] = criarProfessor (cpf, nome, departamento);
								
								cout<<"Professor "<<i+1<<" cadastrado com sucesso!"<<endl;
							}
						}
						break;
						
						case 2:
						{
							int a;
							
							cout<<"**Alterar dados**"<<endl;
							cout<<"21 - Alterar o CPF "<<endl;
							cout<<"22 - Alterar o nome"<<endl;
							cout<<"23 - Alterar o departamento"<<endl;
						
							cin>>a;
							
							switch (a)
							{
								case 21:
								{
									int n;
									long double cpf;
									
									cout<<"Digite a posicao do professor desejado:"<<endl;
									cin>>n;
									cout<<"Digite o CPF: "<<endl;
									cin>>cpf;
									
									inserirCPFProfessor(professor[n-1], cpf);
								}
								break;
								
								case 22:
								{
									int n;
									char nome [50];
									
									cout<<"Digite a posicao do professor desejado: "<<endl;
									cin>>n;
									cout<<"Digite o nome: "<<endl;
									cin>>nome;
									
									inserirNomeProfessor(professor[n-1], nome);
								}
								break;
								
								case 23:
								{
									int n;
									char departamento [30];
									
									cout<<"Digite a posicao do professor desejado: "<<endl;
									cin>>n;
									cout<<"Digite o departamento: "<<endl;
									cin>>departamento;
									
									inserirDepartamento(professor[n-1], departamento);
								}
								break;
							}
						}
						break;
						
						case 3:
						{
							int x;
							
							cout<<"**Acesso a dados**"<<endl;
							cout<<"31 - Acessar o CPF "<<endl;
							cout<<"32 - Acessar o nome"<<endl;
							cout<<"33 - Acessar o departamento"<<endl;
							
							cin>>x;
							
							switch(x)
							{
								case 31:
								{
									int n;
									
									cout<<"Digite a posicao do professor desejado: "<<endl;
									cin>>n;
									
									cout<<"CPF: "<<acessarCPFProfessor(professor[n-1])<<endl;
								}
								break;
								
								case 32:
								{
									char nome [50];
									int n;
									
									cout<<"Digite a posicao do professor desejado: "<<endl;
									cin>>n;
									
									acessarNomeProfessor (professor[n-1], nome);
									
									cout<<"Nome: "<<nome<<endl;	
									
								}
								break;
								
								case 33:
								{
									char departamento [30];
									int n;
									
									cout<<"Digite a posicao do professor desejado: "<<endl;
									cin>>n;
									
									acessarDepartamento (professor[n-1], departamento);
									
									cout<<"Departamento: "<<departamento<<endl;	
								}
								break;
							}
						}
						break;
						
						case 4:
						{
							int z;
							
							cout<<"**Imprimir dados**"<<endl;
							cout<<"41 - Imprimir os dados de um professor"<<endl;
							cout<<"42 - Imprimir os dados de todos os professores"<<endl;	
							
							cin>>z;
							
							switch (z)
							{
								case 41:
								{
									int n;
									
									cout<<"Digite a posicao do professor desejado: "<<endl;
									cin>>n;
									
									imprimirProfessor(professor[n-1]);
								}
								break;
								
								case 42:
								{	
									for (int i=0; i<tprofessor; i++)
									{
										imprimirProfessor(professor[i]);
										cout<<endl<<endl;
									}
								}
								break;
							}
						}
						break;
					}
				} while (t != 0);
			}
			break;
			
			case 3:
			{
				int t;
				
				do
				{
					cout<<"**Opcao disciplina**"<<endl;
					cout<<"1 - Cadastrar disciplinas"<<endl;
					cout<<"2 - Alterar dados"<<endl;
					cout<<"3 - Acessar dados"<<endl;
					cout<<"4 - Imprimir dados na tela"<<endl;
					cout<<"0 - Sair do menu disciplina"<<endl<<endl;
					
					cin>>t;
					
					switch (t)
					{
						case 1:
						{
							char nome [30];
							char codigo [15];
							int ch;
							char curso [30];
							int sala;
							
							cout<<"**Cadastro de disciplinas**"<<endl;
							cout<<"Digite o numero de disciplinas a serem cadastradas: "<<endl;
							cin>>tdisciplina;
						
							for (int i=0; i<tdisciplina; i++)
							{
								cout<<"Digite o nome da disciplina: "<<i+1<<endl;
								cin>>nome;
								cout<<"Digite o codigo da disciplina: "<<i+1<<endl;
								cin>>codigo;
								cout<<"Digite a carga horaria: "<<i+1<<endl;
								cin>>ch;
								cout<<"Digite o curso da disciplina: "<<i+1<<endl;
								cin>>curso;
								cout<<"Digite a sala da disciplina: "<<i+1<<endl;
								cin>>sala;
								
								disciplina[i] = criarDisciplina(nome, codigo, ch, curso, sala);
								
								cout<<"Disciplina "<<i+1<<" cadastrada com sucesso!"<<endl<<endl;
							}
						}
						break;
						
						case 2:
						{
							int u;
							
							cout<<"**Alterar dados**"<<endl;
							cout<<"21 - Alterar o nome "<<endl;
							cout<<"22 - Alterar o codigo"<<endl;
							cout<<"23 - Alterar a carga horaria"<<endl;
							cout<<"24 - Alterar o curso"<<endl;
							cout<<"25 - Alterar a sala"<<endl;
							
							cin>>u;
							
							switch (u)
							{
								case 21:
								{
									int n;
									char nome [30];
									
									cout<<"Digite a posicao da disciplina desejada:"<<endl;
									cin>>n;
									cout<<"Digite o nome: "<<endl;
									cin>>nome;
									
									inserirNomeDisciplina(disciplina[n-1], nome);
								}
								break;
								
								case 22:
								{
									int n;
									char codigo [15];
									
									cout<<"Digite a posicao da disciplina desejada:"<<endl;
									cin>>n;
									cout<<"Digite o codigo: "<<endl;
									cin>>codigo;
									
									inserirCodigo(disciplina[n-1], codigo);
								}
								break;
								
								case 23:
								{
									int n;
									int carga;
									
									cout<<"Digite a posicao da disciplina desejada:"<<endl;
									cin>>n;
									cout<<"Digite a carga horaria: "<<endl;
									cin>>carga;
									
									inserirCH(disciplina[n-1], carga);
								}
								break;
								
								case 24:
								{
									int n;
									char curso [30];
									
									cout<<"Digite a posicao da disciplina desejada:"<<endl;
									cin>>n;
									cout<<"Digite o curso: "<<endl;
									cin>>curso;
									
									inserirCurso(disciplina[n-1], curso);
								}
								break;
								
								case 25:
								{
									int n;
									int numero;
									
									cout<<"Digite a posicao da disciplina desejada:"<<endl;
									cin>>n;
									cout<<"Digite o numero da sala: "<<endl;
									cin>>numero;
									
									inserirSala(disciplina[n-1], numero);
								}
								break;
							}
						}
						break;
						
						case 3:
						{
							int v;
							
							cout<<"**Acesso a dados**"<<endl;
							cout<<"31 - Acessar o nome "<<endl;
							cout<<"32 - Acessar o codigo"<<endl;
							cout<<"33 - Acessar a carga horaria"<<endl;
							cout<<"34 - Acessar o curso"<<endl;
							cout<<"35 - Acessar a sala"<<endl;
							
							cin>>v;
							
							switch (v)
							{
								case 31:
								{
									char nome [30];
									int n;
									
									cout<<"Digite a posicao da disciplina desejada: "<<endl;
									cin>>n;
									
									acessarNomeDisciplina (disciplina[n-1], nome);
									
									cout<<"Nome: "<<nome<<endl;	
								}
								break;
								
								case 32:
								{
									int n;
									char code [15];
									
									cout<<"Digite a posicao da disciplina desejada: "<<endl;
									cin>>n;
									
									acessarCodigo(disciplina[n-1], code);
									
									cout<<"Codigo: "<<code<<endl;
								}
								break;
								
								case 33:
								{
									int n;
									
									cout<<"Digite a posicao da disciplina desejada: "<<endl;
									cin>>n;
									
									cout<<"Carga horaria: "<<acessarCH(disciplina[n-1])<<" h"<<endl;
								}
								break;
								
								case 34:
								{
									char curso [30];
									int n;
									
									cout<<"Digite a posicao da disciplina desejada: "<<endl;
									cin>>n;
									
									acessarCurso (disciplina[n-1], curso);
									
									cout<<"Curso: "<<curso<<endl;	
								}
								break;
								
								case 35:
								{
									int n;
									
									cout<<"Digite a posicao da disciplina desejada: "<<endl;
									cin>>n;
									
									cout<<"Sala: "<<acessarSala(disciplina[n-1])<<endl;
								}
								break;
							}	
						}
						break;
						
						case 4:
						{
							int w;
							
							cout<<"**Imprimir dados**"<<endl;
							cout<<"41 - Imprimir os dados de uma disciplina"<<endl;
							cout<<"42 - Imprimir os dados de todas as disciplinas"<<endl;	
							
							cin>>w;
							
							switch (w)
							{
								case 41:
								{
									int n;
									
									cout<<"Digite a posicao da disciplina desejada: "<<endl;
									cin>>n;
									
									imprimirDisciplina(disciplina[n-1]);
								}
								break;
								
								case 42:
								{	
									for (int i=0; i<tdisciplina; i++)
									{
										imprimirDisciplina(disciplina[i]);
										cout<<endl;
									}
								}
								break;
							}	
						}
						break;
					}
				}while (t != 0);
			} 
			break;	
		};
		
		cout<<"**MENU DE ACESSO**"<<endl;
		cout<<"1 - Aluno"<<endl;
		cout<<"2 - Professor"<<endl;
		cout<<"3 - Disciplina"<<endl;
		cout<<"0 - Sair do programa"<<endl;
				
		cin>>op;
	}
	
	if (talunos>0)
	{
		for (int i=0; i<talunos; i++)
			desalocarAluno(aluno[i]);
	
		delete aluno;
	}
	
	if (tprofessor>0)
	{
		for (int i=0; i<tprofessor; i++)
			desalocarProfessor(professor[i]);
	
		delete professor;
	}
	
	if (tdisciplina>0)
	{
		for (int i=0; i<tdisciplina; i++)
			desalocarDisciplina(disciplina[i]);
	
		delete disciplina;
	}	
	
	cout<<"**Sair do programa**"<<endl;

	return 0;
}
