#include <iostream>
#include <cstring>
#include "alunotad.hpp"
#include "disciplinatad.hpp"
using namespace std;

//definicao do nome da strcuct
typedef struct atestado Tatestado;

//funcao para alocar dinamicamente um tipo atestado
Tatestado* criarAtestado (int n);

//funcao para desalocar um tipo atestado
void desalocarAtestado (Tatestado* atestado, int n);

//funcao para preencher os campos de um tipo atestado aluno/conjunto de disciplinas
void preencheAtestado (Tatestado* atestado, int n);

//funcao para alterar/acessar os dados de um aluno contido em um atestado
void alterarAluno (Tatestado* atestado);

//funcao para alterar/acessar dados do conjunto de disciplinas contidas no atestado
void alterarDisciplinaAtestado (Tatestado* atestado);

//funcao para imrimir os dados do atestado na tela
void imprimirAtestado (Tatestado* atestado, int n);
