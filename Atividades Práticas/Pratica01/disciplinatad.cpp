#include <iostream>
#include <cstring>
#include "disciplinatad.hpp"
using namespace std;

struct disciplina 
{
	char nome [30];
	char codigo [15];
	int ch;
	char curso [30];
	int sala;
};

Tdisciplina* criarDisciplina (char nome [30], char codigo [15], int carga, char curso [30], int sala)
{
	Tdisciplina* aux = new Tdisciplina;
	
	strcpy (aux->nome, nome);
	strcpy (aux->codigo, codigo);
	aux->ch = carga;
	strcpy (aux->curso, curso);
	aux->sala = sala;
	
	return aux;
} 

void desalocarDisciplina (Tdisciplina* disciplina)
{
	delete disciplina;
}

void preencheDisciplina (Tdisciplina* disciplina, char name [30], char code [15], int carga, char course [30], int numero)
{
	strcpy(disciplina->nome, name);
	strcpy(disciplina->codigo, code);
	disciplina->ch = carga;
	strcpy(disciplina->curso, course);
	disciplina->sala = numero;
}

void inserirNomeDisciplina (Tdisciplina* disciplina, char name [30])
{
	strcpy(disciplina->nome, name);
}

void inserirCodigo (Tdisciplina* disciplina, char code [15])
{
	strcpy (disciplina->codigo, code);
}

void inserirCH (Tdisciplina* disciplina, int carga)
{
	disciplina->ch = carga;
}

void inserirCurso (Tdisciplina* disciplina, char course [30])
{
	strcpy (disciplina->curso, course);
}

void inserirSala (Tdisciplina* disciplina, int numero)
{
	disciplina->sala = numero;
}

void acessarNomeDisciplina (Tdisciplina* disciplina, char name [30])
{
	strcpy (name, disciplina->nome);
}

void acessarCodigo (Tdisciplina* disciplina, char code [15])
{
	strcpy(code, disciplina->codigo);
}

int acessarCH (Tdisciplina* disciplina)
{
	return disciplina->ch;
}

void acessarCurso (Tdisciplina* disciplina, char course [30])
{
	strcpy (course, disciplina->curso);
}

int acessarSala (Tdisciplina* disciplina)
{
	return disciplina->sala;
}

void imprimirDisciplina (Tdisciplina* disciplina)
{
	cout<<"Disciplina: "<<endl;
	cout<<"Nome: "<<disciplina->nome;
	cout<<"Codigo: "<<disciplina->codigo<<endl;
	cout<<"Carga horaria: "<<disciplina->ch<<"h"<<endl;
	cout<<"Curso: "<<disciplina->curso<<endl;
	cout<<"Sala em que e ofertada: "<<disciplina->sala<<endl;
}
