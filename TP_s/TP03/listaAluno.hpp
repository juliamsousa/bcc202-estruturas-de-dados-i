#ifndef LISTALUNO_HPP
#define LISTAALUNO_HPP
#include <iostream>
#include <cstddef>

typedef struct lista Lista;

ListaNo* criaNo ();

void desalocaNo (ListaNo* no);

Lista* criaLista ();

void liberaLista (Lista* l);

void insereInicioLista (Lista* l, int v, ListaNo* no);

void insereOrdenadoLista (Lista* l, ListaNo* inserir);

void retiraLista (Lista* l, long int matricula);

int listaVazia (Lista* l);

int listaPertence (Lista* l, long int matricula);

void listaImprime (Lista* l);

#endif
