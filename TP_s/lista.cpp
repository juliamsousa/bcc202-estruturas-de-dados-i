#include "lista.hpp"
#include <iostream>
using namespace std;
struct lista{
	ListaNo* prim;
};

struct listano{
	int info;
	ListaNo* prox;
};

struct lista_ult{
	ListaNo* ultimo;
};

Lista* lista_criar (){
	Lista* l= new Lista;
	l->prim=NULL;
	return l;
}

void lista_liberar (Lista* l){
	ListaNo* p = l-> prim; 
	while (p!=NULL) {
		ListaNo* t= p-> prox; //guarda referencia para proximo elemento
		delete p; //deleta a memoria apontada para p
		p= t; //faz apontar para o proximo
	}
	delete l;
}

void lista_inserir (Lista* l, int v){
	ListaNo* novo= new Listano;
	novo-> info= v;
	novo-> prox= l->prim;
	l->prim=novo;
}

void lista_insere_ordenado (Lista* l, int v){
	ListaNo* ant = NULL; //ponteiro pra elemento anterior
	ListaNo* p= l-> prim; //ponteiro para percorrer lista
	
	//localizar posição de inserção
	while (p!=NULL && p->info <v){
		ant =p;
		p= p-> prox;
	}
	
	//cria novo elemento
	ListaNo* novo = new Listano;
	novo -> info=v;

	
	//encadeia elemento	
	if (ant == NULL ){
		novo-> prox = l->prim;
		l->prim= novo;
	}
	//insere elemento no lugar 
	else{
		novo->prox= anti->prox;
		ant->prox= novo;
	}
}

void lista_retirar (Lista* l, int v){
	ListaNo* ant = NULL; //ponteiro pra elemento anterior
	ListaNo* p= l->prim; //ponteiro para percorrer lista
	
	//procura elemento na lista e guarda anterior
	while (p!=NULL && p->info!=v){
		ant=p;
		p=p->prox;
	}
	
	//verifica se achou elemento
	if (p!=NULL){
		//retira elemento
		if(ant==NULL)
			l->prim=p->prox;

		//retira elemento do meio da lista
		else
			ant->prox=p->prox;
		//libera o nó
		delete p;
	}
}
	
int lista_vazia (Lista* l){
	return (l->prim==NULL);
}

int lista_pertence (Lista* l, int v){
	ListaNo* p= l-> prim; //ponteiro para percorrer lista
	
	while (p->prox!=NULL && p->info!=v) //percorrer o encadeamento até encontrar o numero ou null
		p=p->prox;
	if (p->info == v)
		return 1;
	else
		return 0;
}

void lista_imprime (Lista* l){
	for(ListaNo* p=l->prim; p!=NULL; p=p->prox)
		cout<<"Valor:"<<p->infor<<endl;
}

void lista_insere_ultima_posicao (Lista *l);
int lista_retira_ultima_posicao (Lista *l);

