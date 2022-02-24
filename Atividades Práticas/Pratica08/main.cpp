#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main ()
{
	string nome1, nome2;
	
	cin>>nome1>>nome2;

	 if (nome1<nome2)
	 	cout<<nome1<<" vem antes de "<<nome2;
	else cout<<nome2<<" vem antes de "<<nome1;
	
	return 0;
}

