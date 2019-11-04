#include <iostream>
#include "arvoreBinaria.h"

using namespace std;

int main() {
	no* r = NULL;
	int op, num, numF;

	// MENU:
	do {
		system("cls");
		cout << "# Menu:"
			"\n1) Inicializar uma arvore vazia."
			"\n2) Inserir um novo no (Recursiva)."
			"\n3) Inserir um novo no (Iterativa)."
			"\n4) Numeros de Folhas (Recursiva)."
			"\n5) Numeros de Folhas (Iterativa)."
			"\n6) Passeio em-ordem (Iterativa)."
			"\n7) Passeio pre-ordem (Iterativa)."
			"\n8) Passeio pos-ordem (Iterativa)."
			"\n9) Frequencia de um item (Recursiva)."
			"\n0) Sair."
			"\n-------------------------------------\n";

		cout << "Digite a opcao: ";
		cin >> op;

		switch (op) {
		case 0: return 0;

		case 1: arvoreVazia(r);
			break;

		case 2: cout << "Digite um Numero: ";
			cin >> num;

			if (inserirR(r, num) == true) {
				cout << "Numero Inserido com Sucesso!\n";
				system("pause");
			}
			else {
				cout << "Numero ja existe!\n";
				system("pause");
			}
			break;

		case 3: cout << "Digite um Numero: ";
			cin >> num;

			if (inserirI(r, num) == true) {
				cout << "Numero Inserido com Sucesso!\n";
				system("pause");
			}
			else {
				cout << "Numero ja existe!\n";
				system("pause");
			}
			break;

		case 4: numF = numFolhasR(r);
			cout << "Numero de Folhas: ";
			cin >> numF;
			break;

		case 5: numF = numFolhasI(r);
			cout << "Numero de Folhas: ";
			cin >> numF;
			break;

		case 6: emOrdem(r);
			break;

		case 7: preOrdem(r);
			break;

		case 8: posOrdem(r);
			break;

		case 9: //frequencia(r);
				//break;

		default: cout << "\nOpcao Errada! Digite entre 0 e 9.\n"; system("pause");
		}
	} while (op != 0);

	system("pause");
}
