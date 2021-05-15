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
			if(!entra) {
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

bool Damas::validarMovimiento(int x1, int y1, int x2, int y2, Casilla*& cs) {
	bool esValido = false;
	if(cs->getPieza() != NULL) {
		if(cs->getPieza()->getBando()) {
			if(cs->getPieza()->getReina()) {
				if(tablero[x1+1][y1-1]->getPieza()->getBando() == false
				        && x2 == x1+2 && y2 == y1-2 &&
				        tablero[x2][y2]->getPieza() == NULL) {
					esValido = true;
				}
				if(tablero[x1+1][y1+1]->getPieza()->getBando() == false
				        && x2 == x1+2 && y2 == y1+2 &&
				        tablero[x2][y2]->getPieza() == NULL) {
					esValido = true;
				}
				if(tablero[x1-1][y1+1]->getPieza()->getBando() == false
				        && x2 == x1-2 && y2 == y1+2 &&
				        tablero[x2][y2]->getPieza() == NULL) {
					esValido = true;
				}
				if(tablero[x1-1][y1-1]->getPieza()->getBando() == false
				        && x2 == x1-2 && y2 == y1-2 &&
				        tablero[x1-2][y1-2]->getPieza() == NULL) {
					esValido = true;
				}
			} else {
				if(tablero[x1+1][y1-1]->getPieza()->getBando() == false
				        && x2 == x1+2 && y2 == y1-2 &&
				        tablero[x2][y2]->getPieza() == NULL) {
					esValido = true;
				}
				if(tablero[x1+1][y1+1]->getPieza()->getBando() == false
				        && x2 == x1+2 && y2 == y1+2 &&
				        tablero[x2][y2]->getPieza() == NULL) {
					esValido = true;
				}
			}
		} else {
			if(cs->getPieza()->getReina()) {
				if(tablero[x1+1][y1-1]->getPieza()->getBando()
				        && x2 == x1+2 && y2 == y1-2 &&
				        tablero[x2][y2]->getPieza() == NULL) {
					esValido = true;
				}
				if(tablero[x1+1][y1+1]->getPieza()->getBando()
				        && x2 == x1+2 && y2 == y1+2 &&
				        tablero[x2][y2]->getPieza() == NULL) {
					esValido = true;
				}
				if(tablero[x1-1][y1+1]->getPieza()->getBando()
				        && x2 == x1-2 && y2 == y1+2 &&
				        tablero[x2][y2]->getPieza() == NULL) {
					esValido = true;
				}
				if(tablero[x1-1][y1-1]->getPieza()->getBando()
				        && x2 == x1-2 && y2 == y1-2 &&
				        tablero[x2][y2]->getPieza() == NULL) {
					esValido = true;
				}
			} else {
				if(tablero[x1-1][y1+1]->getPieza()->getBando()
				        && x2 == x1-2 && y2 == y1+2 &&
				        tablero[x2][y2]->getPieza() == NULL) {
					esValido = true;
				}
				if(tablero[x1-1][y1-1]->getPieza()->getBando()
				        && x2 == x1-2 && y2 == y1-2 &&
				        tablero[x2][y2]->getPieza() == NULL) {
					esValido = true;
				}
			}
		}
	}
	return esValido;
}//fin metodo validar movimiento

void Damas::capturar(int x1, int y1, int x2, int y2, Casilla*& cs) {
	if(validarMovimiento(x1, y1, x2, y2, cs)) {
		if(cs->getPieza() != NULL) {
			if(cs->getPieza()->getBando()) {
				if(cs->getPieza()->getReina()) {
					if(tablero[x1+1][y1-1]->getPieza()->getBando() == false
					        && x2 == x1+2 && y2 == y1-2 &&
					        tablero[x2][y2]->getPieza() == NULL) {
						tablero[x1+1][y1-1] = new Casilla();
						tablero[x1][y1] = new Casilla();
						tablero[x2][y2] = cs;
					}
					if(tablero[x1+1][y1+1]->getPieza()->getBando() == false
					        && x2 == x1+2 && y2 == y1+2 &&
					        tablero[x2][y2]->getPieza() == NULL) {
						tablero[x1+1][y1+1] = new Casilla();
						tablero[x1][y1] = new Casilla();
						tablero[x2][y2] = cs;
					}
					if(tablero[x1-1][y1+1]->getPieza()->getBando() == false
					        && x2 == x1-2 && y2 == y1+2 &&
					        tablero[x2][y2]->getPieza() == NULL) {
						tablero[x1-1][y1+1] = new Casilla();
						tablero[x1][y1] = new Casilla();
						tablero[x2][y2] = cs;
					}
					if(tablero[x1-1][y1-1]->getPieza()->getBando() == false
					        && x2 == x1-2 && y2 == y1-2 &&
					        tablero[x1-2][y1-2]->getPieza() == NULL) {
						tablero[x1-1][y1-1] = new Casilla();
						tablero[x1][y1] = new Casilla();
						tablero[x2][y2] = cs;
					}
				} else {
					if(tablero[x1+1][y1-1]->getPieza()->getBando() == false
					        && x2 == x1+2 && y2 == y1-2 &&
					        tablero[x2][y2]->getPieza() == NULL) {
						tablero[x1+1][y1-1] = new Casilla();
						tablero[x1][y1] = new Casilla();
						tablero[x2][y2] = cs;
					}
					if(tablero[x1+1][y1+1]->getPieza()->getBando() == false
					        && x2 == x1+2 && y2 == y1+2 &&
					        tablero[x2][y2]->getPieza() == NULL) {
						tablero[x1+1][y1+1] = new Casilla();
						tablero[x1][y1] = new Casilla();
						tablero[x2][y2] = cs;
					}
				}
			} else {
				if(cs->getPieza()->getReina()) {
					if(tablero[x1+1][y1-1]->getPieza()->getBando()
					        && x2 == x1+2 && y2 == y1-2 &&
					        tablero[x2][y2]->getPieza() == NULL) {
						tablero[x1+1][y1-1] = new Casilla();
						tablero[x1][y1] = new Casilla();
						tablero[x2][y2] = cs;
					}
					if(tablero[x1+1][y1+1]->getPieza()->getBando()
					        && x2 == x1+2 && y2 == y1+2 &&
					        tablero[x2][y2]->getPieza() == NULL) {
						tablero[x1+1][y1+1] = new Casilla();
						tablero[x1][y1] = new Casilla();
						tablero[x2][y2] = cs;
					}
					if(tablero[x1-1][y1+1]->getPieza()->getBando()
					        && x2 == x1-2 && y2 == y1+2 &&
					        tablero[x2][y2]->getPieza() == NULL) {
						tablero[x1-1][y1+1] = new Casilla();
						tablero[x1][y1] = new Casilla();
						tablero[x2][y2] = cs;
					}
					if(tablero[x1-1][y1-1]->getPieza()->getBando()
					        && x2 == x1-2 && y2 == y1-2 &&
					        tablero[x2][y2]->getPieza() == NULL) {
						tablero[x1-1][y1-1] = new Casilla();
						tablero[x1][y1] = new Casilla();
						tablero[x2][y2] = cs;
					}
				} else {
					if(tablero[x1-1][y1+1]->getPieza()->getBando()
					        && x2 == x1-2 && y2 == y1+2 &&
					        tablero[x2][y2]->getPieza() == NULL) {
						tablero[x1-1][y1+1] = new Casilla();
						tablero[x1][y1] = new Casilla();
						tablero[x2][y2] = cs;
					}
					if(tablero[x1-1][y1-1]->getPieza()->getBando()
					        && x2 == x1-2 && y2 == y1-2 &&
					        tablero[x2][y2]->getPieza() == NULL) {
						tablero[x1-1][y1-1] = new Casilla();
						tablero[x1][y1] = new Casilla();
						tablero[x2][y2] = cs;
					}
				}
			}
		}
	}
}//fin metodo capturar

bool Damas::ganar() {
	bool gane = false;
	int cBlanco = 0;
	int cNegro = 0;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(tablero[i][j]->getPieza()->getBando()) {
				cBlanco++;
			}
			if(tablero[i][j]->getPieza()->getBando() == false) {
				cNegro++;
			}
		}
	}
	if(cBlanco == 0) {
		gane = true;
		cout << endl;
		cout << "Ha ganado el jugador con fichas negras" << endl;
		cout << endl;
	}
	if(cNegro == 0) {
		gane = true;
		cout << endl;
		cout << "Ha ganado el jugador con fichas blancas" << endl;
		cout << endl;
	}
	return gane;
}

void Damas::becomeQueen(Casilla *&cs, int x, int y) {
	if(cs->getPieza()->getBando() && x == 7) {
		cs->getPieza()->setReina(true);
	}
	if(cs->getPieza()->getBando() == false && x == 0) {
		cs->getPieza()->setReina(true);
	}
}

void Damas::jugar() {
	int x1, y1, x2, y2;
	for(int i = 0; i < 1500; i++) {
		if(i % 2 == 0) {
			cout << "Es turno del jugador con fichas blancas" << endl;
			imprimirTablero();
			cout << endl;
			cout << "Coordenadas del origen de la ficha" << endl;
			cout << "Ingrese la fila[0-7]: ";
			cin >> x1;
			while(x1 < 0 || x1 > 7) {
				cout << endl;
				cout << "Ingrese una posicion valida" << endl;
				cout << "Ingrese la fila[0-7]: ";
				cin >> x1;
				cout << endl;

			}
			cout << "Ingrese la columna[0-7]: ";
			cin >> y1;
			while(y1 < 0 || y1 > 7) {
				cout << endl;
				cout << "Ingrese una posicion valida" << endl;
				cout << "Ingrese la columna[0-7]: ";
				cin >> y1;
				cout << endl;
			}
			cout << endl;
			cout << "Coordenadas del destino de la ficha" << endl;
			cout << "Ingrese la fila[0-7]: ";
			cin >> x2;
			while(x2 < 0 || x2 > 7) {
				cout << endl;
				cout << "Ingrese una posicion valida" << endl;
				cout << "Ingrese la fila[0-7]: ";
				cin >> x2;
				cout << endl;

			}
			cout << "Ingrese la columna[0-7]: ";
			cin >> y2;
			while(y2 < 0 || y2 > 7) {
				cout << endl;
				cout << "Ingrese una posicion valida" << endl;
				cout << "Ingrese la columna[0-7]: ";
				cin >> y2;
				cout << endl;
			}
			while(tablero[x1][y1]->getPieza()->getBando() == false) {
				cout << endl;
				cout << "Las coordenadas de origen NO coinciden con una ficha blanca" << endl;
				cout << "Coordenadas del origen de la ficha" << endl;
				cout << "Ingrese la fila[0-7]: ";
				cin >> x1;
				while(x1 < 0 || x1 > 7) {
					cout << endl;
					cout << "Ingrese una posicion valida" << endl;
					cout << "Ingrese la fila[0-7]: ";
					cin >> x1;
					cout << endl;

				}
				cout << "Ingrese la columna[0-7]: ";
				cin >> y1;
				while(y1 < 0 || y1 > 7) {
					cout << endl;
					cout << "Ingrese una posicion valida" << endl;
					cout << "Ingrese la columna[0-7]: ";
					cin >> y1;
					cout << endl;
				}
				cout << endl;
			}
			while(validarMovimiento(x1, y1, x2, y2, tablero[x1][y1]) == false) {
				cout << endl;
				cout << "Movimiento invalido, intente nuevamente" << endl;
				cout << "Coordenadas del destino de la ficha" << endl;
				cout << "Ingrese la fila[0-7]: ";
				cin >> x2;
				while(x2 < 0 || x2 > 7) {
					cout << endl;
					cout << "Ingrese una posicion valida" << endl;
					cout << "Ingrese la fila[0-7]: ";
					cin >> x2;
					cout << endl;

				}
				cout << "Ingrese la columna[0-7]: ";
				cin >> y2;
				while(y2 < 0 || y2 > 7) {
					cout << endl;
					cout << "Ingrese una posicion valida" << endl;
					cout << "Ingrese la columna[0-7]: ";
					cin >> y2;
					cout << endl;
				}
			}
			capturar(x1,y1,x2,y2,tablero[x1][y1]);
			becomeQueen(tablero[x2][y2], x2, y2);
			imprimirTablero();
		} else {
			cout << "Es turno del jugador con fichas negras" << endl;
			imprimirTablero();
			cout << endl;
			cout << "Coordenadas del origen de la ficha" << endl;
			cout << "Ingrese la fila[0-7]: ";
			cin >> x1;
			while(x1 < 0 || x1 > 7) {
				cout << endl;
				cout << "Ingrese una posicion valida" << endl;
				cout << "Ingrese la fila[0-7]: ";
				cin >> x1;
				cout << endl;

			}
			cout << "Ingrese la columna[0-7]: ";
			cin >> y1;
			while(y1 < 0 || y1 > 7) {
				cout << endl;
				cout << "Ingrese una posicion valida" << endl;
				cout << "Ingrese la columna[0-7]: ";
				cin >> y1;
				cout << endl;
			}
			cout << endl;
			cout << "Coordenadas del destino de la ficha" << endl;
			cout << "Ingrese la fila[0-7]: ";
			cin >> x2;
			while(x2 < 0 || x2 > 7) {
				cout << endl;
				cout << "Ingrese una posicion valida" << endl;
				cout << "Ingrese la fila[0-7]: ";
				cin >> x2;
				cout << endl;

			}
			cout << "Ingrese la columna[0-7]: ";
			cin >> y2;
			while(y2 < 0 || y2 > 7) {
				cout << endl;
				cout << "Ingrese una posicion valida" << endl;
				cout << "Ingrese la columna[0-7]: ";
				cin >> y2;
				cout << endl;
			}
			while(tablero[x1][y1]->getPieza()->getBando() == false) {
				cout << endl;
				cout << "Las coordenadas de origen NO coinciden con una ficha negra" << endl;
				cout << "Coordenadas del origen de la ficha" << endl;
				cout << "Ingrese la fila[0-7]: ";
				cin >> x1;
				while(x1 < 0 || x1 > 7) {
					cout << endl;
					cout << "Ingrese una posicion valida" << endl;
					cout << "Ingrese la fila[0-7]: ";
					cin >> x1;
					cout << endl;

				}
				cout << "Ingrese la columna[0-7]: ";
				cin >> y1;
				while(y1 < 0 || y1 > 7) {
					cout << endl;
					cout << "Ingrese una posicion valida" << endl;
					cout << "Ingrese la columna[0-7]: ";
					cin >> y1;
					cout << endl;
				}
				cout << endl;
			}
			while(validarMovimiento(x1, y1, x2, y2, tablero[x1][y1]) == false) {
				cout << endl;
				cout << "Movimiento invalido, intente nuevamente" << endl;
				cout << "Coordenadas del destino de la ficha" << endl;
				cout << "Ingrese la fila[0-7]: ";
				cin >> x2;
				while(x2 < 0 || x2 > 7) {
					cout << endl;
					cout << "Ingrese una posicion valida" << endl;
					cout << "Ingrese la fila[0-7]: ";
					cin >> x2;
					cout << endl;

				}
				cout << "Ingrese la columna[0-7]: ";
				cin >> y2;
				while(y2 < 0 || y2 > 7) {
					cout << endl;
					cout << "Ingrese una posicion valida" << endl;
					cout << "Ingrese la columna[0-7]: ";
					cin >> y2;
					cout << endl;
				}
			}
			capturar(x1,y1,x2,y2,tablero[x1][y1]);
			becomeQueen(tablero[x2][y2], x2, y2);
			imprimirTablero();
		}
		if(ganar()){
			break;
		}
	}//fin del for
}//fin metodo jugar