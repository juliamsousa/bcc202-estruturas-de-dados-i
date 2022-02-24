#include <iostream>
#include <cstring>
#include <iomanip>
#include "alunotad.hpp"
#include "disciplinatad.hpp"
#include "atestadotad.hpp"
using namespace std;

//definicao dos campos da struct atestado
struct atestado 
{
	Taluno* aluno;
	
	Tdisciplina** disciplinas;
	
	int horasAula;
};

//funcao para alocar dinamicamente um tipo atestado
Tatestado* criarAtestado (int n)
{
	Tatestado* aux = new Tatestado;
	
	//chamada da funcao para alocar dinamicamente um tipo aluno
	aux->aluno = criarAluno();
	
	aux->disciplinas = new Tdisciplina*;
	
	//funcao para alocar disciplina é chamada para cada disciplina contida no atestado
	for (int i=0; i<n; i++)
		aux->disciplinas[i] = criarDisciplina();

	return aux;
}

//funcao para desalocar um tipo atestado
void desalocarAtestado (Tatestado* atestado, int n)
{
	desalocarAluno(atestado->aluno);
	
	for (int i=0; i<n; i++)
		desalocarDisciplina(atestado->disciplinas[i]);
		
	delete [] atestado->disciplinas;
		
	delete atestado;
}

//funcao para preencher os campos de um tipo atestado aluno/conjunto de disciplinas
void preencheAtestado (Tatestado* atestado, int n)
{
	int ch=0;
	long double cpf;
	long int matricula;
	int carga, sala, dd, mm, yy;
	char nome [30];
	char codigo [15];
	char curso [30];
	
	cout<<"Digite o nome do aluno: "<<endl;
	cin>>nome;
	cout<<"Digite o CPF do aluno: "<<endl;
	cin>>cpf;
	cout<<"Digite a matricula do aluno: "<<endl;
	cin>>matricula;
	cout<<"Digite o curso do aluno: "<<endl;
	cin>>curso;
	cout<<"Digite a data de ingresso (dia/mes/ano): "<<endl;
	cin>>dd>>mm>>yy;
	
	
	//chamada da funcao para preencher os dados do aluno
	preencheAluno(atestado->aluno, cpf, nome, matricula, curso, dd, mm, yy);
	
	for (int i=0; i<n; i++)
	{
		//comparacao para verificar se as horas aula permitidas estao sendo ultrapassadas
		if (ch<=28)
		{
			cout<<"Digite o nome da disciplina."<<endl;
			cin>>nome;
			cout<<"Digite o codigo da disciplina."<<endl;
			cin>>codigo;
			cout<<"Digite o curso da disciplina."<<endl;
			cin>>curso;
			cout<<"Digite a carga horaria da disciplina."<<endl;
			cin>>carga;
			cout<<"Digite a sala da disciplina."<<endl;
			cin>>sala;
			
			//chamada da funcao para preencher cada disciplina contida no atestado 
			preencheDisciplina(atestado->disciplinas[i], nome, codigo, carga, curso, sala);		
			
			//calculo das horas-aula do aluno
			ch+=acessarCH(atestado->disciplinas[i]);
		}
		else 
			cout<<"Horas permitidas atingidas."<<endl;
	}
	
	atestado->horasAula = ch;
}

//funcao para alterar/acessar os dados de um aluno contido em um atestado
void alterarAluno (Tatestado* atestado)
{
	int t, talunos;

	do 
	{
		cout<<"**Opcao aluno**"<<endl;
		cout<<"1 - Alterar dados"<<endl;
		cout<<"2 - Acessar dados"<<endl;
		cout<<"0 - Sair do menu aluno"<<endl<<endl;
	
		cin>>t;
	
		switch (t) 
		{
			//opcao para alterar dados do aluno contido no atestado
			case 1: 
			{
				int a;
	
				cout<<"**Alterar dados**"<<endl;
				cout<<"11 - Alterar o CPF "<<endl;
				cout<<"12 - Alterar o nome"<<endl;
				cout<<"13 - Alterar a matricula"<<endl;
				cout<<"14 - Alterar o curso"<<endl;
				cout<<"15 - Alterar a data de ingresso"<<endl;
	
				cin>>a;
	
				switch (a) 
				{
					//opcao para alterar o cpf do aluno contido no atestado
					case 11: 
					{
						long double cpf;

						cout<<"Digite o CPF: "<<endl;
						cin>>cpf;
	
						inserirCPFAluno(atestado->aluno, cpf);
					}
					break;
					
					//opcao para alterar o nome do aluno contido no atestado
					case 12: 
					{
						char nome[50];

						cout<<"Digite o nome: "<<endl;
						cin>>nome;
	
						inserirNomeAluno(atestado->aluno, nome);
					}
					break;
					
					//opcao para alterar a matricula do aluno contido no atestado
					case 13: 
					{
						long int matricula;
						
						cout<<"Digite a matricula: "<<endl;
						cin>>matricula;
	
						inserirMatriculaAluno(atestado->aluno, matricula);
					}
					break;
	
					//funcao para alterar o curso do aluno contido no atestado
					case 14: 
					{
						char curso [30];

						cout<<"Digite o curso: "<<endl;
						cin>>curso;
	
						inserirCursoAluno(atestado->aluno, curso);
					}
					break;
					
					//opcao para alterar a data de ingresso do aluno contido no atestado
					case 15: 
					{
						int dd, mm, yy;
	
						cout<<"Digite a data de ingresso (dia/mes/ano): "<<endl;
						cin>>dd, mm, yy;
	
						inserirDataAluno(atestado->aluno, dd, mm, yy);
					}
				}
			}
			break;
			
			//opcao para acessar daados do aluno contido no atestado
			case 2:
			{
				int b;
	
				cout<<"**Acesso a dados**"<<endl;;
				cout<<"21 - Acessar o CPF "<<endl;
				cout<<"22 - Acessar o nome"<<endl;
				cout<<"23 - Acessar a matricula"<<endl;
				cout<<"24 - Acessar o curso"<<endl;
				cout<<"25 - Acesar a data de ingresso"<<endl;
	
				cin>>b;
	
				switch (b) 
				{
					//opcao para ler o cpf do aluno contido no atestado
					case 21: 
					{
						int n;

						cout<<"CPF: "<<acessarCPFAluno(atestado->aluno)<<endl;
					}
					break;
					
					//opcao para ler o nome do aluno contido no atestado
					case 22: 
					{
						char nome [50];
					
						acessarNomeAluno (atestado->aluno, nome);
	
						cout<<"Nome: "<<nome<<endl;
					}
					break;
					
					//opcao para ler o humero de matricula do aluno contido o atesatdo
					case 23: 
					{
						cout<<"Matricula: "<<acessarMatriculaAluno(atestado->aluno)<<endl;
					}
					break;
					
					//opcao para ler o curso do aluno contido no atestado
					case 24: 
					{
						char curso[30];
	
						acessarCursoAluno (atestado->aluno, curso);
	
						cout<<"Curso: "<<curso<<endl;
					}
					break;
	
					//opcao para ler a data de ingresso do aluno contido no atesatdo
					case 25: 
					{
						int n, d, m, a;

						acessarDataAluno (atestado->aluno, &d, &m, &a);
	
						cout<<"Data de ingresso: "<<d<<"/"<<m<<"/"<<a<<endl;
					}
					break;
				}
			}
			break;
		}
	} while (t != 0);
}

//funcao para alterar/acessar dados do conjunto de disciplinas contidas no atestado
void alterarDisciplinaAtestado (Tatestado* atestado)
{
	int t, tdisciplina;
	
	do 
	{
		cout<<"**Opcao disciplina**"<<endl;
		cout<<"1 - Alterar dados"<<endl;
		cout<<"2 - Acessar dados"<<endl;
		cout<<"0 - Sair do menu disciplina"<<endl<<endl;
	
		cin>>t;
	
		switch (t) 
		{
			//opcao para alterar dados das disciplinas contidas no atestado
			case 1: 
			{
				int u;
	
				cout<<"**Alterar dados**"<<endl;
				cout<<"11 - Alterar o nome "<<endl;
				cout<<"12 - Alterar o codigo"<<endl;
				cout<<"13 - Alterar a carga horaria"<<endl;
				cout<<"14 - Alterar o curso"<<endl;
				cout<<"15 - Alterar a sala"<<endl;
	
				cin>>u;
	
				switch (u) 
				{
					//opcao para alterar o nome de uma disciplina contida no atestado
					case 11: 
					{
						int n;
						char nome [30];
	
						cout<<"Digite a posicao da disciplina desejada:"<<endl;
						cin>>n;
						cout<<"Digite o nome: "<<endl;
						cin>>nome;
	
						inserirNomeDisciplina(atestado->disciplinas[n-1], nome);
					}
					break;
					
					//opcao para alterar o codigo de uma disciplina contida no atestado
					case 12: 
					{
						int n;
						char codigo [15];
	
						cout<<"Digite a posicao da disciplina desejada:"<<endl;
						cin>>n;
						cout<<"Digite o codigo: "<<endl;
						cin>>codigo;
	
						inserirCodigo(atestado->disciplinas[n-1], codigo);
					}
					break;
					
					//opcao para alterar a carga horaria de uma disciplina contida no atestado
					case 13: 
					{
						int n;
						int carga;
	
						cout<<"Digite a posicao da disciplina desejada:"<<endl;
						cin>>n;
						cout<<"Digite a carga horaria: "<<endl;
						cin>>carga;
	
						inserirCH(atestado->disciplinas[n-1], carga);
					}
					break;
					
					//opcao para alterar o curso de uma disciplina contida no atestado
					case 14: 
					{
						int n;
						char curso [30];
	
						cout<<"Digite a posicao da disciplina desejada:"<<endl;
						cin>>n;
						cout<<"Digite o curso: "<<endl;
						cin>>curso;
	
						inserirCurso(atestado->disciplinas[n-1], curso);
					}
					break;
	
					//opcao para alterar a sala em que a disciplina contida no atestado é oferecida 
					case 15: 
					{
						int n;
						int numero;
	
						cout<<"Digite a posicao da disciplina desejada:"<<endl;
						cin>>n;
						cout<<"Digite o numero da sala: "<<endl;
						cin>>numero;
	
						inserirSala(atestado->disciplinas[n-1], numero);
					}
					break;
				}
			}
			break;
			
			//opcao para acessar dados das dsciplinas contidas no atestado
			case 2: 
			{
				int v;
	
				cout<<"**Acesso a dados**"<<endl;
				cout<<"21 - Acessar o nome "<<endl;
				cout<<"22 - Acessar o codigo"<<endl;
				cout<<"23 - Acessar a carga horaria"<<endl;
				cout<<"24 - Acessar o curso"<<endl;
				cout<<"25 - Acessar a sala"<<endl;
	
				cin>>v;
	
				switch (v) 
				{
					//opcao para ler o nome de uma disciplina
					case 21: 
					{
						char nome [30];
						int n;
	
						cout<<"Digite a posicao da disciplina desejada: "<<endl;
						cin>>n;
	
						acessarNomeDisciplina (atestado->disciplinas[n-1], nome);
	
						cout<<"Nome: "<<nome<<endl;
					}
					break;
					
					//opcao para ler o codigo de uma disciplina contida no atestado
					case 22: 
					{
						int n;
						char code [15];
	
						cout<<"Digite a posicao da disciplina desejada: "<<endl;
						cin>>n;
	
						acessarCodigo(atestado->disciplinas[n-1], code);
	
						cout<<"Codigo: "<<code<<endl;
					}
					break;
	
					//opcao para ler a carga horaria de uma disciplina contida no atestado
					case 23: 
					{
						int n;
	
						cout<<"Digite a posicao da disciplina desejada: "<<endl;
						cin>>n;
	
						cout<<"Carga horaria: "<<acessarCH(atestado->disciplinas[n-1])<<" h"<<endl;
					}
					break;
					
					//opcao para ler o curso de uma disciplina contida no atestado
					case 24: 
					{
						char curso [30];
						int n;
	
						cout<<"Digite a posicao da disciplina desejada: "<<endl;
						cin>>n;
	
						acessarCurso (atestado->disciplinas[n-1], curso);
	
						cout<<"Curso: "<<curso<<endl;
					}
					break;
					
					//opcao para ler a sala em que uma disciplina contida no atestado sera ofertada
					case 25: 
					{
						int n;
	
						cout<<"Digite a posicao da disciplina desejada: "<<endl;
						cin>>n;
	
						cout<<"Sala: "<<acessarSala(atestado->disciplinas[n-1])<<endl;
					}
					break;
				}
			}
			break;
		}
	} while (t != 0);
}

//funcao para imrimir os dados do atestado na tela
void imprimirAtestado (Tatestado* atestado, int n)
{
	imprimirAluno(atestado->aluno);
	cout<<endl;
	
	for (int i=0; i<n; i++)
	{
		imprimirDisciplina(atestado->disciplinas[i]);
		cout<<endl<<endl;
	}
	
	cout<<"Carga horaria "<<atestado->horasAula<<" h"<<endl<<endl;
}
