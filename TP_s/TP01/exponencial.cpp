#include <iostream>
#include <cmath>
#include "exponenciacaoRecursiva.hpp"
using namespace std;

//funcao para calcular exponencial de forma recursiva
float exponenciacaoRecursiva (int base, int expoente)
{	
	float potencia;
	
	//caso base
	if (expoente == 0)
		return 1;
	
	//chamada para quando o expoente e par
	if (expoente%2 == 0)
	{
		potencia = exponenciacaoRecursiva(base, expoente/2);
		return potencia*potencia; 
	}
	
	//chamada para quando o expoente e impar
	if (expoente%2 != 0)
	{
		potencia = exponenciacaoRecursiva (base, expoente/2);
		return potencia*potencia*base;
	}

}	
