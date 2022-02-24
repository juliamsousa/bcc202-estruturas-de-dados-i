#include <iostream>
using namespace std;

int main()
{
	int* aux = new int;
	int b = 25;
	
	delete aux;
	
	aux = &b;
	cout<<*aux<<endl;
	
	return 0;
}
