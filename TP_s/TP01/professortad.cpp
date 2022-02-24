#include <iostream>
#include <cstring>
#include <iomanip>
#include "professortad.hpp"
using namespace std;

//definicao dos campos da struct professor
struct professor 
{
	long double cpf;
	char nome [50];
	char departamento [30];
};

//funcao para alocar dinamicamente um tipo professor
Tprofessor* criarProfessor ()
{
	Tprofessor* aux = new Tprofessor;
	
	return aux;
}

//funcao para desalocar um tipo professor
void desalocarProfessor (Tprofessor* professor)
{
	delete professor;
}

//funcao para preencher os campos do tipo professor
void preencheProfessor (Tprofessor* professor, long double cpf, char nome [50], char departamento [30])
{
	professor->cpf = cpf;
	strcpy(professor->nome, nome);
	strcpy(professor->departamento, departamento);
}

//funcao para alterar/preencher o cpf de um professor
void inserirCPFProfessor (Tprofessor* professor, long double cpf)
{
	professor->cpf = cpf;
}

//funcao para alterar/preencher o nome de um professor
void inserirNomeProfessor (Tprofessor* professor, char name [50])
{
	strcpy(professor->nome, name);
}

//funcao para alterar/preencher o departamento de um professor
void inserirDepartamento (Tprofessor* professor, char dpt [30])
{
	strcpy(professor->departamento, dpt);
}

//funcao para ler o cpf de um professor 
long double acessarCPFProfessor (Tprofessor* professor)
{
	return professor->cpf;
}

//funcao para acessar o nome de um professor
void acessarNomeProfessor (Tprofessor* professor, char name [50])
{
	strcpy(name, professor->nome);	
}

//funcao para ler o departamento de um professor
void acessarDepartamento (Tprofessor* professor, char dpt [30])
{
	strcpy (dpt, professor->departamento);
}

//funcao para imprimir na tela os dados de um professor
void imprimirProfessor (Tprofessor* professor)
{
	cout<<"Professor: "<<endl;
	cout<<"Nome: "<<professor->nome<<endl;
	cout<<"CPF: "<<fixed<<setprecision(0)<<professor->cpf<<endl;
	cout<<"Departamento: "<<professor->departamento<<endl<<endl;
}
