#include <iostream>
#include <cstring>
using namespace std;

//definicao do nome da struct
typedef struct disciplina Tdisciplina;

//funcao para alocar dinamicamene um tipo disciplina
Tdisciplina* criarDisciplina ();

//funcao para desalocar um tipo disciplina
void desalocarDisciplina (Tdisciplina* disciplina);

//funcao para preenceher os campos de um tipo disciplina
void preencheDisciplina (Tdisciplina* disciplina, char name [30], char code [15], int carga, char course [30], int numero);

//funcao para preencehr/alterar o nome de uma disciplina
void inserirNomeDisciplina (Tdisciplina* disciplina, char name [30]);

//funcao para preencehr/alterar o codigo de uma disciplina
void inserirCodigo (Tdisciplina* disciplina, char code [15]);

//funcao para preencehr/alterar a carga horaria de uma disciplina
void inserirCH (Tdisciplina* disciplina, int carga);

//funcao para preencehr/alterar o curso de uma disciplina
void inserirCurso (Tdisciplina* disciplina, char course [30]);

//funcao para preencehr/alterar a sala de uma disciplina
void inserirSala (Tdisciplina* disciplina, int numero);

//funcao para ler o nome de uma disciplina
void acessarNomeDisciplina (Tdisciplina* disciplina, char name [30]);

//funcao para ler o codigo de uma disciplina
void acessarCodigo (Tdisciplina* disciplina, char code [15]);

//funcao para ler a carga horaria de uma disciplina
int acessarCH (Tdisciplina* disciplina);

//funcao para ler o curso de uma disciplina
void acessarCurso (Tdisciplina* disciplina, char course [30]);

//funcao para ler a sala de uma disciplina
int acessarSala (Tdisciplina* disciplina);

//funcao para imprimir na tela os dados de uma disciplina 
void imprimirDisciplina (Tdisciplina* disciplina);
