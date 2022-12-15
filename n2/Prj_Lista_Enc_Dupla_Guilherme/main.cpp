#include "lista_dupla.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(){
	cout << "##########################################" << endl;
	cout << "1- Insere inicio!" << endl;
	cout << "2- Insere fim!" << endl;
	cout << "3- Imprimir frente ao fim!" << endl;
	cout << "4- Imprimir fim ate a frente!" << endl;
	cout << "5- Remove inicio!" << endl;
	cout << "6- Remove fim!" << endl;
	cout << "7- Buscar elemento!" << endl;
	cout << "8- Remover elemento!" << endl;
	cout << "9- inserir orndenado!" << endl;
	cout << ">";
}
int main(int argc, char** argv) {
	
	Lista2* l; //ponteiro controla a lista encadeada dupla, apontando para o 1o nó-dado
	l = inicializa();
	int op(0);
	int x;
	l = insere_fim(l,1);
	l = insere_fim(l,2);
	l = insere_fim(l,3);
	do{
		menu();
		cin >> op;
		switch(op){
			case 1:
				cout << "Informe o valor:" << endl;
				cin >> x;
				l = insere_inicio(l,x);
				break;
			case 2:
				cout << "Informe o valor:" << endl;
				cin >> x;
				l = insere_fim(l,x);
				break;
			case 3:
				imprimir_frente_fim (l);
				break;
			case 4:
				imprimir_fim_frente(l);
				break;
			case 5:
				l = remove_inicio(l);
				break;
			case 6:
				l = remove_fim(l);
				break;
			case 7:
				cout << "Informe o valor:" << endl;
				cin >> x;
				busca_msg(l,x);
				break;
			case 8:
				cout << "Informe o valor:" << endl;
				cin >> x;
				l = retira(l,x);
				break;
			case 9:
				cout << "Informe o valor:" << endl;
				cin >> x;
				l = insere_ord (l,x);
				break;
		}
	}while(op>0 && op<10);
		
	return 0;
}
