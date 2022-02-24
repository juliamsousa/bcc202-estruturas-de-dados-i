#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "Tcontato.hpp"
#include "arvoreBusca.hpp"
using namespace std;

struct arvNo 
{
	Tcontato* info;
	arvNo* esq;
	arvNo* dir;
};

 // funcao para criar no
arvNo* criaNoArvore ()
{
	arvNo* no = new arvNo;
	
	no = NULL;
	
	return no;
}

 // funcao para preencher um no
void preencheNoArvore (arvNo* no, Tcontato* informacao)
{
	no->info = informacao;
}

 //funcao queretorna a informacao de um no
Tcontato* retornaInfo (arvNo* no)
{
	return no->info;
}

 // funcao para buscar um contato
arvNo* buscaNoArv (arvNo* pRaiz, string contato)
{
	if (pRaiz == NULL)
		return NULL;
		
	else if (acessaNome(pRaiz->info) > contato)
			return buscaNoArv(pRaiz->esq, contato);
			
	else if (acessaNome(pRaiz->info) < contato)
			return buscaNoArv (pRaiz->dir, contato);
			
	else return pRaiz;
}

 // funcao para inserir um no
arvNo* arvNoInsere (arvNo* pRaiz, arvNo* no)
{
	if (pRaiz == NULL)
		return no;
	
	if (acessaNome (pRaiz->info) > acessaNome (no->info))
		pRaiz->esq = arvNoInsere (pRaiz->esq, no);
	else
		pRaiz->dir = arvNoInsere (pRaiz->dir, no);

	return pRaiz;
}

 // funcao para retirar um no
arvNo* arvNoRetira (arvNo* pRaiz, Tcontato* pessoa)
{
	if (pRaiz == NULL) // verififica se a arvore e vazia
		return NULL;
	else if (acessaNome(pRaiz->info) > acessaNome(pessoa))
			pRaiz->esq = arvNoRetira(pRaiz->esq, pessoa);
	else if (acessaNome(pRaiz->info) < acessaNome(pessoa))
			pRaiz->dir = arvNoRetira(pRaiz->dir, pessoa);
	else // o elemento a ser retirado foi encontrado
	{
		if (pRaiz->esq == NULL && pRaiz->dir == NULL) // verifica se o elemento nao possui filhos
		{
			delete pRaiz; // e apenas desalocada de forma trivial
			pRaiz = NULL;
		}
		else if (pRaiz->esq == NULL) // verifica se o elemento possui filho apenas a direita
		{
			arvNo* t = pRaiz;
			pRaiz = pRaiz->dir; // recebe seu filho a direita
			delete t;
		}
		else if (pRaiz->dir == NULL) // verifica se o elemento possui filho apenas a esquerda
		{
			arvNo* t = pRaiz;
			pRaiz = pRaiz->esq; // recebe seu filho a esquerda
			delete t;
		}
		else // verifica se o elemento possui dois filhos
		{
			arvNo* pai = pRaiz;
			arvNo* f = pRaiz->esq;
			
			while (f->dir != NULL)
			{
				pai = f;
				f = f->dir;
				pRaiz->info = f->info;
				pRaiz->info = pessoa;
				pRaiz->esq = arvNoRetira (pRaiz->esq, pessoa);
			}
		}
	}
	
	return pRaiz;
}
 
 // forma de impressao pre-ordem
void preOrdem (arvNo* pRaiz)
{
	if (pRaiz == NULL)
		return;
	
	imprimirContato (pRaiz->info);
	
	preOrdem (pRaiz->esq);
	preOrdem (pRaiz->dir);
}

 // forma de impressao pos-ordem
void posOrdem (arvNo* pRaiz)
{
	if (pRaiz == NULL)
		return;
	
	posOrdem (pRaiz->esq);
	posOrdem (pRaiz->dir);
	
	imprimirContato (pRaiz->info);
}

 // forma de impressao caminhamento central
void caminhaCentral (arvNo* pRaiz)
{
	if (pRaiz == NULL)
		return;
	
	caminhaCentral (pRaiz->esq);
	
	imprimirContato (pRaiz->info);
	
	caminhaCentral (pRaiz->dir);
}
