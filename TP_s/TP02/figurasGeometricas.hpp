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

// opera��es relacionadas ao tipo c�rculo
circle* criaCirculo ();

void desalocaCirculo (circle* circuloApagar);

void preencheCirculo (circle* circuloPreencher, double r);

void acessaRaioCirculo (circle* circuloAcessa, double r);

// opera��es relacionadas ao tipo ret�ngulo
rectangle* criaRetangulo ();

void desalocaRetangulo (rectangle* retanguloApagar);

void preencheRetangulo (rectangle* retanguloPreencher, float base, float height);

void acessaBaseRetangulo (rectangle* retanguloBase, double base);

void acessaAlturaRetangulo (rectangle* retanguloAltura, double height);

// opera��es relacionadas ao tipo tri�ngulo
triangle* criaTriangulo ();

void desalocaTriangulo (triangle* trianguloApagar);

void preencheTriangulo (triangle* trianguloPreencher, float base, float height);

void acessaBaseTriangulo (triangle* trianguloBase, double base);

void acessaAlturaTriangulo (rectangle* trianguloAltura, double height);
