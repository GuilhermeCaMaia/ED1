//lista_dupla_circular.cpp
#include "lista_dupla_circular.h"

Lista2* inicializa(){
	return NULL;
}
Lista2* insere_inicio(Lista2* l, int v){
	Lista2* novo = (Lista2*) malloc(sizeof(Lista2*));
	novo->info = v;
	
	if(l==NULL){
		novo->prox=novo;
		novo->ant=novo;
	}else{
		novo->prox=l;
		novo->ant=l->ant;
		l->ant->prox=novo;
		l->ant=novo;
	}
	return novo;
}

Lista2* Insere_fim(Lista2* l,int v){
	Lista2* novo = (Lista2*) malloc(sizeof(Lista2*));
	novo->info = v;
	
	if(l==NULL){
		novo->prox=novo;
		novo->ant=novo;
		return novo;
	}else{
		novo->prox=l;
		l->ant->prox= novo;
		novo->ant=l->ant;
		l->ant=novo;
		
		return l;
	}
}

void Imprime_frente_fim(Lista2* l){
	Lista2* p = l;
	if(l!=NULL){
		do{
			cout << p->info << " - ";
			p = p->prox;
		}while(p!=l);
		cout << endl;
	}else
		cout << "Lista vaiza!" << endl;
}

void Imprime_reverso(Lista2* l){
	Lista2* p = l;
	if(l!=NULL){
		do{
			p = p->ant;
			cout << p->info << " - ";	
		}while(p!=l);
		cout << endl;
	}else
		cout << "Lista vaiza!" << endl;
}

Lista2* Remove_inicio(Lista2* l){
	Lista2* p = l;
	if(l==NULL){
		printf("Lista vazia ja esta vazia!\n");
		return NULL;
	}
	if(p->prox==p){
		free(p);
		return NULL;
	}else{
		l=l->prox;
		p->ant->prox=l;
		l->ant=p->ant;
		free(p);
		return l;
	}
}

Lista2* Remove_fim(Lista2* l){
	Lista2* p = l;
	if(l==NULL){
		printf("Lista vazia ja esta vazia!\n");
		return NULL;
	}
	if(p->prox==p){
		free(p);
		return NULL;
	}else{
		p=p->ant;
		l->ant=p->ant;
		p->ant->prox=l;
		free(p);
		return l;
	}
}

Lista2* Remove_valor(Lista2* l,int v){
	Lista2* p = l;
	if(l==NULL){
		printf("Lista vazia ja esta vazia!\n");
		return NULL;
	}
	if(p->prox==p){
		free(p);
		return NULL;
	}else{
		do{//busca!
			if(p->info==v)
				break;
			p=p->prox;
		}while(p!= l);
		if(p->info != v){
			cout << "valor nao encontrado!" << endl;
			return l;
		}
		if(p==l){//remove inicio
//			l=l->prox;
//			p->ant->prox=l;
//			l->ant=p->ant;
//			free(p);
//			return l;
			return Remove_inicio(l);
		}
		if(p!=l && l->ant!=p){//remove meio
			p->ant->prox=p->prox;
			p->prox->ant=p->ant;
			free(p);
			return l;
		}
		if(l->ant==p){//remove fim
//			l->ant=p->ant;
//			p->ant->prox=l;
//			free(p);
//			return l;
			return Remove_fim(l);
		}
	}
}
