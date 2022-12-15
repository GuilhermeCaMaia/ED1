//Aula ED - prof. Irineu
//lista_simples_circular.h
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct lista {
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa();

bool vazia(Lista* l);

Lista* insere_inicio(Lista* l, int i);

Lista* insere_fim(Lista* l, int i);

void imprime(Lista* l);

Lista* retira(Lista* l, int v);

void mostraInicio(Lista* l);

void mostraFim(Lista* l);

int tamanho(Lista* l);

int ocorrencias(Lista* l,int v);
