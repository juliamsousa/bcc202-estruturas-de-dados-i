#include <iostream>
#include <cstddef>
#include "lista.hpp"
using namespace std;

typedef struct listaNo  
{
	// campo 
	string vocabulario;
	//campo para ocorrencias
	int informacao;
	
	//campo para apontar para o proximo elemento da lista
	listaNo* proximo;
	
} ListaNo;

struct lista
{
	//ponteiro para o primeiro nó da lista
	ListaNo* primeiro;
};

Lista* criaLista ()
{
	//aloca a lista dinamicamente
	Lista* aux = new Lista;
	
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
		delete aux;
		//apontando para o proximo elemnto da lista para ser desalocado na proxima iteraccao
		aux = aux2;
	}
	
	//apos desalocar cada nó, desalocar a lista
	delete l;
}

void insereInicioLista (Lista* l, int v, string palavra)
{
	//aloca um nó dinamicamente
	ListaNo* no = new ListaNo;
	
	//preenche o nó com o valor passado na funcao
	no->informacao = v;
	//preenche o campo do voabulario
	no->vocabulario = palavra; 
	//aponta o nó para o primeiro nó da lista para nao quebrar o encadeamento
	no->proximo = l->primeiro;
	//insere o novo nó na primeira posicao da lista
	l->primeiro = no;
}
void insereOrdenadoLista (Lista* l, int v)
{
	ListaNo* inserir = new ListaNo;
	inserir->informacao = v;
	
	ListaNo* ant = NULL;
	ListaNo* aux = l->primeiro;
	
	while (aux!=NULL && aux->informacao<v)
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

void retiraLista (Lista* l, int v)
{
	ListaNo* ant = NULL;
	ListaNo* n = l->primeiro;
	
	while (n!=NULL && n->informacao!=v)
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
			
		delete n;
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

int listaPertence (Lista* l, int v)
{
	ListaNo* no = l->primeiro;
	
	while (no!= NULL)
	{
		if (no->informacao == v)
			return 1;
		
		no = no->proximo;
	}
	
	return 0;
}

void listaImprime (Lista* l)
{
	ListaNo* no;
	
	for (no = l->primeiro; no!= NULL; no = no->proximo)
		cout<<no->informacao<<" ";
		
	cout<<endl;
}
