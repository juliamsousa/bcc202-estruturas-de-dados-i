#include <iostream>
#include <cstring>
using namespace std;

typedef struct aluno Taluno;

Taluno* criarAluno (long double cpf, char nome [50], long int matricula, char curso [30], int dd, int mm, int yy);

void desalocarAluno (Taluno* aluno);

void preencheAluno (Taluno* aluno, long double cpf, char nome [50], long int matricula, char curso [30], int dd, int mm, int yy);

void inserirCPFAluno (Taluno* aluno, long double cpf);

void inserirNomeAluno (Taluno* aluno, char nome [50]);

void inserirMatriculaAluno (Taluno* aluno, long int matricula);

void inserirCursoAluno (Taluno* aluno, char curso [30]);

void inserirDataAluno (Taluno* aluno, int dd, int mm, int yy);

long double acessarCPFAluno (Taluno* aluno);

void acessarNomeAluno (Taluno* aluno, char name [50]);

long int acessarMatriculaAluno (Taluno* aluno);

void acessarCursoAluno (Taluno* aluno, char curso [30]);

void acessarDataAluno (Taluno* aluno, int* dd, int* mm, int* yy);

void imprimirAluno (Taluno* aluno);
