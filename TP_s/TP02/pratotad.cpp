#include <iostream>
#include <cstddef>
#include <stddef.h>
#include <cstring>
#include <string.h>
#include <stddef.h>
#include "pratotad.hpp"
using namespace std;

struct Ingrediente 
{
	int codigo;
	char nome [20];
	ingrediente* proximo;
};

struct Prato 
{
	int codigo;
	char nome [20];
	prato* proximo;
	ingrediente* ingredientes;
};

struct Lista 
{
	prato* primeiro;
};

lista* criaLista ()
{
	// alocação dinâmica
	lista* aux = new lista;
	// aponta a lista para nulo
	aux->primeiro = NULL;
	// retorna uma lista vazia devidamente alocada
	return aux;
}

int inserirPrato (lista* menu, prato* acrescimo)
{
	prato* aux = menu->primeiro;
	
	//verifica se a lista de pratos está vazia
	if (aux == NULL)
	{
		//adiciona o prato na primeira posição da lista de pratos
		menu->primeiro = acrescimo;
		
		//aponta o prato para nulo pois não há pratos conseguintes
		acrescimo->proximo = NULL;
		
		//mostra que o prato foi inserido
		return 1;
	}
	else
	{
		//verifica onde está a última posição da lista de pratos
		while (aux != NULL)
		{
			//verifica se o prato é o último da lista de pratos
			if (aux->proximo == NULL)
			{
				//insere o acrescimo na última posição
				aux->proximo = acrescimo;
				//aponta o acrescimo para nulo pois é o último prato da lista
				acrescimo->proximo = NULL;
				//mostra que o prato foi inserido 
				return 1;
			}
			else
				//atualiza o valor do auxiliar para percorrer a lista de pratos
				aux = aux->proximo;
		}
	}
	
	return 0;
}

int retirarPrato (lista* menu, int codigoDecrescimo)
{
	// ponteiro auxiliar que recebe o primeiro item da lista de pratos
	prato* aux = menu->primeiro;
	
	// verifica se a lista de pratos está vazia
	if (aux == NULL)
		// mostra que o prato nao existe na lista
		return 0;
	// a lista de pratos não está vazia
	else
	{
		prato* anterior = aux;
		
		while (aux != NULL)
		{
			if (aux->codigo == codigoDecrescimo)
			{
				//verifica se existe apenas um prato na lista
				if (aux->proximo == NULL)
				{
					//função que desaloca o prato desejado
					desalocaPrato (aux);
					
					//mostra que o prato existe na lista e foi desalocado
					return 1;
				}
				//existe mais de um prato na lista
				else
				{
					//apontando o prato anterior para o prato proximo ao que será desalocado
					anterior = aux->proximo;
					desalocaPrato  (aux);
					//mostra que o prato existe e foi desalocado
					return 1;
				}
			}
			else
			{
				//atualizando os valores dos auxiliares para percorrer a lista de pratos
				anterior = aux;
				aux = aux->proximo;
			}
		}
	}
	//mostra que o prato nao existe na lista
	return 0;
}

void imprimirIngredientesPrato (lista* menu, int codePrato)
{
	prato* pratoImprimir;
	
	// verificação de onde está o prato a ser impresso
	pratoImprimir = encontraPratoCodigo (menu, codePrato);
	
	
	// verifica se o prato foi encontrado
	if (pratoImprimir != NULL)
	{
		// ponteiro para o primeiro ingrediente da lista de pratos
		ingrediente* componentes = pratoImprimir->ingredientes;
		
		// verifica se a lista de ingredientes está vazia
		if (componentes == NULL)
			cout<<"A lista de ingredientes esta vazia."<<endl;
		// a lista de ingredientes não está vazia
		else
		{	
			cout<<"INGREDIENTES: "<<endl;
			
			// percorre a lista de ingredientes
			while (componentes != NULL)
			{
				// imprime o nome e codigo do componente 
				cout<<"Nome do ingrediente: "<<componentes->nome<<endl;
				cout<<"Codigo do ingrediente: "<<componentes->codigo<<endl;
				// atualiza o valor da variável auxiliar para percorrer a lista de ingredientes
				componentes = componentes->proximo;
				
				cout<<endl;
			}
		}
	}
}

int adicionarIngrediente (lista* menu, int codePrato, ingrediente* adicional)
{
	// verifica se a lista de pratos esta vazia
	if (menu->primeiro == NULL)
	{
		cout<<"A lista de pratos esta vazia."<<endl;
		// mostra que não foi possível adicionar o ingrediente 
		return 0;
	}
	// a lista de pratos não está vazia
	else
	{
		// verifica onde esta o prato a receber o ingrediente adicional
		prato* pratoAdd = encontraPratoCodigo (menu, codePrato);
		
		// verifica se o prato foi encontrado
		if (pratoAdd == NULL)
		{
			cout<<"O prato nao foi encontrado."<<endl;
			// mostra que não foi possível adicionar o ingrediente 
			return 0;
		}
		// o prato foi encontrado
		else
		{
			// verifica se a lista de ingredientes do prato está vazia
			if (pratoAdd->ingredientes == NULL)
			{
				// adiciona o ingrediente a primeira posicao
				pratoAdd->ingredientes = adicional;
				// aponta o ingrediente para nulo pois não há ingrediente subsequente
				adicional->proximo = NULL;
				// mostra que o ingrediente foi adicionado com sucesso
				return 1;
			}
			// a lista de ingredientes não está vazia 
			else
			{
				// auxiliar para o primeiro ingrediente do prato
				ingrediente* aux = pratoAdd->ingredientes;
				
				while (aux != NULL)
				{
					// verifica se o ingrediente é o último da lista de ingredientes
					if (aux->proximo = NULL)
					{
						// insere o ingrediente adicional na última posição da lista de ingredientes
						aux->proximo = adicional;
						// aponta o ultimo ingrediente para nulo
						adicional->proximo = NULL;
						// mostra que o ingrediente foi adicionado com sucesso
						return 1;
					}
					// não foi achado o último ingrediente da lista
					else
					{
						// atualiza o auxiliar para percorrer a lista
						aux = aux->proximo;
					}
				}
			}	
		}
	}
}

void desalocaIngrediente (lista* menu, char nome [20], int codeIngrediente, int codePrato)
{
	prato* aux = menu->primeiro;
	
	// verifica se a lista de pratos está vazia
	if (aux == NULL) 
		cout<<"A lista de pratos esta vazia."<<endl;
	// a lista de pratos não está vazia 
	else
	{
		// procura o prato que terá um ingrediente retirado
		aux = encontraPratoCodigo (menu, codePrato);
		
		// verfica se o prato foi encontrado
		if (aux == NULL)	
			cout<<"O prato nao esta presente na lista de pratos."<<endl;
			
		// o prato está na lista de pratos
		else
		{
			// auxiliares para percorrer a lista de ingredientes
			ingrediente* aux2 = aux->ingredientes;
			ingrediente* ingAnterior = aux2;
			
			// verifica se a lista de ingredientes esta vazia
			if (aux2 == NULL)
				cout<<"A lista de ingredientes esta vazia."<<endl;
		
			// a lista de ingredientes não está vazia
			else
			{
				while (aux2 != NULL)
				{
					// verifica se o codigo ou o nome do ingrediente são iguais ao procurado
					if ((aux2->codigo == codeIngrediente) || (strcmp (nome, aux2->nome) == 0))
					{
						// verifica se existe apenas um ingrediente no prato
						if (aux2->proximo == NULL)
						{
							// desaloção do ingrediente
							delete aux2;
							// prato passa a apontar para nulo pois havia um único ingrediente
							aux->ingredientes = NULL;		
							
							cout<<"O ingrediente "<<codeIngrediente<<" foi desalocado."<<endl;
						}
						// existe mais de um ingrediente no prato
						else
						{
							// reapontando o ingediente anterior para o ingrediente proximo do que sera desalocado
							ingAnterior->proximo = aux2->proximo;
							// desalocando o ingrediente
							delete aux2;
						}		
					}
					//o nome e o código são diferentes dos procurados
					else
					{
						//atualizando os auxiliares para percorrer a lista de ingredientes
						ingAnterior = aux2;
						aux2 = aux2->proximo;
					}
				}	
			}
		}
	}
}

void imprimirMenuCompleto (lista* menu)
{
	prato* aux = menu->primeiro;
	
	// verifica se a lista de pratos está vazia
	if (aux == NULL)
		cout<<"A lista de pratos esta vazia."<<endl;
		
	// a lista de pratos não está vazia
	else
	{
		cout<<"** LISTA DE PRATOS **"<<endl;
		while (aux != NULL)
		{
			// impresão do nome, código e ingredientes do prato
			cout<<"Nome do prato: "<<aux->nome<<endl;
			cout<<"Codigo do prato: "<<aux->codigo<<endl;
			
			imprimirIngredientesPrato (menu, aux->codigo);
			
			cout<<endl;	
			
			// atuaaliza o valor do auxiliar para percorrer a lista de pratos
			aux = aux->proximo;	
		}
	}
 	
}

prato* criaPrato ()
{
	// alocação dinâmica do prato
	prato* aux = new prato;
	// aponta o ponteiro para o próximo prato para nulo
	aux->proximo = NULL;
	// aponta o ponteiro de ingredientes para nulo
	aux->ingredientes = NULL;
	
	return aux;
}

void preenchePrato (char nome [20], int code, prato* prato)
{
	prato->codigo = code;
	strcpy (prato->nome, nome);
}

void desalocaPrato (prato* prato)
{
	ingrediente* aux = prato->ingredientes;
	ingrediente* aux2 = aux;
	
	// verifica se alista de ingredientes está vazia
	if (aux == NULL)
		//desalocação do prato 
		delete prato;
	// a lista de ingredientes não está vazia
	else
	{
		// percorre a lista de ingredientes
		while (aux != NULL)
		{	
			// verifica se existe apenas um ingrediente
			if (aux->proximo == NULL)
				// desalocação do ingrediente
				delete aux;
			// existe mais de um ingrediente 
			else
			{
				// auxiliar recebe o proximo para não perder o encadeamento
				aux2 = aux->proximo;
				// desalocação do ingrediente
				delete aux;
				// atualização do auxiliar para percorrer a lista de ingredientes
				aux = aux2;
			}
		}
		
		//desalocação do prato após desalocar os ingredientes
		delete prato;
	}
}

prato* encontraPratoCodigo (lista* menu, int codigo)
{
	prato* aux = menu->primeiro;
	
	//verifica se a lista de pratos esta vazia
	if (aux == NULL)
	{
		//retorna um ponteiro para nulo
		return aux;
	}
	//a lista de pratos não está vazia
	else
	{
		while (aux != NULL)
		{
			//compara se o código do prato e o código procurado são os mesmos
			if(aux->codigo == codigo)
			{
				//retorna o prato procurado
				return aux;
			}
			else
				//atualiza o valor do auxiliar para percorrer a lista e pratos
				aux = aux->proximo;
		}
	}
	
	//retorna um ponteiro para nulo
	return aux;
}

ingrediente* criaIngrediente ()
{
	ingrediente* aux = new ingrediente;
	
	aux->proximo = NULL;
	
	return aux;
} 

void preencheIngrediente (char nome [20], int code, ingrediente* ingrediente)
{
	ingrediente->codigo = code;
	strcpy(ingrediente->nome, nome);
}
