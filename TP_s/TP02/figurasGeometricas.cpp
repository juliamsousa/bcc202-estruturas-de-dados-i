#include <iostream>
#include "figurasGeometricas.hpp"
using namespace std;

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

circle* criaCirculo ()
{
	circle* aux = new circle;
	
	return aux;
}

void desalocaCirculo (circle* circuloApagar)
{
	delete circuloApagar;
}

void preencheCirculo (circle* circuloPreencher, double r)
{
	circuloPreencher->raio = r;
}

void acessaRaioCirculo (circle* circuloAcessa, double r)
{
	r = circuloAcessa->raio;
}

rectangle* criaRetangulo ()
{
	rectangle* aux = new rectangle;
	
	return aux;
}

void desalocaRetangulo (rectangle* retanguloApagar)
{
	delete retanguloApagar;
}

void preencheRetangulo (rectangle* retanguloPreencher, float base, float height)
{
	retanguloPreencher->altura = height;
	retanguloPreencher->base = base;
}

void acessaBaseRetangulo (rectangle* retanguloBase, double base)
{
	base = retanguloBase->base;
}

void acessaAlturaRetangulo (rectangle* retanguloAltura, double height)
{
	height = retanguloAltura->altura;
}

triangle* criaTriangulo ()
{
	triangle* aux = new triangle;
	
	return aux;
}

void desalocaTriangulo (triangle* trianguloApagar)
{
	delete trianguloApagar;
}

void preencheTriangulo (triangle* trianguloPreencher, float base, float height)
{
	trianguloPreencher->altura = height;
	trianguloPreencher->base = base;
}

void acessaBaseTriangulo (triangle* trianguloBase, double base)
{
	base = trianguloBase->base;
}

void acessaAlturaTriangulo (rectangle* trianguloAltura, double height)
{
	height = trianguloAltura->altura;
}
