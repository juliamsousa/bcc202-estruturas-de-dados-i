#include <iostream>
#include <cstring>
using namespace std;

//definicao do nome da struct
typedef struct aluno Taluno;

//funcao para alocar dinamicamente um tipo aluno
Taluno* criarAluno ();

//funcao para desalocar uma variavel tipo aluno	
void desalocarAluno (Taluno* aluno);

//funcao para preencher os campos do tipo aluno
void preencheAluno (Taluno* aluno, long double cpf, char nome [50], long int matricula, char curso [30], int dd, int mm, int yy);

//funcao para preencher/alterar o cpf de um aluno
void inserirCPFAluno (Taluno* aluno, long double cpf);

//funcao para preenceher/alterar o nome de um aluno
void inserirNomeAluno (Taluno* aluno, char nome [50]);

//funcao para preenceher/alterar a matricula de um aluno
void inserirMatriculaAluno (Taluno* aluno, long int matricula);

//funcao para preencher/alterar o curso de um aluno
void inserirCursoAluno (Taluno* aluno, char curso [30]);

//funcao para preencher/alterar a data de ingresso de um aluno
void inserirDataAluno (Taluno* aluno, int dd, int mm, int yy);

//funcao para ler o cpf de um aluno
long double acessarCPFAluno (Taluno* aluno);

//funcao para ler onome de um aluno
void acessarNomeAluno (Taluno* aluno, char name [50]);

//funcao para ler a matricula de um aluno
long int acessarMatriculaAluno (Taluno* aluno);

//funcao para ler o curso de um aluno
void acessarCursoAluno (Taluno* aluno, char curso [30]);

//funcao para ler a data de ingresso de um aluno
void acessarDataAluno (Taluno* aluno, int* dd, int* mm, int* yy);

//funcao para imprimir os dados de um aluno na tela
void imprimirAluno (Taluno* aluno);
