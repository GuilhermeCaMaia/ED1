#include "Lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu(){
	cout << "#######################################################\n";
	cout << "***Menu***\n";
	cout << "1-insere no inicio\n";
	cout << "2-mostra inicio\n";
	cout << "3-mostraFim\n";
	cout << "4-imprimir\n";
	cout << "5-tamanho\n";
	cout << "6-retira numero\n";
	cout << "7-Buscar numero\n";
	cout << "8-Mostrar ocorencia de um numero ocorrencias\n";
	cout << "9-insere no fim\n";//
//	cout << "10-remover do inicio\n";
//	cout << "11-remover do fim\n";
	cout << "12-verificar se a lista esta vazia\n";
	cout << "? ";	
	int op;
	cin >> op; //lendo opção do usuário
	return op;
}

int main(int argc, char** argv) {
	int op;
	int x;
	bool v;
	Lista* l; /* declara uma lista não inicializada */
	l = inicializa(); /* inicializa lista como vazia */
	l = insere_inicio(l, 1); // insere na lista o elemento 23 
	l = insere_inicio(l, 2); // insere na lista o elemento 45
	l = insere_inicio(l, 3); // insere na lista o elemento 56
//	l = insere_inicio(l, 2); // insere na lista o elemento 78
	do{
		op = menu();
 		switch(op){
 			case 1:
 				cout << "Insira o valor a ser acrecentado a lista:" << endl;
 				cin >> x;
 				l = insere_inicio(l, x);
 				break;
 			
 			case 2:
 				mostraInicio(l);
 				break;
 				
 			case 3:
 				mostraFim(l);
 				break;
 				
 			case 4:
 				imprime(l);
 				break;
 				
 			case 5:
 				tamanho(l);
 				break;
 				
 			case 6:
 				cout << "Insira o valor a ser retirado da lista:" << endl;
 				cin >> x;
 				l = retira(l,x);
 				break;
 			
 			case 7:
 				cout << "Insira o valor a ser buscado na lista:" << endl;
 				cin >> x;
 				busca(l, x);
 				break;
			
			case 8:
 				cout << "Insira o valor a ser buscado na lista:" << endl;
 				cin >> x;
 				ocorrencias(l,x);
 				break;
 			
 			case 9:
 				cout << "Insira o valor a ser acrecentado no final da lista:" << endl;
 				cin >> x;
 				l = insereFim(l, x);
 				break;
 				
 			case 10:
 				removeInicio(l);
 				break;
 				
 			case 11:
				removeFim(l);
				break;
 				
 			case 12:
 				v = vazia(l);
 				if(v==true)
 					cout << "A lista esta vazia" << endl;
 				else
 					cout << "A lista não esta vazia" << endl;
 				break;
 			
		}	
	}while(op>0 && op<13);

	/*imprime(l);
	l = insere_inicio(l, 23); // insere na lista o elemento 23 
	l = insere_inicio(l, 45); // insere na lista o elemento 45
 	l = insere_inicio(l, 56); // insere na lista o elemento 56
 	l = insere_inicio(l, 78); // insere na lista o elemento 78
 	imprime(l); // imprimirá: 78 56 45 23
	busca(l, 45);
	busca(l, 100);
	l = retira(l, 78);
	imprime(l);
	l = retira(l, 23);
	imprime(l);
	l = retira(l, 90);
	imprime(l);
	//libera(l);
	//libera_rec(l);
	libera_rec2(l);
	l = inicializa();
	imprime(l);*/
	return 0;
}
