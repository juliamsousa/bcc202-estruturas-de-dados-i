#include <iostream>
#include "Tcontato.hpp"
using namespace std;

typedef struct arvNo no;

 // funcao para criar no
arvNo* criaNoArvore ();

 // funcao para preencher um no
void preencheNoArvore (arvNo* no, Tcontato* informacao);

 // funcao para buscar um contato
arvNo* buscaNoArv (arvNo* r, string contato);

 // funcao para inserir um no
arvNo* arvNoInsere (arvNo* pRaiz, arvNo* no);

 // funcao para retirar um no
arvNo* arvNoRetira (arvNo* pRaiz, Tcontato* pessoa);

 // retorna um ponteiro de contato
Tcontato* retornaInfo (arvNo* no);

 // forma de impressao pre-ordem
void preOrdem (arvNo* pRaiz);

 // forma de impressao pos-ordem
void posOrdem (arvNo* pRaiz);

 // forma de impressao caminhamento central
void caminhaCentral (arvNo* pRaiz);

