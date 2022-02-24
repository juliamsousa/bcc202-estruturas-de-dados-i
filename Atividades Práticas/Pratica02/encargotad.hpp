#include <iostream>
#include "professortad.hpp"
#include "disciplinatad.hpp"
using namespace std;

//definicao do nome da struct
typedef struct encargo Tencargo;

//funcao para alocar dinamicamente um tipo encargo
Tencargo* criarEncargo (int n);

//funcao para desalocar um tipo encargo
void desalocarEncargo (Tencargo* encargo, int n);

//funcao para preencher os campos de um tipo encargo
void preencheEncargo (Tencargo* encargo, int n);

//funcao para alterar/acessar os dados do profesor contido no encargo
void alterarProfessor (Tencargo* encargo);

//funcao para alterar as disciplinas contidas no encargo
void alterarDisciplinaEncargo (Tencargo* encargo);

//funcao para imprimir na tela os dados do tipo encargo
void imprimirEncargo (Tencargo* encargo, int n);
