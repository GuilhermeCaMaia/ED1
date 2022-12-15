//Lista.cpp
#include "Lista.h"

/* função de inicialização: retorna uma lista vazia */
Lista* inicializa () {
	return NULL;
}

/* inserção no início: retorna a lista atualizada */
//1)
Lista* insere_inicio (Lista* l, int i) {
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}
//Mostrar o elemento do inicio da lista
//2)
void mostraInicio(Lista* l){
	if(!vazia(l)){
		Lista* p;
		cout << "Info: ";
		p = l;
		cout << p->info << endl;
	}else
		cout << "Lista vazia! \n";
}
//Mostrar o elemento do final da lista
//3)
void mostraFim(Lista* l){
	if (!vazia(l)){
		cout << "Info: ";
		Lista* p; // variável auxiliar para percorrer a lista 
		for (p = l; p != NULL; p = p->prox)
			if(p->prox == NULL){
				cout << p->info << endl;
				break;
			}
	} else
		cout << "Lista vazia! \n";
}
/* função vazia: retorna 1 se vazia ou 0 se não vazia */
//12)
bool vazia (Lista* l) {
 	return (l == NULL);
}

// função imprime: imprime valores dos elementos
//4)
void imprime (Lista* l) {
	if (!vazia(l)){
		cout << "Info: ";
		Lista* p; /* variável auxiliar para percorrer a lista */
		for (p = l; p != NULL; p = p->prox)
			cout << p->info << ", ";
		cout << endl;
	} else
		cout << "Lista vazia! \n";
}
// Mostra o tamnho da lista
//5)
void tamanho(Lista* l){
	int tam = 0;
	if(!vazia(l)){
		cout << "info: ";
		Lista* p; /* variável auxiliar para percorrer a lista */
		for (p = l; p != NULL; p = p->prox){
			tam++;
		}
		printf("Tamanho da lista:%d\n",tam);
	}else{
		cout << "Lista vazia!" << endl;
		cout << "tamnho 0!" << endl;
	}	
}

// função retira: retira elemento da lista
// 6)
Lista* retira (Lista* l, int v) {
	Lista* ant = NULL; /* ponteiro para elemento anterior */
 	Lista* p = l; /* ponteiro para percorrer a lista*/
 	/* procura elemento na lista, guardando anterior */
 	while (p != NULL && p->info != v) {
 		ant = p;
 		p = p->prox;
 	}
 	/* verifica se achou elemento */
 	if (p == NULL) {
 		cout << "Elemento " << v << " nao encontrado!\n"; 
 		return l; /* não achou: retorna lista original */
	}
 	/* retira elemento */
 	cout << "Elemento " << v << " retirado!\n"; 
	if (ant == NULL) { /* retira elemento do inicio */
 		l = p->prox;
 	}
 	else { /* retira elemento do meio da lista */
 		ant->prox = p->prox;
 	}
 	free(p);
 	return l;
}

// função busca: busca um elemento na lista
// 7)
Lista* busca (Lista* l, int v) {
	Lista* p;
 	for (p=l; p!=NULL; p=p->prox)
 		if (p->info == v){
 			cout << "Elemento " << v << " encontrado!\n";
 			return p;
		}
 	cout << "Elemento " << v << " nao encontrado!\n";		
 	return NULL; /* não achou o elemento */
}

// Mostra a frequencia que determinado numero aprarece
// 8)
Lista* ocorrencias(Lista* l, int v){
	Lista* p;
	int o = 0;
 	for (p=l; p!=NULL; p=p->prox)
 		if (p->info == v){
 			cout << "Elemento " << v << " encontrado!\n";
 			o++;
		}
		printf("A frequencia e:%d\n",o);
		return p;
 	cout << "Elemento " << v << " nao encontrado!\n";		
 	return NULL; /* não achou o elemento */
}

// Insere um elemento ao final da lista
// 9)
Lista* insereFim(Lista* l, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	Lista* p;
	int cont = 0;
	novo->info = i;
	novo->prox = NULL;
	p = l;
	while(p->prox!=NULL){
		p = p->prox;
		if(p->prox==NULL){
			p->prox = novo;
			return novo;
		}
	}
	return l;
}

// Remove um elemento do inicio da lista
// 10)
Lista* removeInicio(Lista* l){
	Lista* p;
	p=l;
	if(p->prox){
		free(p);
	}
	return l;
}


// Remove um elemento do final da lista
// 11)
Lista* removeFim(Lista* l){
	Lista* ant = NULL; /* ponteiro para elemento anterior */
	Lista* p = l; /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior */
	while (p != NULL) {
		ant = p;
		p = p->prox;
		if (p == NULL) {
			free(p);
			return l;
		}
	}
	/* verifica se achou elemento */
	return l;
}
//////////////////////////////////////////////////////////////////////////////////
void libera (Lista* l) {
	Lista* p = l;
	while (p != NULL) {
		Lista* t = p->prox; /* guarda referência para o próximo elemento*/
	 	free(p); /* libera a memória apontada por p */
	 	p = t; /* faz p apontar para o próximo */
	}
}

void libera_rec (Lista* l) { /* Libera com recursividade*/
	Lista* p = l;
	if (p != NULL) {
		Lista* t = p->prox; /* guarda referência para o próximo elemento*/
	 	free(p); /* libera a memória apontada por p */
	 	p = t; /* faz p apontar para o próximo */
	 	libera_rec (p);
	}
}

void libera_rec2 (Lista* l) { /* Libera com recursividade*/
	Lista* p = l;
	if (p != NULL) {
		libera_rec(p->prox);
		free(p); /* libera a memória apontada por p */
	}
}

