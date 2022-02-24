#include <iostream>
#include "funcoesrecursivas.hpp"
using namespace std;


long int calculaPotenciacao (int base, int expoente)
{
	if (expoente<=1)
		return base;
	else
		return base * calculaPotenciacao(base, expoente-1);		
}

int inverteNumero (int numero)
{	
	if (numero < 10)
		return numero;
	else
	{
		cout<<numero%10;
		return inverteNumero (numero/10); 
	}
}

int converteBinario (int numero)
{
	if ( numero<2 ) 
        return numero;
 
    return ( 10 * converteBinario(numero/2)) + numero%2;
}
