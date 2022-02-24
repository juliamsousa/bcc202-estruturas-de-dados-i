#include <iostream>
#include <cstddef>
#include "alunotad.hpp"
#include "lista.hpp"
using namespace std;

typedef struct listaNo  
{
	//campo para informacao contida no nó
	Taluno* aluno;
	
	//campo para apontar para o proximo elemento da lista
	listaNo* proximo;
	
} ListaNo;

struct lista
{
	//ponteiro para o primeiro nó da lista
	ListaNo* primeiro;
};

ListaNo* criaNo ()
{
	ListaNo* aux = new ListaNo;
	
	aux->aluno = criarAluno ();
	
	return aux;
}

void desalocaNo (ListaNo* no)
{
	desalocarAluno (no->aluno);
	
	delete no;
}

Lista* criaLista ()
{
	//aloca a lista dinamicamente
	lista* aux = new lista;
	
	//apontando seu campo primeiro para nulo
	aux->primeiro = NULL;
	
	//retorno da lista devidamente alocada
	return aux;
}

void liberaLista (Lista* l)
{
	//ponteiro de nó para o primeiro nó da lista
	ListaNo* aux = l->primeiro;
	//ponteiro de nó auxiliar para nao perder o encadeamneto
	ListaNo* aux2;
	
	while (aux != NULL)
	{
		//ponteiro de nó auxiliar para o proximo nó da lista para nao perder o encadeameto
		aux2 = aux->proximo;
		//desalocar o nó apos apontar para o seu proximo
		desalocarAluno (aux->aluno);
		
		delete aux;
		//apontando para o proximo elemnto da lista para ser desalocado na proxima iteraccao
		aux = aux2;
	}
	
	//apos desalocar cada nó, desalocar a lista
	delete l;
}

void insereInicioLista (Lista* l, int v, ListaNo* no)
{
	//aponta o nó para o primeiro nó da lista para nao quebrar o encadeamento
	no->proximo = l->primeiro;
	//insere o novo nó na primeira posicao da lista
	l->primeiro = no;
}

void insereOrdenadoLista (Lista* l, ListaNo* inserir)
{
	ListaNo* ant = NULL;
	ListaNo* aux = l->primeiro;
	
	while (aux!=NULL && acessarMatriculaAluno (aux->aluno) < acessarMatriculaAluno (inserir->aluno))
	{
		ant = aux;
		aux = aux->proximo;
	}
	
	if (ant!=NULL)
	{
		inserir->proximo = ant->proximo;
		ant->proximo = inserir;	
	}
	else
	{
		inserir->proximo = l->primeiro;
		l->primeiro = inserir;
	}
}

void retiraLista (Lista* l, long int matricula)
{
	ListaNo* ant = NULL;
	ListaNo* n = l->primeiro;
	
	while (n!=NULL && acessarMatriculaAluno (n->aluno) != matricula)
	{
		ant = n;
		n = n->proximo;
	}

	if (n!=NULL)
	{
		if (ant == NULL)
			l->primeiro = n->proximo;
		else
			ant->proximo = n->proximo;
			
		desalocaNo (n);
	}
	else
		cout<<"Elemento nao esta presente na lista"<<endl;
}

int listaVazia (Lista* l)
{
	//verifica se o campo primeiro esta apontado para nulo
	if (l->primeiro == NULL)
		return 1;
	
	//caso o campo esteja apontado para algum nó
	return 0;
}

int listaPertence (Lista* l, long int matricula)
{
	ListaNo* no = l->primeiro;
	
	while (no!= NULL)
	{
		if (no->informacao == matricula)
			return 1;
		
		no = no->proximo;
	}
	
	return 0;
}

void listaImprime (Lista* l)
{
	ListaNo* no;
	
	for (no = l->primeiro; no!= NULL; no = no->proximo)
		imprimirAluno (no);
		
	cout<<endl;
}
