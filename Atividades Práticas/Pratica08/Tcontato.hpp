#include <iostream>
#include <string>
using namespace std;

typedef struct contato Tcontato;

 // funcao para criar um contato
contato* criaContato ();

 // funcao para preencher os campos de um contato
void preencheContato (contato* pessoa, string name, long int phone, int day, int month, int year);

 // funcao para imprimir os campos do contato
void imprimirContato (contato* pessoa);

 // funcao para desalocar um contato
void desalocaContato (contato* pessoa);

 // funcao para alterar nome do contato
void alteraNome (contato* pessoa, string name);

 // funcao para alterar o telefone de um contato
void alteraTelefone (contato* pessoa, long int phone);

 // funcao para alterar o dia de aniversario do contato
void alteraDia (contato* pessoa, int day);

 // funcao para alterar o mes de aniversario do contato
void alteraMes (contato* pessoa, int month);

 // funcao para alterar o ano de aniversario do contato
void alteraAno (contato* pessoa, int year);

 // funcao para acessar o nome do contato
string acessaNome (contato* pessoa);

 // funcao para acessar o telefone do contato
long int acessaTelefone (contato* pessoa);

 // funcao para acesar o dia de aniverasrio do contato
int acessaDia (contato* pessoa);

 // fucncao para acessar o mes de aniversario do contato
int acessaMes (contato* pessoa);

 // funcao para acessar o ano de aniversario do contato
int acessaAno (contato* pessoa);
