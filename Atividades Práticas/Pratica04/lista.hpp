#ifndef LISTA_HPP
#define LISTA_HPP
#include <iostream>
#include <cstddef>

typedef struct lista Lista;

Lista* criaLista ();

void liberaLista (Lista* l);

void insereInicioLista (Lista* l, int v, string palavra);

void insereOrdenadoLista (Lista* l, int v);

void retiraLista (Lista* l, int v);

int listaVazia (Lista* l);

int listaPertence (Lista* l, int v);

void listaImprime (Lista* l);

#endif
