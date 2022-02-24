#ifndef LISTA_HPP
#define LISTA_HPP
typedef struct lista Lista;
typedef struct listano Listano;
typedef struct lista_ult Lista_ult;
Lista* lista_criar ();
void lista_liberar (Lista* l);
void lista_inserir (Lista* l, int v);
void lista_insere_ordenado (Lista* l, int v);
void lista_retirar (Lista* l, int v);
int lista_vazia (Lista* l);
int lista_pertence (Lista* l, int v);
void lista_imprime (Lista* l);
void lista_insere_ultima_posicao (Lista *l);
int lista_retira_ultima_posicao (Lista *l);
#endif
