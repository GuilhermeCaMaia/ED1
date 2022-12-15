#include "lista_dupla_circular.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(){
	cout << "##########################################" << endl;
	cout << "##############   MENU   ##################" << endl;
	cout << "##########################################" << endl;
	cout << "1- Insere inicio!" << endl;
	cout << "2- Insere fim!" << endl;
	cout << "3- Remove inicio!" << endl;
	cout << "4- Remove Fim!" << endl;
	cout << "5- Remover valor!" << endl;
	cout << "6- imprimir!" << endl;
	cout << "7- imprimir reverso!" << endl;
	cout << ">";
}
int main(int argc, char** argv) {
	Lista2* l;
	int x;
	int op(0);
	l = inicializa();
	l=insere_inicio(l,1);
	l=Insere_fim(l,2);
	l=Insere_fim(l,3);
	do{
		menu();
		cin >> op;
		switch(op){
			case 1:
				cout << "Informe o valor:" << endl;
				cin >> x;
				l=insere_inicio(l,x);
				break;
			case 2:
				cout << "Informe o valor:" << endl;
				cin >> x;
				l=Insere_fim(l,x);
				break;
			case 3:
				l = Remove_inicio(l);
				break;
			case 4:
				l = Remove_fim(l);
				break;
			case 5:
				cout << "Informe o valor:" << endl;
				cin >> x;
				l = Remove_valor(l,x);
				break;
			case 6:
				Imprime_frente_fim(l);
				break;
			case 7:
				Imprime_reverso(l);
				break;
			default:
				cout << "opcao invalida!" << endl;
				break;
		}
	}while(op>0 && op<8);
	return 0;
}
