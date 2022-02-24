#include <iostream>
#include "pratotad.hpp"
#include "filaGeometrica.hpp"
using namespace std;

int main ()
{
	int op;
	
	do
	{
		cout<<"** MENU DE OPCOES **"<<endl;
		cout<<"1 - Registro de Pratos Gastronomicos"<<endl;
		cout<<"2 - Registro de Poligonos"<<endl;
		
		cin>>op;
		
		switch (op)
		{
			case 1:
			{
				int t;
				lista* menu = criaLista();
					
				do
				{
					
					
					cout<<"** REGISTRO DE PRATOS GASTRONOMICOS **"<<endl;
					cout<<"1 - Adicionar um prato com todos seus ingredientes"<<endl;
					cout<<"2 - Apagar um prato com todos os seus ingredientes"<<endl;
					cout<<"3 - Dado o codigo de um prato, imprimir sua lista de ingredientes"<<endl;
					cout<<"4 - Dado o codigo de um prato, adicionar um ingrediente"<<endl;
					cout<<"5 - Dado o codigo de um prato, eliminar um ingrediente por codigo ou nome"<<endl;
					cout<<"6 - Imprimir a lista completa de pratos e ingredientes"<<endl;
					cout<<"0 - Sair do menu"<<endl;
					cin>>t;
					
					switch(t)
					{
						case 1:
						{
							char nomePrato [20];
							int codigoPrato, qtdInicial;
							
							prato* plate = criaPrato();
							
							cout<<"Digite o nome do prato."<<endl;
							cin>>nomePrato;
							cout<<"Digite o codigo do prato."<<endl;
							cin>>codigoPrato;
							cout<<"Digite a quantidade inicial de ingredientes."<<endl;
							cin>>qtdInicial;
							
							preenchePrato (nomePrato, codigoPrato, plate);
							
							inserirPrato (menu, plate);
							
							for (int i=0; i<qtdInicial; i++)
							{
								char nomeIngrediente [20];
								int codigoIngrediente;
								ingrediente* componente = criaIngrediente ();
								
								cout<<"Digite o nome do ingrediente."<<endl;
								cin>>nomeIngrediente;
								cout<<"Digite o codigo do ingrediente"<<endl;
								cin>>codigoIngrediente;
								
								preencheIngrediente (nomeIngrediente, codigoIngrediente, componente);
								
								adicionarIngrediente(menu, codigoPrato, componente);
							}
							
		 				} break;
		 				
		 				case 2:
		 				{
		 					int codigoDecrescimo;
		 					
		 					cout<<"Digite o codigo do prato que se deseja retirar."<<endl;
		 					cin>>codigoDecrescimo;
		 					
		 					retirarPrato (menu, codigoDecrescimo);
		 					
						} break;
						
						case 3:
						{
							int codigoImprimir;
							
							cout<<"Digite o codigo do prato que deseja imprimir."<<endl;
							cin>>codigoImprimir;
							
							imprimirIngredientesPrato (menu, codigoImprimir);
						} break;
						
						case 4:
						{
							int codigoAdd;
							
							cout<<"Digite o codigo do prato que deseja adicionar um ingrediente."<<endl;
							cin>>codigoAdd;
						
							int codigoIngrediente;
							char nomeIngrediente [20];
							
							cout<<"Digite o nome do ingrediente."<<endl;
							cin>>nomeIngrediente;
							cout<<"Digite o codigo do ingrediente."<<endl;
							cin>>codigoIngrediente;
							
							ingrediente* adicional =  criaIngrediente ();

							preencheIngrediente (nomeIngrediente, codigoIngrediente, adicional);
							
							adicionarIngrediente (menu, codigoAdd, adicional);
						} break;
						
						case 5:
						{
							int codigoRemover;
							
							cout<<"Digite o codigo do prato do qual deseja remover um ingrediente."<<endl;
							cin>>codigoRemover;
							
							int t;
							
							cout<<"Deseja remover o ingrediente por nome ou codigo?"<<endl;
							cout<<"1 - Nome"<<endl;
							cout<<"2 - Codigo"<<endl;
							cin>>t;
							
							if (t == 1)
							{
								char nomeRemocao [20];
								
								cout<<"Digite o nome do ingrediente a ser removido."<<endl;
								cin>>nomeRemocao;
								
								desalocaIngrediente (menu, nomeRemocao, 0, codigoRemover);
							}
							else
							{
								int codigoRemocao;
								
								cout<<"Digite o codigo do ingrediente a ser removido."<<endl;
								cin>>codigoRemocao;
								
								desalocaIngrediente (menu, "----", codigoRemocao, codigoRemover);
							}
						} break;
						
		 				case 6:
		 				{
		 					imprimirMenuCompleto(menu);
		 					cout<<endl;
						} break;
						
					}
				} while (t != 0);
			}
			
			case 2:
			{
				int op;
				fila* filaGeometrica = criaFilaVazia();
				
				do
				{
					cout<<"** REGISTRO DE POLIGONOS **"<<endl;
					cout<<"1 - Inserir um elemento."<<endl;
					cout<<"2 - Remover um elemento."<<endl;
					cout<<"3 - Verificar se a fila esta vazia"<<endl;
					cout<<"4 - Liberar a estrutura da fila."<<endl;
				
					cin>>op;
					
					switch (op)
					{
						case 1:
						{
							int t;
							
							cout<<"Digite o tipo de elemento a ser inserido."<<endl;
							cout<<"1 - Circulo"<<endl;
							cout<<"2 - Retangulo"<<endl;
							cout<<"3 - Triangulo"<<endl;
							
							switch (t)
							{
								case 1:
								{
									double r;
									circle* circulo;
									cout<<"Digite o raio do circulo."<<endl;
									cin>>r;
									
									circulo = criaCirculo(r);
									
									inserirFinalFila (filaGeometrica, circulo);
								} break;
								
								case 2:
								{
									double b, h;
									cout<<"Digite a base e a altura do retangulo."<<endl;
									cin>>b>>h;
									
									rectangle* retangulo = criaRetangulo (b, h);
									
									inserirFinalFila (filaGeometrica, retangulo);
								} break;
								
								case 3:
								{
									double b, h;
									cout<<"Digite a base e a altura do triangulo."<<endl;
									cin>>b>>h;
									
									triangle* triangulo = criaTriangulo (b, h);
									
									inserirFinalFila (filaGeometrica, triangulo);
								}
							}
							
						} break;
						
						case 2:
						{
							removerInicioFila (filaGeometrica);
						} break;
						
						case 3:
						{
							int v;
							v = verificaFilaVazia (filaGeometrica);
							
							if (v==1)
								cout<<"A fila esta vazia."<<endl;
							else
								cout<<"A fila nao esta vazia."<<endl;
						} break;
						
						case 4:
						{
							liberarFila (filaGeometrica);
						} break;
						
					}
				} while (op != 0);
			}
		}
	} while (op != 0);
	
	return 0;
}

