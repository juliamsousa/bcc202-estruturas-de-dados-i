#include <iostream>
#include <cstring>
using namespace std;

//definicao do nome da struct
typedef struct professor Tprofessor;

//funcao para alocar dinamicamente um tipo professor
Tprofessor* criarProfessor ();

//funcao para desalocar um tipo professor
void desalocarProfessor (Tprofessor* professor);

//funcao para preencher os campos do tipo professor
void preencheProfessor (Tprofessor* professor, long double cpf, char nome [50], char departamento [30]);

//funcao para alterar/preencher o cpf de um professor
void inserirCPFProfessor (Tprofessor* professor, long double cpf);

//funcao para alterar/preencher o nome de um professor
void inserirNomeProfessor (Tprofessor* professor, char name [50]);

//funcao para alterar/preencher o departamento de um professor
void inserirDepartamento (Tprofessor* professor, char dpt [30]);

//funcao para ler o cpf de um professor
long double acessarCPFProfessor (Tprofessor* professor);

//funcao para acessar o nome de um professor
void acessarNomeProfessor (Tprofessor* professor, char name [50]);

//funcao para ler o departamento de um professor
void acessarDepartamento (Tprofessor* professor, char dpt [30]);

//funcao para imprimir na tela os dados de um professor
void imprimirProfessor (Tprofessor* professor);
