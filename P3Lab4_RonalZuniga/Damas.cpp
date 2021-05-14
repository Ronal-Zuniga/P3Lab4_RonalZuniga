#include "Damas.h"
#include <iostream>
using namespace std;

Damas::Damas() {
	prepararTablero();
}

Damas::~Damas() {
	freeTablero();
}

void Damas::freeTablero() {
	if(tablero != NULL) {
		for(int i = 0; i < 8; i++) {
			delete[] tablero[i];
		}
		delete[] tablero;
		tablero=NULL;
	}
}

void Damas::prepararTablero() {
	if(tablero != NULL) {
		freeTablero();
	}
	tablero = new Casilla**[8];
	for(int i = 0; i < 8; i++) {
		tablero[i] = new Casilla*[8];
	}
	
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			bool entra = false;
			Pieza* p;
			Casilla* cs;
			if(i <= 2 && ((i + j) % 2 == 0)) {
				p = new Pieza(false, true);
				cs = new Casilla(p);
				tablero[i][j] = cs;
				entra = true;
			} else if (i >= 5 && ((i + j) % 2 == 0)) {
				p = new Pieza(false, false);
				cs = new Casilla(p);
				tablero[i][j] = cs;
				entra = true;
			} 
			if(!entra){
				cs = new Casilla();
				tablero[i][j] = cs;
			}
		}
	}
}// fin metodo crear tablero

void Damas::imprimirTablero() {
	cout << endl;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			cout << "[ " << tablero[i][j]->toString() << " ] ";
		}
		cout << endl;
	}

}//fin metodo imprimir