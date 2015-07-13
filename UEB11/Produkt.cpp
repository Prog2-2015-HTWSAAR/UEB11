/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb11 *.o
 * @file Produkt.cpp
 *
 * @date 10.07.2015
 * @author Simon Bastian & Andreas Schreiner
 */

#include "Produkt.h"
const char* Produkt::meldungName = "Der Name des Produkts darf nicht leer sein!";
const char* Produkt::meldungProduktionskosten = "Die Produktionskosten duefen nicht negativ sein!";
Produkt::Produkt(string name, string beschreibung, double produktionskosten) :
	Projektbestandteil(name, beschreibung), produktionskosten(produktionskosten) {
	if(name.empty()){
		throw ProjektException(meldungName);
	}
	if(produktionskosten < 0){
		throw ProjektException(meldungProduktionskosten);
	}
}

Produkt::~Produkt() {
}

double Produkt::berechneKosten(double stundenSatz){
	return produktionskosten;
}

ostream& Produkt::ausgeben(ostream& o){
	o << "Produkt: " << getName() << endl;
	o << getBeschreibung() << endl;
	o << "Kosten: " << produktionskosten << " Euro" << endl;
	return o;
}
