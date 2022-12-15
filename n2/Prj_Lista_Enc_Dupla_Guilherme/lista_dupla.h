//lista_dupla.h
#include <iostream>
using namespace std;

struct lista2 {
	int info;
	struct lista2* ant;
	struct lista2* prox;
};
typedef struct lista2 Lista2;

Lista2* inicializa();
Lista2* insere_inicio (Lista2* l, int v);
Lista2* insere_fim(Lista2* l, int v);
void imprimir_frente_fim (Lista2* l);
void imprimir_fim_frente(Lista2* l);
bool vazia(Lista2* l);
Lista2* busca (Lista2* l, int v);
void busca_msg (Lista2* l, int v);
Lista2* retira (Lista2* l, int v);
Lista2* remove_inicio(Lista2* l);
Lista2* remove_fim(Lista2* l);
Lista2* insere_ord (Lista2* l, int v);
void encadeamentoDuplo(lista2* l);//fara o encadeamendo dos dois lados;

