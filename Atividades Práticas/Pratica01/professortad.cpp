#include <iostream>
#include <cstring>
#include <iomanip>
#include "professortad.hpp"
using namespace std;

struct professor 
{
	long double cpf;
	char nome [50];
	char departamento [30];
};

Tprofessor* criarProfessor (long double cpf, char nome [50], char departamento [30])
{
	Tprofessor* aux = new Tprofessor;
	
	aux->cpf = cpf;
	strcpy (aux->nome, nome);
	strcpy (aux->departamento, departamento);
	
	return aux;
}

void desalocarProfessor (Tprofessor* professor)
{
	delete professor;
}

void preencheProfessor (Tprofessor* professor, long double cpf, char nome [50], char departamento [30])
{
	professor->cpf = cpf;
	strcpy(professor->nome, nome);
	strcpy(professor->departamento, departamento);
}

void inserirCPFProfessor (Tprofessor* professor, long double cpf)
{
	professor->cpf = cpf;
}

void inserirNomeProfessor (Tprofessor* professor, char name [50])
{
	strcpy(professor->nome, name);
}

void inserirDepartamento (Tprofessor* professor, char dpt [30])
{
	strcpy(professor->departamento, dpt);
}

long double acessarCPFProfessor (Tprofessor* professor)
{
	return professor->cpf;
}

void acessarNomeProfessor (Tprofessor* professor, char name [50])
{
	strcpy(name, professor->nome);	
}

void acessarDepartamento (Tprofessor* professor, char dpt [30])
{
	strcpy (dpt, professor->departamento);
}

void imprimirProfessor (Tprofessor* professor)
{
	cout<<"Professor: "<<endl;
	cout<<"Nome: "<<professor->nome;
	cout<<"CPF: "<<fixed<<setprecision(0)<<professor->cpf<<endl;
	cout<<"Departamento: "<<professor->departamento<<endl;
}
