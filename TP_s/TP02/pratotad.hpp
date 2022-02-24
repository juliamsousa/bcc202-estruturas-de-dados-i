#include <iostream>
#include <cstddef>
#include <stddef.h>
#include <cstring>
#include <string.h>
#include <stddef.h>
using namespace std;

typedef struct Lista lista;

typedef struct Prato prato;

typedef struct Ingrediente ingrediente;

lista* criaLista ();

int inserirPrato (lista* menu, prato* acrescimo);

int retirarPrato (lista* menu, int codigoDecrescimo);

void imprimirIngredientesPrato (lista* menu, int codePrato);

int adicionarIngrediente (lista* menu, int codePrato, ingrediente* adicional);

void desalocaIngrediente (lista* menu, char nome [20], int codeIngrediente, int codePrato);

void imprimirMenuCompleto (lista* menu);

prato* criaPrato ();

void preenchePrato (char nome [20], int code, prato* prato);

void desalocaPrato (prato* prato);

prato* encontraPratoCodigo (lista* menu, int codigo);

ingrediente* criaIngrediente ();

void preencheIngrediente (char nome [20], int code, ingrediente* ingrediente);
