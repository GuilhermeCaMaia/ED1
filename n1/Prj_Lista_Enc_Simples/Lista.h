//Lista.h
#include <iostream>
#include <stdlib.h>

using namespace std;

struct lista {
	int info;
	struct lista* prox;
};
typedef struct lista Lista; //tipo nó-dado "Lista"

Lista* inicializa ();
Lista* insere_inicio (Lista* l, int i);
void mostraInicio(Lista* l);
void mostraFim(Lista* l);//
bool vazia (Lista* l);
void imprime (Lista* l);
void tamanho(Lista* l);
Lista* retira (Lista* l, int v);
Lista* busca (Lista* l, int v);
Lista* ocorrencias(Lista* l, int v);
Lista* insereFim(Lista* l, int i);
Lista* removeInicio(Lista* l);
Lista* removeFim(Lista* l);
void libera (Lista* l);
void libera_rec (Lista* l); 
void libera_rec2 (Lista* l); 

