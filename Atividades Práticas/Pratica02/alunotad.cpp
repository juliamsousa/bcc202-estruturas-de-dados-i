#include <iostream>
#include <cstring>
#include <iomanip>
#include "alunotad.hpp"
using namespace std;

//definicao dos campos da struct aluno
struct aluno
{
	long double cpf;
	char nome [50];
	long int matricula;
	char curso [30];
	int dia;
	int mes;
	int ano;
};

//funcao para alocar dinamicamente um tipo aluno
Taluno* criarAluno ()
{
	Taluno* aux = new Taluno;
	
	return aux;
}	

//funcao para desalocar uma variavel tipo aluno	
void desalocarAluno (Taluno* aluno)
{
	delete aluno;
}

//funcao para preencher os campos do tipo aluno
void preencheAluno (Taluno* aluno, long double cpf, char nome [50], long int matricula, char curso [30], int dd, int mm, int yy)
{
	aluno->cpf = cpf;
	strcpy(aluno->nome, nome);
	aluno->matricula = matricula;
	strcpy(aluno->curso, curso);
	aluno->dia = dd;
	aluno->mes = mm;
	aluno->ano = yy;
}

//funcao para preencher/alterar o cpf de um aluno
void inserirCPFAluno (Taluno* aluno, long double cpf)
{ 
	aluno->cpf = cpf;	
}

//funcao para preenceher/alterar o nome de um aluno
void inserirNomeAluno (Taluno* aluno, char nome [50])
{
	strcpy(aluno->nome, nome);
}

//funcao para preenceher/alterar a matricula de um aluno
void inserirMatriculaAluno (Taluno* aluno, long int matricula)
{
	aluno->matricula = matricula;
}

//funcao para preencher/alterar o curso de um aluno
void inserirCursoAluno (Taluno* aluno, char curso [30])
{
	strcpy(aluno->curso, curso);
}

//funcao para preencher/alterar a data de ingresso de um aluno
void inserirDataAluno (Taluno* aluno, int dd, int mm, int yy)
{
	aluno->dia = dd;
	aluno->mes = mm;
	aluno->ano = yy;
}

//funcao para ler o cpf de um aluno
long double acessarCPFAluno (Taluno* aluno)
{ 
	return aluno->cpf;	
}

//funcao para ler onome de um aluno
void acessarNomeAluno (Taluno* aluno, char name [50])
{
	strcpy (name, aluno->nome);
}

//funcao para ler a matricula de um aluno
long int acessarMatriculaAluno (Taluno* aluno)
{
	return aluno->matricula;
}

//funcao para ler o curso de um aluno
void acessarCursoAluno (Taluno* aluno, char curso [30])
{
	strcpy(curso, aluno->curso);
}

//funcao para ler a data de ingresso de um aluno
void acessarDataAluno (Taluno* aluno, int* dd, int* mm, int* yy)
{
	*dd = aluno->dia;	
	*mm = aluno->mes;
	*yy = aluno->ano;
}

//funcao para imprimir os dados de um aluno na tela
void imprimirAluno (Taluno* aluno)
{
	cout<<"Aluno: "<<endl;
	cout<<"Nome: "<<aluno->nome<<endl;
	cout<<"CPF: "<<fixed<<setprecision(0)<<aluno->cpf<<endl;
	cout<<"N. Matricula: "<<aluno->matricula<<endl;
	cout<<"Curso: "<<aluno->curso<<endl;
	cout<<"Data de ingresso: "<<aluno->dia<<"/"<<aluno->mes<<"/"<<aluno->ano<<endl<<endl;
}
