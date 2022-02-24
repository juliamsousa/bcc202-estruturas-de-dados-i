#include <iostream>
#include <string>
#include "Tcontato.hpp"
using namespace std;

 // struct Tcontato
struct contato
{
	string nome;
	long int tel;
	int dia, mes, ano;
};

 // funcao para criar um contato
contato* criaContato ()
{
	contato* aux = new contato;
	
	return aux;
}

 // funcao para preencher os campos de um contato
void preencheContato (contato* pessoa, string name, long int phone, int day, int month, int year)
{
	pessoa->nome = name;
	pessoa->tel = phone;
	pessoa->dia = day;
	pessoa->mes = month;
	pessoa->ano = year; 
}

 // funcao para imprimir os campos do contato
void imprimirContato (contato* pessoa)
{
	cout<<"Nome: "<<pessoa->nome<<endl;
	cout<<"Telefone: "<<pessoa->tel<<endl;
	cout<<"Data de aniversario: "<<pessoa->dia<<"/"<<pessoa->mes<<"/"<<pessoa->ano<<endl;
	cout<<endl;		
}

 // funcao para desalocar um contato
void desalocaContato (contato* pessoa)
{
	delete pessoa;
}

 // funcao para alterar nome do contato
void alteraNome (contato* pessoa, string name)
{
	pessoa->nome = name;
}

 // funcao para alterar o telefone de um contato
void alteraTelefone (contato* pessoa, long int phone)
{
	pessoa->tel = phone;
}

 // funcao para alterar o dia de aniversario do contato
void alteraDia (contato* pessoa, int day)
{
	pessoa->dia = day;
}
 // funcao para alterar o mes de aniversario do contato
void alteraMes (contato* pessoa, int month)
{
	pessoa->mes = month;
}

 // funcao para alterar o ano de aniversario do contato
void alteraAno (contato* pessoa, int year)
{
	pessoa->ano = year;
}

 // funcao para acessar o nome do contato
string acessaNome (contato* pessoa)
{
	return pessoa->nome;
}

 // funcao para acessar o telefone do contato
long int acessaTelefone (contato* pessoa)
{
	 return pessoa->tel;
}
 // funcao para acesar o dia de aniverasrio do contato
int acessaDia (contato* pessoa)
{
	 return pessoa->dia;
}

 // fucncao para acessar o mes de aniversario do contato
int acessaMes (contato* pessoa)
{
	 return pessoa->mes;
}

 // funcao para acessar o ano de aniversario do contato
int acessaAno (contato* pessoa)
{
	return pessoa->ano;
}
