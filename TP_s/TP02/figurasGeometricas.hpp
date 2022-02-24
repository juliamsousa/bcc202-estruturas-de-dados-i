#include <iostream>
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
circle* criaCirculo ();

void desalocaCirculo (circle* circuloApagar);

void preencheCirculo (circle* circuloPreencher, double r);

void acessaRaioCirculo (circle* circuloAcessa, double r);

// operações relacionadas ao tipo retângulo
rectangle* criaRetangulo ();

void desalocaRetangulo (rectangle* retanguloApagar);

void preencheRetangulo (rectangle* retanguloPreencher, float base, float height);

void acessaBaseRetangulo (rectangle* retanguloBase, double base);

void acessaAlturaRetangulo (rectangle* retanguloAltura, double height);

// operações relacionadas ao tipo triângulo
triangle* criaTriangulo ();

void desalocaTriangulo (triangle* trianguloApagar);

void preencheTriangulo (triangle* trianguloPreencher, float base, float height);

void acessaBaseTriangulo (triangle* trianguloBase, double base);

void acessaAlturaTriangulo (rectangle* trianguloAltura, double height);
