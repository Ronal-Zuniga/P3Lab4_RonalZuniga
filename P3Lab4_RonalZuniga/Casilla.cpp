#include "Casilla.h"
#include <iostream>
#include <string>
using namespace std;

Casilla::Casilla(){
	this->pieza = NULL;
}

Casilla::Casilla(Pieza* p){
	this->pieza = p;
}

Pieza* Casilla::getPieza(){
	return this->pieza;
}

void Casilla::setPieza(Pieza* p){
	this->pieza = p;
}

string Casilla::toString(){
	if(pieza != NULL){
		return pieza->toString();
	} else{
		return " ";
	}
}