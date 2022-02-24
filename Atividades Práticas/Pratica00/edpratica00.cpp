#include <iostream>
#include <iomanip>
#include <cmath>
#define rad 0.0174532925;
using namespace std;

// prototipo das funcoes
long double calcFatorial (int n);
double calcRad (int x);
void calcCosx (int z);

void calcRend (int n);

int** alocaMatriz (int linhas, int colunas);
void desalocaMatriz (int linhas, int colunas, int **matriz);
void preencheMatriz (int linhas, int colunas, int **matriz);

// definicao da struct
typedef struct maiormenor
{
	int maior;
	int menor;
	double media;
} Tmaiormenor; 

// prototipo de funcao
Tmaiormenor maiorMenor (int linhas, int colunas, int **matriz);

int main ()
{
    int op;
    cin>>op;

	while (op>=1 && op<=4)
	{
    	switch (op)
    	{
        	case 1:
        	{
            	int z;
            	cin>>z;
							// 
            	calcCosx(z); 
        	}
        	break;
        
        	case 2: 
        	{
        		int n;
        	
        		cin>>n;
        	
        		calcRend (n);
			}
			break;
		
			case 3:
			{
				int n, linhas, colunas;
			
				cin>>n;
			
				for (int i=0; i<n; i++)
				{
					int **matriz;
					Tmaiormenor tmm;
				
					cin>>linhas>>colunas;
					
					matriz = alocaMatriz(linhas, colunas);
					preencheMatriz(linhas, colunas, matriz);
					tmm=maiorMenor (linhas, colunas, matriz);
				
					cout<<tmm.maior<<" "<<tmm.menor<<" "<<fixed<<setprecision(3)<<tmm.media<<endl;
				
					desalocaMatriz (linhas, colunas, matriz);
				}
			
			}
			break;
		
			case 4:
			{
				int n, a;
				int **matriz;

				cin>>n>>a;
			
				matriz=alocaMatriz (a+1, n+2);
			
	
				for (int j=0; j<n; j++)
					cin>>matriz[0][j];
		
				for (int i=1; i<=a; i++)
				{
					for (int j=0; j<n; j++)
						cin>>matriz[i][j];

					cin>>matriz[i][n];
				}
			
				for (int i=1; i<a+1; i++)
				{
					matriz[i][n+1]=0;
						
					for (int j=0; j<n; j++)
						if (matriz[i][j]==matriz[0][j])
							matriz[i][n+1]++;
				
					cout<<matriz[i][n]<<" "<<matriz[i][n+1]<<endl;
				}
			
				desalocaMatriz(n+2, a+1, matriz);
			}	
			break;
    	}
    	
    	cin>>op;
	}
	
    return 0;
}

long double calcFatorial (int n)
{
    long double prod = 1;

    while (n>=1)
    {
        prod *= n;
        n -= 1;        
    }

    return prod;
}

double calcRad (int x)
{
    double xrad;

    xrad = x*rad;

	return xrad;
}
   
void calcCosx (int z)
{
    double cosx=1, x;
    int sinal = -1, p = 2, n;

    for (int i=0; i<z; i++)
    {
        cin>>x;
        cin>>n;

        for (int j=0; j<n; j++)
        {
            cosx += pow (calcRad(x),p)/calcFatorial(p)*sinal;
            sinal *= -1;
            p += 2;
        }
        
        cout<<setprecision(2)<<fixed<<calcRad (x)<<" ";
        cout<<n<<" ";
        cout<<setprecision(5)<<fixed<<cosx<<" "<<endl;
    
        p=2;
        cosx=1;    
        sinal=-1;
    }
}

void calcRend (int n)
{
	
	double xa, da, ra, xb, rb;
	int m, cont=0; 
	
	for (int i=0; i<n; i++)
	{
		cin>>xa>>da>>ra>>xb>>rb>>m;
		
		if (ra>rb)
			cout<<"Rendimento de B invalido"<<endl;
		else
		{	
			ra/=100;
			rb/=100;
			
			for (int j=0; j<m; j++)
			{
				xa+=xa*ra+da;
				xb*=(1+rb);
 
				if (xb<=xa)
					cont++;
			}	
			
			cout<<xa<<" "<<fixed<<setprecision(2)<<xb<<" ";
			
			if (m-cont==0)
				cout<<"B nao supera A"<<endl;
			else
			if (m-cont>0)
				cout<<cont+1<<endl;		
		}
		
		cont=0;
	}	
}

int** alocaMatriz (int linhas, int colunas)
{
    int **matriz = new int*[linhas];
    
    for (int i=0; i<linhas; i++)
        matriz[i] = new int [colunas];
    
    return matriz;
}

void preencheMatriz (int linhas, int colunas, int **matriz)
{
	for (int i=0; i<linhas; i++)
		for (int j=0; j<colunas; j++)
			cin>>matriz[i][j];
}

void desalocaMatriz (int linhas, int colunas, int **matriz)
{
	for (int i=0; i<linhas; i++)
       delete [] matriz[i];

    delete [] matriz;
}

Tmaiormenor maiorMenor (int linhas, int colunas, int **matriz)
{
	int soma=0;
	Tmaiormenor mm;
	
	mm.maior=matriz[0][0];
	mm.menor=matriz[0][0];
	
	for (int i=0; i<linhas; i++)
		for (int j=0; j<colunas; j++)
		{
			if (matriz[i][j]<mm.menor)
				mm.menor=matriz[i][j];
				
			if (matriz[i][j]>mm.maior)
				mm.maior=matriz[i][j];
				
			soma+=matriz[i][j];
		}
	
	mm.media=soma*1.0/(linhas*colunas);
	
	return mm;
}
