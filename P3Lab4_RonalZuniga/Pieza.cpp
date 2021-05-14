#include "Pieza.h"
#include <iostream>
#include <string>
using namespace std;

Pieza::Pieza() {

}

Pieza::Pieza(bool _reina, bool _bando) {
	this->reina = _reina;
	this->bando = _bando;
}

bool Pieza::getReina() {
	return this->reina;
}

void Pieza::setReina(bool _reina) {
	this->reina = _reina;
}

bool Pieza::getBando() {
	return this->bando;
}

void Pieza::setBando(bool _bando) {
	this->bando = _bando;
}

string Pieza::toString() {
	if(this->bando) {
		if(this->reina) {
			return "RO";
		} else {
			return "O";
		}
	} else {
		if(this->reina) {
			return "RX";
		} else {
			return "X";
		}
	}
}