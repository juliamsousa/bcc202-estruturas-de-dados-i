#include <iostream>
#include <cstring>
#include <iomanip>
#include "alunotad.hpp"
using namespace std;

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

Taluno* criarAluno (long double cpf, char nome [50], long int matricula, char curso [30], int dd, int mm, int yy)
{
	Taluno* aux = new Taluno;
	
	aux->cpf = cpf;
	strcpy(aux->nome, nome);
	aux->matricula = matricula;
	strcpy(aux->curso, curso);
	aux->dia = dd;
	aux->mes = mm;
	aux->ano = yy;
	
	return aux;
}	
	
void desalocarAluno (Taluno* aluno)
{
	delete aluno;
}

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

void inserirCPFAluno (Taluno* aluno, long double cpf)
{ 
	aluno->cpf = cpf;	
}

void inserirNomeAluno (Taluno* aluno, char nome [50])
{
	strcpy(aluno->nome, nome);
}

void inserirMatriculaAluno (Taluno* aluno, long int matricula)
{
	aluno->matricula = matricula;
}

void inserirCursoAluno (Taluno* aluno, char curso [30])
{
	strcpy(aluno->curso, curso);
}

void inserirDataAluno (Taluno* aluno, int dd, int mm, int yy)
{
	aluno->dia = dd;
	aluno->mes = mm;
	aluno->ano = yy;
}

long double acessarCPFAluno (Taluno* aluno)
{ 
	return aluno->cpf;	
}

void acessarNomeAluno (Taluno* aluno, char name [50])
{
	strcpy (name, aluno->nome);
}

long int acessarMatriculaAluno (Taluno* aluno)
{
	return aluno->matricula;
}

void acessarCursoAluno (Taluno* aluno, char curso [30])
{
	strcpy(curso, aluno->curso);
}

void acessarDataAluno (Taluno* aluno, int* dd, int* mm, int* yy)
{
	*dd = aluno->dia;	
	*mm = aluno->mes;
	*yy = aluno->ano;
}

void imprimirAluno (Taluno* aluno)
{
	cout<<"Aluno: "<<endl;
	cout<<"Nome: "<<aluno->nome<<endl;
	cout<<"CPF: "<<fixed<<setprecision(0)<<aluno->cpf<<endl;
	cout<<"N. Matricula: "<<aluno->matricula<<endl;
	cout<<"Curso: "<<aluno->curso<<endl;
	cout<<"Data de ingresso: "<<aluno->dia<<"/"<<aluno->mes<<"/"<<aluno->ano<<endl;
}
