#include <iostream>
#include "imprimenaturais.hpp"
using namespace std;

void imprimeNaturaisIterativa (int n)
{
	for (int i=0; i<=n; i++)
		cout<<i<<", ";
}

int imprimeNaturaisRecursiva (int n)
{
	 if(n == -1) 
		return 0;

	1 + imprimeNaturaisRecursiva (n - 1);
	cout<<n<<", ";
}
