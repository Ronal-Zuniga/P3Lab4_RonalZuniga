#ifndef CASILLA
#define CASILLA
#include "Pieza.h"
#include <string>
#include <iostream>
using namespace std;

class Casilla{
	private:
		Pieza* pieza;
	
	public:
		Casilla();
		Casilla(Pieza*);
		Pieza* getPieza();
		void setPieza(Pieza*);
		string toString();
};

#endif