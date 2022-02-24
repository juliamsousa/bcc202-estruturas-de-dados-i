#include <iostream>
#include <cstddef>
#include <stddef.h>
#include "filaGeometrica.hpp"
using namespace std;

struct no 
{
	figura id; 
	void* informacao;
	no* proximo;
};

struct fila
{
	no* primeiro;
};

struct triangle
{
	float base;
	float altura;
};

struct circle
{
	float raio;
};

struct rectangle
{
	float base;
	float altura;
};

circle* criaCirculo (float r)
{
	circle* aux = new circle;
	aux->raio = r;
	
	return aux;
}

void acessaRaioCirculo (circle* circuloAcessa, double r)
{
	r = circuloAcessa->raio;
}

rectangle* criaRetangulo (float b, float h)
{
	rectangle* aux = new rectangle;
	aux->altura = h;
	aux->base = b;
	
	return aux;
}

void acessaBaseRetangulo (rectangle* retanguloBase, double base)
{
	base = retanguloBase->base;
}

void acessaAlturaRetangulo (rectangle* retanguloAltura, double height)
{
	height = retanguloAltura->altura;
}

triangle* criaTriangulo (float b, float h)
{
	triangle* aux = new triangle;
	aux->altura = h;
	aux->base = b;
	
	return aux;
}

void acessaBaseTriangulo (triangle* trianguloBase, double base)
{
	base = trianguloBase->base;
}

void acessaAlturaTriangulo (rectangle* trianguloAltura, double height)
{
	height = trianguloAltura->altura;
}

no* criaNoVazio ()
{
	no* aux = new no;
	aux->proximo = NULL;
	aux->informacao = NULL;

	return aux;	
}

void preencheNo (int tipo, float raio, float base, float altura, no* noPreenchido)
{	
	switch (noPreenchido->id)
	{
		case RET:
		{
			noPreenchido->informacao = criaRetangulo (base, altura);
		} break;
		
		case CIRC:
		{
			noPreenchido->informacao = criaCirculo (raio);
		} break;
		
		case TRI:
		{
			noPreenchido->informacao = criaTriangulo (base, altura);
		}
	}
}

void desalocarNo (no* noDesalocado)
{

}

fila* criaFilaVazia ()
{
	fila* aux = new fila;
	aux->primeiro = NULL;
	
	return aux;
}

void inserirFinalFila (fila* filaInserir, no* noInserido)
{
	no* aux = filaInserir->primeiro;
	
	if (aux == NULL)
	{
		filaInserir->primeiro = noInserido;
		noInserido->proximo = NULL;
	}
	else
	{
		while (aux != NULL)
		{
			if (aux->proximo == NULL)
			{
				aux->proximo = noInserido;
				noInserido->proximo = NULL;
			}
			else
				aux = aux->proximo;
		}
	}
	
}

void removerInicioFila (fila* filaRemover)
{
	no* aux = filaRemover->primeiro;
	
	if (aux->proximo == NULL)
	{
		filaRemover->primeiro == NULL;
		
		desalocarNo (aux);
	}
	else
	{
		filaRemover->primeiro = aux->proximo;
		
		desalocarNo (aux);
	}
	
}

int verificaFilaVazia (fila* filaVerificada)
{
	if (filaVerificada->primeiro == NULL && filaVerificada->primeiro->informacao == NULL && filaVerificada->primeiro->proximo == NULL)
		return 1;
	else
		return 0;
}

void liberarFila (fila* filaLiberar)
{
	no* aux = filaLiberar->primeiro;
	no* aux2 = aux;
	 
	if (verificaFilaVazia (filaLiberar) == 1)
	{
		delete filaLiberar;
	}
	else
	{	
		while (aux2->proximo!=NULL)
		{
			aux2 = aux->proximo;
			
			switch (aux->id)
			{
				case RET:
				{
					delete (rectangle*) aux->id;	
				}break;
				
				case CIRC:
				{
					delete (circle*) aux->id;
				} break;
				
				case TRI:
				{
					delete (triangle*) aux->id;	
				} break;
			}
			
			delete aux;
			
			aux = aux2;
		}	
	}
}


