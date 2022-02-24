#include <iostream>
#include <cstddef>
#include <stddef.h>
using namespace std;

enum tipo
{
	RET,
	TRI, 
	CIRC
};

typedef enum tipo figura;

typedef struct circle circulo;

typedef struct rectangle retangulo;

typedef struct triangle triangulo;

// operações relacionadas ao tipo círculo
circle* criaCirculo (float r);

void preencheCirculo (circle* circuloPreencher, double r);

void acessaRaioCirculo (circle* circuloAcessa, double r);

// operações relacionadas ao tipo retângulo
rectangle* criaRetangulo (float b, float h);

void acessaBaseRetangulo (rectangle* retanguloBase, double base);

void acessaAlturaRetangulo (rectangle* retanguloAltura, double height);

// operações relacionadas ao tipo triângulo
triangle* criaTriangulo (float b, float h);

void acessaBaseTriangulo (triangle* trianguloBase, double base);

void acessaAlturaTriangulo (rectangle* trianguloAltura, double height);

// operacoes relacionadas a fila
typedef struct no No;

typedef struct fila Fila;

fila* criaFilaVazia ();

void inserirFinalFila (fila* listaInserir, no* noInserido);

void removerInicioFila (fila* filaRemover);

int verificaFilaVazia (fila* filaVerificada);

void liberarFila (fila* filaLiberar);

