#include <iostream>
#include "Damas.h"
using namespace std;


int main() {
	Damas* d = new Damas();
	d->imprimirTablero();
	d->~Damas();
	delete d;
	return 0;
}
