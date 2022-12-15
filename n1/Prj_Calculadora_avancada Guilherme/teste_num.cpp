//teste_num.cpp
#include "teste_num.h"

int par_impa(int n1){
	n1 = n1%2;
	if(n1==0){
		return printf("eh par");
	}
	else{
		return printf("eh impar");
	}
}

float primo(float n1){
	float r=0;
	for(int i=1;i<=n1;i++){
		if((int)n1%i==0){
			r++;
		}
		if(r<=2){
			return printf("é primo");
		}
		else{
			return printf("nao eh primo");
		}
	}
}
