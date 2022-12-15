//Aula ED - prof. Irineu
#include "lista_simples_circular.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(){
	cout << "\n#####################################################" << endl;
	cout << "Escolha uma das opsoes seguintes:" << endl;
	cout << "1- Insere no inicio!" << endl;
	cout << "2- Insere no fim!" << endl;
	cout << "3- imprime!" << endl;
	cout << "4- Retirar valor!" << endl;
	cout << "5- mostra inicio!" << endl;
	cout << "6- mostra fim!" << endl;
	cout << "7- mostra tamanho!" << endl;
	cout << "8- mostrar ocorencia!" << endl;
	cout << "9- remove do inicio!" << endl;
	cout << "10- remove do fim!" << endl;
	//cout << "" << endl;
}
int main(int argc, char** argv) {
	int op(0);
	int x;
	Lista* l; /* declara uma lista não inicializada - deverá apontar sempre para nó final*/
	l = inicializa(); /* inicializa lista como vazia */
	l = insere_inicio(l, 23); /* insere_inicio na lista o elemento 23 */
	l = insere_inicio(l, 45); /* insere_inicio na lista o elemento 45 */
	l = insere_fim(l, 50); /* insere_fim na lista o elemento 50 */
	l = insere_fim(l, 51); /* insere_fim na lista o elemento 50 */
	l = insere_fim(l, 50);
	
	do{
		menu();
		cin >> op;
		switch(op){
			case 1:
				cout << "Informe o valor:" << endl;
				cin >> x;
				insere_inicio(l, x);
				break;
			case 2:
				cout << "Informe o valor:" << endl;
				cin >> x;
				insere_fim(l, x);
				break;
			case 3:
				imprime(l);
				break;
			case 4:
				cout << "Informe o valor a ser retirado:" << endl;
				cin >> x;
				retira(l, x);
			case 5:
				mostraInicio(l);
				break;
			case 6:
				mostraFim(l);
				break;
			case 7:
				x = tamanho(l);
				printf("%d",x);
				break;
			case 8:
				cin >> x;
				x = ocorrencias(l,x);
				printf("%d",x);
		}
	}while(op>0 && op<11);
	return 0;
}
