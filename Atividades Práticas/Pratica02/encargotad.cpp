#include <iostream>
#include <cstring>
#include <iomanip>
#include "professortad.hpp"
#include "disciplinatad.hpp"
#include "encargotad.hpp"
using namespace std;

//defnicao dos campos da struct encargo
struct encargo
{
	Tprofessor* professor;
	
	Tdisciplina** disciplinas;
	
	int horasAula;
};

//funcao para alocar dinamicamente um tipo encargo
Tencargo* criarEncargo (int n)
{
	Tencargo* aux = new Tencargo;
	
	aux->professor = criarProfessor();
	
	aux->disciplinas = new Tdisciplina*;
	
	for (int i=0; i<n; i++)
		aux->disciplinas[i] = criarDisciplina();

	return aux;
}

//funcao para desalocar um tipo encargo
void desalocarEncargo (Tencargo* encargo, int n)
{
	desalocarProfessor(encargo->professor);
	
	for (int i=0; i<n; i++)
		desalocarDisciplina(encargo->disciplinas[i]);
		
	delete [] encargo->disciplinas;
		
	delete encargo;
}

//funcao para preencher os campos de um tipo encargo
void preencheEncargo (Tencargo* encargo, int n)
{
	int ch=0;
	long double cpf;
	int carga, sala, dd, mm, yy;
	char nome [50];
	char departamento [30];
	char codigo [15];
	char curso [30];
	
	cout<<"Digite o nome do professor: "<<endl;
	cin>>nome;
	cout<<"Digite o CPF do professor: "<<endl;
	cin>>cpf;
	cout<<"Digite o departamento do professor: "<<endl;
	cin>>departamento;
	
	//chamada da funcao para preencher os campos do professor contido no encargo
	preencheProfessor(encargo->professor, cpf, nome, departamento);
	
	for (int i=0; i<n; i++)
	{	
		//comparacao para verificar se as horas aula permitidas estao sendo ultrapassadas
		if (ch<=16)
		{
			cout<<"Digite o nome da disciplina "<<i+1<<endl;
			cin>>nome;
			cout<<"Digite o codigo da disciplina "<<i+1<<endl;
			cin>>codigo;
			cout<<"Digite o curso da disciplina "<<i+1<<endl;
			cin>>curso;
			cout<<"Digite a carga horaria da disciplina "<<i+1<<endl;
			cin>>carga;
			cout<<"Digite a sala da disciplina "<<i+1<<endl;
			cin>>sala;
			
			//funcao para preenceher as disciplins contidas no encargo	 
			preencheDisciplina(encargo->disciplinas[i], nome, codigo, carga, curso, sala);		
			
			//calculo da carga horaria total
			ch+=acessarCH(encargo->disciplinas[i]);
		}
		else 
			cout<<"Horas permitidas atingidas."<<endl;
	}
	
	encargo->horasAula = ch;
}

//funcao para alterar/acessar os dados do profesor contido no encargo
void alterarProfessor (Tencargo* encargo)
{
	int t, tprofessor;

	do 
	{
		cout<<"**Opcao professor**"<<endl;
		cout<<"1 - Alterar dados"<<endl;
		cout<<"2 - Acessar dados"<<endl;
		cout<<"0 - Sair do menu aluno"<<endl<<endl;
	
		cin>>t;
	
		switch (t) 
		{
			//opcao para alterar dados do professor contido no encargo
			case 1: 
			{
				int a;
	
				cout<<"**Alterar dados**"<<endl;
				cout<<"11 - Alterar o CPF "<<endl;
				cout<<"12 - Alterar o nome"<<endl;
				cout<<"13 - Alterar o departamento"<<endl;
	
				cin>>a;
	
				switch (a) 
				{
					//opcao para alterar/preencher o cpf do professor contido no atestado
					case 11: 
					{
						long double cpf;
	
						cout<<"Digite o CPF: "<<endl;
						cin>>cpf;
	
						inserirCPFProfessor(encargo->professor, cpf);
					}
					break;
					
					//opcao para alterar/preencher o nome do professor contido no atestado
					case 12: 
					{
						char nome [50];
	
						cout<<"Digite o nome: "<<endl;
						cin>>nome;
	
						inserirNomeProfessor(encargo->professor, nome);
					}
					break;
	
					//opcao para alterar/preencher o departamento do professor contido no atestado
					case 13: 
					{
						char departamento [30];
	
						cout<<"Digite o departamento: "<<endl;
						cin>>departamento;
	
						inserirDepartamento(encargo->professor, departamento);
					}
					break;
				}
			}
			break;
			
			//opcao para acessar dados do professor contido no atestado
			case 2: 
			{
				int x;
	
				cout<<"**Acesso a dados**"<<endl;
				cout<<"31 - Acessar o CPF "<<endl;
				cout<<"32 - Acessar o nome"<<endl;
				cout<<"33 - Acessar o departamento"<<endl;
	
				cin>>x;
	
				switch(x) 
				{
					//opcao para ler o cpf do professor contido no atestado
					case 21: 
					{
						cout<<"CPF: "<<acessarCPFProfessor(encargo->professor)<<endl;
					}
					break;
					
					//opcao para ler o nome do professor conido no encargo
					case 22: 
					{
						char nome [50];
	
						acessarNomeProfessor (encargo->professor, nome);
	
						cout<<"Nome: "<<nome<<endl;
					}
					break;
					
					//opcao para ler o departamento do professor contido no atestado
					case 23: 
					{
						char departamento [30];
					
						acessarDepartamento (encargo->professor, departamento);
	
						cout<<"Departamento: "<<departamento<<endl;
					}
					break;
				}
			}
			break;
		}
	} while (t != 0);
}

//funcao para alterar as disciplinas contidas no encargo
void alterarDisciplinaEncargo (Tencargo* encargo)
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
			//opcao para alterar dados das disciplinas contidas no encargo
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
					//opcao para alterar o nome de uma disciplina contida no encargo
					case 11: 
					{
						int n;
						char nome [30];
	
						cout<<"Digite a posicao da disciplina desejada:"<<endl;
						cin>>n;
						cout<<"Digite o nome: "<<endl;
						cin>>nome;
	
						inserirNomeDisciplina(encargo->disciplinas[n-1], nome);
					}
					break;
					
					//opcao para alterar o codigo de uma disciplina contida no encargo
					case 12: 
					{
						int n;
						char codigo [15];
	
						cout<<"Digite a posicao da disciplina desejada:"<<endl;
						cin>>n;
						cout<<"Digite o codigo: "<<endl;
						cin>>codigo;
	
						inserirCodigo(encargo->disciplinas[n-1], codigo);
					}
					break;
					
					//opcao para alterar a carga horaria de uma disciplina contida no encargo
					case 13: 
					{
						int n;
						int carga;
	
						cout<<"Digite a posicao da disciplina desejada:"<<endl;
						cin>>n;
						cout<<"Digite a carga horaria: "<<endl;
						cin>>carga;
	
						inserirCH(encargo->disciplinas[n-1], carga);
					}
					break;
	
					//opcao para alterar o curso de uma disciplina contida no encargo
					case 14: 
					{
						int n;
						char curso [30];
	
						cout<<"Digite a posicao da disciplina desejada:"<<endl;
						cin>>n;
						cout<<"Digite o curso: "<<endl;
						cin>>curso;
	
						inserirCurso(encargo->disciplinas[n-1], curso);
					}
					break;
					
					//opcao para alterar o numero da sala de uma disciplina contida no encargo
					case 15: 
					{
						int n;
						int numero;
	
						cout<<"Digite a posicao da disciplina desejada:"<<endl;
						cin>>n;
						cout<<"Digite o numero da sala: "<<endl;
						cin>>numero;
	
						inserirSala(encargo->disciplinas[n-1], numero);
					}
					break;
				}
			}
			break;
			
			//opcao para acessar dados das disciplinas contidas no encargo
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
					//opcao para ler o nome de uma disciplina contida no encargo
					case 21: 
					{
						char nome [30];
						int n;
	
						cout<<"Digite a posicao da disciplina desejada: "<<endl;
						cin>>n;
	
						acessarNomeDisciplina (encargo->disciplinas[n-1], nome);
	
						cout<<"Nome: "<<nome<<endl;
					}
					break;
					
					//opcao para ler o codigo de uma disciplina
					case 22: 
					{
						int n;
						char code [15];
	
						cout<<"Digite a posicao da disciplina desejada: "<<endl;
						cin>>n;
	
						acessarCodigo(encargo->disciplinas[n-1], code);
	
						cout<<"Codigo: "<<code<<endl;
					}
					break;
					
					//opcao para ler a carga horaria de uma dsciplina contida no encargo
					case 23: 
					{
						int n;
	
						cout<<"Digite a posicao da disciplina desejada: "<<endl;
						cin>>n;
	
						cout<<"Carga horaria: "<<acessarCH(encargo->disciplinas[n-1])<<" h"<<endl;
					}
					break;
	
					//opcao para ler o curso de uma disciplina contida no encargo
					case 24: 
					{
						char curso [30];
						int n;
	
						cout<<"Digite a posicao da disciplina desejada: "<<endl;
						cin>>n;
	
						acessarCurso (encargo->disciplinas[n-1], curso);
	
						cout<<"Curso: "<<curso<<endl;
					}
					break;
					//opcao para ler a sala de uma disciplina contida no encargo
					case 25: 
					{
						int n;
	
						cout<<"Digite a posicao da disciplina desejada: "<<endl;
						cin>>n;
	
						cout<<"Sala: "<<acessarSala(encargo->disciplinas[n-1])<<endl;
					}
					break;
				}
			}
			break;
		}
	} while (t != 0);
}

//funcao para imprimir na tela os dados do tipo encargo
void imprimirEncargo (Tencargo* encargo, int n)
{
	imprimirProfessor(encargo->professor);
	cout<<endl<<endl;
	for (int i=0; i<n; i++)
	{
		imprimirDisciplina(encargo->disciplinas[i]);
		cout<<endl;
	}
	
	cout<<"Carga horaria "<<encargo->horasAula<<" h"<<endl<<endl;
}
