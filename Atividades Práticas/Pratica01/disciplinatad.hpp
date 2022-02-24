#include <iostream>
using namespace std;

typedef struct disciplina Tdisciplina;

Tdisciplina* criarDisciplina (char nome [30], char codigo [15], int carga, char curso [30], int sala);

void desalocarDisciplina (Tdisciplina* disciplina);

void preencheDisciplina (Tdisciplina* disciplina, char name [30], char code [15], int carga, char course [30], int numero);

void inserirNomeDisciplina (Tdisciplina* disciplina, char name [30]);

void inserirCodigo (Tdisciplina* disciplina, char code [15]);

void inserirCH (Tdisciplina* disciplina, int carga);

void inserirCurso (Tdisciplina* disciplina, char course [30]);

void inserirSala (Tdisciplina* disciplina, int numero);

void acessarNomeDisciplina (Tdisciplina* disciplina, char name [30]);

void acessarCodigo (Tdisciplina* disciplina, char code [15]);

int acessarCH (Tdisciplina* disciplina);

void acessarCurso (Tdisciplina* disciplina, char course [30]);

int acessarSala (Tdisciplina* disciplina);

void imprimirDisciplina (Tdisciplina* disciplina);
