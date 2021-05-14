#ifndef PIEZA
#define PIEZA
#include <iostream>
#include <string>
using namespace std;

class Pieza{
	private:
		bool reina;
		bool bando; // true = blanco, false = negro
		
	public:
		Pieza();
		Pieza(bool, bool);
		bool getBando();
		void setBando(bool);
		bool getReina();
		void setReina(bool);
		string toString();
};

#endif