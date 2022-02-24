#include <iostream>
#include <iomanip>
#include <fstream>
#define tamanho 10
using namespace std;

char** alocaLabirinto ();
void desalocaLabirinto (char **labirinto);
void inicializaLabirinto (char** labirinto);
void imprimeLabirinto (char **labirinto);

int main ()
{
	char** labirinto = alocaLabirinto;
	
	inicializaLabirinto (labirinto);
	
	imprimeLabirinto (labirinto);
	
	desalocaLabirinto (labirinto);
	
	return 0;
}

char** alocaLabirinto ()
{
	//alocacao das linhas da matriz
    char **labirinto = new char*[tamanho];
    //alocacao das colunas da matriz
    for (int i=0; i<tamanho; i++)
        labirinto[i] = new char [3];
    //retorno do ponteiro de ponteiro
    return labirinto;
}
//implemetacao da funcao desalocaMatriz
void desalocaLabirinto (char **labirinto)
{
	//desalocao das colunas da matriz
	for (int i=0; i<tamanho; i++)
       delete [] labirinto[i];
    //desalocacao das linhas da matriz
    delete [] labirinto;
}

void inicializaLabirinto (char** labirinto)
{
	//vetor de char para armazenar o nome do arquivo de entrada
	char nome [30];
	//arquivo de entrada a ser aberto para inicializar a matriz do jogo
	ifstream fileentrada;
	//solicitacao do nome do arquivo de entrada
	cout<<"Indique o arquivo texto contendo o labirinto: "<<endl;
	cin>>nome;
	//abertura do arquivo de entrada
	fileentrada.open (nome,ios::in);
	//transferencia dos dados do arquivo para o labirinto
	 if (fileentrada.is_open())
   	{
		 for (int i =0; i<tamanho; i++)
    		for (int j=0; j<tamanho; j++)
    			fileentrada>>labirinto[i][j];
	}
	//caso o arquivo nao possa ser aberto a funcao e chamada novamente
	else 
		{
			cout<<"Nao foi possivel abrir o arquivo de entrada."<<endl<<endl;
			inicializaLabirinto (labirinto);
		}
	//fechamento do arquivo de entrada
	fileentrada.close();	
}

void imprimeLabirinto (char **labirinto)
{
	for (int i=0; i<tamanho; i++)
		for (int j=0; j,tamanho; j++)
		{
			cout<<labirinto[i][j]<<" ";
			if (j==tamanho)
				cout<<endl;
		}
		
		cout<<endl;
}
