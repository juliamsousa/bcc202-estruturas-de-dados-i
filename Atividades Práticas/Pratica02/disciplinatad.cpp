#include <iostream>
#include <cstring>
#include "disciplinatad.hpp"
using namespace std;

//definicao dos campos da struct disciplina
struct disciplina 
{
	char nome [30];
	char codigo [15];
	int ch;
	char curso [30];
	int sala;
};

//funcao para alocar dinamicamene um tipo disciplina
Tdisciplina* criarDisciplina ()
{
	Tdisciplina* aux = new Tdisciplina;
	
	return aux;
} 

//funcao para desalocar um tipo disciplina
void desalocarDisciplina (Tdisciplina* disciplina)
{
	delete disciplina;
}

//funcao para preenceher os campos de um tipo disciplina
void preencheDisciplina (Tdisciplina* disciplina, char name [30], char code [15], int carga, char course [30], int numero)
{
	strcpy(disciplina->nome, name);
	strcpy(disciplina->codigo, code);
	disciplina->ch = carga;
	strcpy(disciplina->curso, course);
	disciplina->sala = numero;
}

//funcao para preencehr/alterar o nome de uma disciplina
void inserirNomeDisciplina (Tdisciplina* disciplina, char name [30])
{
	strcpy(disciplina->nome, name);
}

//funcao para preencehr/alterar o codigo de uma disciplina
void inserirCodigo (Tdisciplina* disciplina, char code [15])
{
	strcpy (disciplina->codigo, code);
}

//funcao para preencehr/alterar a carga horaria de uma disciplina
void inserirCH (Tdisciplina* disciplina, int carga)
{
	disciplina->ch = carga;
}

//funcao para preencehr/alterar o curso de uma disciplina
void inserirCurso (Tdisciplina* disciplina, char course [30])
{
	strcpy (disciplina->curso, course);
}

//funcao para preencehr/alterar a sala de uma disciplina
void inserirSala (Tdisciplina* disciplina, int numero)
{
	disciplina->sala = numero;
}

//funcao para ler o nome de uma disciplina
void acessarNomeDisciplina (Tdisciplina* disciplina, char name [30])
{
	strcpy (name, disciplina->nome);
}

//funcao para ler o codigo de uma disciplina
void acessarCodigo (Tdisciplina* disciplina, char code [15])
{
	strcpy(code, disciplina->codigo);
}

//funcao para ler a carga horaria de uma disciplina
int acessarCH (Tdisciplina* disciplina)
{
	return disciplina->ch;
}

//funcao para ler o curso de uma disciplina
void acessarCurso (Tdisciplina* disciplina, char course [30])
{
	strcpy (course, disciplina->curso);
}

//funcao para ler a sala de uma disciplina
int acessarSala (Tdisciplina* disciplina)
{
	return disciplina->sala;
}

//funcao para imprimir na tela os dados de uma disciplina 
void imprimirDisciplina (Tdisciplina* disciplina)
{
	cout<<"Disciplina: "<<endl;
	cout<<"Nome: "<<disciplina->nome<<endl;
	cout<<"Codigo: "<<disciplina->codigo<<endl;
	cout<<"Carga horaria: "<<disciplina->ch<<"h"<<endl;
	cout<<"Curso: "<<disciplina->curso<<endl;
	cout<<"Sala em que e ofertada: "<<disciplina->sala<<endl;
}
