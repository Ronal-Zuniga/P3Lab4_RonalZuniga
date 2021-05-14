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
		bool validarMovimiento(int, int, int, int);
		void capturar();
		void jugar();
		void freeTablero();
};

#endif