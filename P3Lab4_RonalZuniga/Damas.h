#ifndef DAMAS
#define DAMAS
#include "Casilla.h"

class Damas{
	private:
		Casilla*** tablero = NULL;
		
	public:
		Damas();
		~Damas();
		void prepararTablero();
		void imprimirTablero();
		bool ganar();
		bool validarMovimiento(int, int, int, int, Casilla*&);
		void capturar(int, int, int, int, Casilla*&);
		void jugar();
		void freeTablero();
		void becomeQueen(Casilla*&, int, int);
};

#endif