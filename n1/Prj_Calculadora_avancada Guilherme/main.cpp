#include <iostream> //bib padrão c++ e/s de dados
#include "calculadora.h" //bib própria!
#include "calculadora_av.h" //bib própria!
#include "teste_num.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu(){
	cout << "Calculadora:\n";
	cout << "1-Soma\n";
	cout << "2-Subtracao\n";
	cout << "3-Multiplicacao\n";
	cout << "4-Divisao\n";
	cout << "5-Potencia\n";
	cout << "6-Raiz quadrada\n";
	cout << "7-Par ou impa\n";
	cout << "8-numero primo\n";
	cout << "? ";	
	int op;
	cin >> op; //lendo opção do usuário
	return op;
}

float obter_num(int n){
	cout << "Digite n" << n << ": ";
	float r;
	cin >> r;
	return r; 
}

int main(int argc, char** argv) {
	int op(0);
	float resp, n1, n2;
	bool b;
	do{
		op = menu();
		switch (op){
			case 1:
				//soma
				n1 = obter_num(1);
				n2 = obter_num(2);
				resp = soma(n1, n2);
				cout << "Soma eh: " << resp << endl;
				break;
			case 2:
				//subtracao
				n1 = obter_num(1);
				n2 = obter_num(2);
				resp = subtracao(n1, n2);
				cout << "Subtracao eh: " << resp << endl;
				break;	
			case 3:
				//multiplicacao
				n1 = obter_num(1);
				n2 = obter_num(2);
				resp = multiplicacao(n1, n2);
				cout << "Multiplicacao eh: " << resp << endl;
				break;
			case 4:
				//divisão
				n1 = obter_num(1);
				n2 = obter_num(2);
				resp = divisao(n1, n2);
				cout << "Divisao eh: " << resp << endl;
				break;
			case 5:
				//potencia
				n1 = obter_num(1);
				n2 = obter_num(2);
				resp = potencia(n1, n2);
				cout << "Potencia eh: " << resp << endl;
				break;
			case 6:
				//raiz
				n1 = obter_num(1);
				resp = raiz(n1);
				cout << "Raiz quadrada eh: " << resp << endl;
				break;
			case 7:
				//par ou impa
				n1 = obter_num(1);
				resp = par_impa(n1);
				break;
			case 8:
				//primo
				n1 = obter_num(1);
				resp = primo(n1);
				break;			
			default:
				//fim de programa
				cout << "Fim de programa!\n";			
		}	
		b = (op<=6) && (op>=1);
	} while(b);
	
	//system("pause");
	
	return 0;
}
