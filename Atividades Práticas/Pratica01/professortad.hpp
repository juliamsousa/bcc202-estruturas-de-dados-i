#include <iostream>
#include <cstring>
using namespace std;

typedef struct professor Tprofessor;

Tprofessor* criarProfessor (long double cpf, char nome [50], char departamento [30]);

void desalocarProfessor (Tprofessor* professor);

void preencheProfessor (Tprofessor* professor, long double cpf, char nome [50], char departamento [30]);

void inserirCPFProfessor (Tprofessor* professor, long double cpf);

void inserirNomeProfessor (Tprofessor* professor, char name [50]);

void inserirDepartamento (Tprofessor* professor, char dpt [30]);

long double acessarCPFProfessor (Tprofessor* professor);

void acessarNomeProfessor (Tprofessor* professor, char name [50]);

void acessarDepartamento (Tprofessor* professor, char dpt [30]);

void imprimirProfessor (Tprofessor* professor);
