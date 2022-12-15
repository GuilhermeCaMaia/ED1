//lista_dupla.cpp
#include "lista_dupla.h"
#include <stdlib.h>

/*inicializa a lista*/
Lista2* inicializa(){
	return NULL;
}

/* inserção no início */
Lista2* insere_inicio (Lista2* l, int v){
	Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
	novo->info = v;
	novo->prox = NULL;
	novo->ant = NULL;
	/* verifica se lista não está vazia */
	if (l != NULL){
		l->ant = novo;	
	}
	return novo;
}

Lista2* insere_fim(Lista2* l, int v){
	if(vazia(l))
		return insere_inicio(l,v);
	Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
	novo->info = v;
	novo->prox = NULL;
	
	Lista2* p = l;
	for(;p->prox!=NULL;p=p->prox);
	
	novo->ant = p;
	p->prox= novo;
	
	return l;
}

void imprimir_frente_fim (Lista2* l){
	if (!vazia(l)){
		cout << "Info: ";
		Lista2* p=l;
		for(; p!=NULL; p=p->prox){
			cout << p->info << " - ";
		}
		cout << endl;
	} else cout << "Lista eh vazia!" << endl;
	
}

void imprimir_fim_frente(Lista2* l){
	if (!vazia(l)){
		cout << "Info: ";
		Lista2* p=l;
		//p=p->ant;
		for(; p->prox!=NULL; p=p->prox);//corre ate o final da lista devolvendo
		//o utimo nó
		//Lista2* aux=p;
		p->prox=l;
		l->ant = p;
		for(; p !=l; p=p->ant){//imprimir de traz para frente!
			cout << p->info << " - ";
		}
		cout << p->info << " - ";
		cout << endl;
	} else cout << "Lista eh vazia!" << endl;
}

bool vazia(Lista2* l){
	return l==NULL;
}

/* função busca: busca um elemento na lista */
Lista2* busca (Lista2* l, int v){
	if (!vazia(l)){
	 	for (Lista2* p=l; p!=NULL; p=p->prox)
	 		if (p->info == v)
	 			return p;
	}
 	return NULL; /* não achou o elemento ou a lista é vazia */
}

void busca_msg (Lista2* l, int v){
	if (busca(l, v) != NULL) //achou!
		cout << "Elemento " << v << " encontrado!\n";
	else 
		cout << "Elemento " << v << " nao encontrado!\n";
}

/* função retira: retira elemento v da lista */
Lista2* retira (Lista2* l, int v) {
 	Lista2* p = busca(l,v);
 	//1- Testa se achou?
	if (p == NULL)
 		return l; /* não achou o elemento: retorna lista inalterada */
 	
	//2- Testa casos de encontrar!
	 /* retira elemento do encadeamento */
 	if (l == p) //É o 1o nó-dado
 		l = p->prox;
 	else //É nó-dado intermediário a último
 		p->ant->prox = p->prox;
 	//Há nó-dado seguinte a p? Se sim, atualize o ant dele!	
 	if (p->prox != NULL)
 		p->prox->ant = p->ant;
 	
	free(p);
 	
 	return l;
}

Lista2* remove_inicio(Lista2* l){
	Lista2* p = l;
	if(!vazia(l)){
		if(p->prox!=NULL){	
			l=l->prox;
			free(p);
			return l;
		}else {
			free(l);
			return NULL;
		}
	}else cout << "Lista vaiza!" << endl;
}

Lista2* remove_fim(Lista2* l){
	Lista2* p = l;
	if(!vazia(l)){
		if(p->prox!=NULL){
			for(p=l;p->prox!=NULL;p=p->prox);			
			p->ant->prox=NULL;
			free(p);
			return l;
		}else {
			free(l);
			return NULL;
		}
	}else cout << "Lista vaiza!" << endl;
}

Lista2* insere_ord (Lista2* l, int v)
{
	Lista2* novo = (lista2*) malloc (sizeof(lista2));
	Lista2* p=l;
	novo->info = v;
	//Caso seja uma lista vazia
	if (vazia(l)){
		novo->prox = NULL;
		novo->ant = NULL;
		l = novo;
		return l;
	}
	else
	//Insere no inicio
	if(p->info >=novo->info){
		novo->prox = p;
		novo->prox->ant=novo;
		return novo;
	}
	else{
		//Busca a posiçao para inserir
		while(p->prox != NULL && p->prox->info < novo->info){
			p = p->prox;
		}
		novo->prox = p->prox;
		
		
		//Insere no meio
		if(p->prox != NULL){
			novo->prox->ant = novo;
			p->prox = novo;
			novo->ant = p;
		}
		
		//Insere no fim
		if(p->prox==NULL){
			novo->ant=p;
			p->prox=novo;
		}
		return l;
	}
}



/*Lista2* insere_ord(Lista2* l, int v){
	Lista2* p = l;
	//Lista2* novo = (lista2*) malloc (sizeof(lista2));
	//novo->info = v;
	//if (vazia(l)){
	//	novo->prox = NULL;
	//	novo->ant = NULL;
	//	l = novo;		
	//	return insere_inicio(l,v);
	//}
	//incere inicio
	if(p->info>=v)
		return insere_inicio(l,v);
	
	//incere no meio
//	while(p->prox != NULL && p->prox->info < novo->info){
//		p = p->prox;
//	}
//	if(p->prox != NULL){
//		novo->prox->ant = novo;
//		p->prox = novo;
//		novo->ant = p;
//		return l;
//	}else{
//		//incere fim
//		return insere_fim(l,v);
//	}		
}

Lista2* insere_ord(Lista2* l, int v){
	Lista2* novo = (lista2*) malloc (sizeof(lista2));
	Lista2* p=l;
	novo->info = v;
	//Caso seja uma lista vazia
	if (vazia(l)){
//		novo->prox = NULL;
//		novo->ant = NULL;
//		l = novo;		
		return insere_inicio(l,v);;
	}
	else
	//Insere no inicio
	if(p->info >=novo->info){
//		novo->prox = p;
//		novo->prox->ant=novo;
		return insere_inicio(l,v);;
	}
	else{
		//Busca a posiçao para inserir
		while(p->prox != NULL && p->prox->info < novo->info){
			p = p->prox;
		}
		novo->prox = p->prox;
		//Insere no meio
		if(p->prox != NULL){
			novo->prox->ant = novo;
			p->prox = novo;
			novo->ant = p;
		}	
		//Insere no fim
		if(p->prox==NULL){
			novo->ant=p;
			p->prox=novo;
		}
		return insere_fim(l,v);
	}
}*/
