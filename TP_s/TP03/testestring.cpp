#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
using namespace std;

int main ()
{
	char nome1 [40];
	char nome2 [40];
	
	cin.getline(nome1, 40);
	cin.getline(nome2, 40);
	
	cout<<nome1<<endl;
	cout<<nome2<<endl;
	
	int p = strcmp(nome1, nome2);
	
	cout<<p<<endl;
	
	return 0;
}
