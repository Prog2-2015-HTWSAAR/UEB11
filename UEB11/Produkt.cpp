/*
 * Produkt.cpp
 *
 *  Created on: 10.07.2015
 *      Author: sbastian
 */

#include "Produkt.h"

Produkt::Produkt(string name, string beschreibung, double produktionskosten) :
	Projektbestandteil(name, beschreibung), produktionskosten(produktionskosten) {
	// TODO Exception
}

Produkt::~Produkt() {
}

double Produkt::berechneKosten(double stundenSatz){
	return produktionskosten;
}

ostream& operator<<(ostream& o, Produkt* pp){
	o << pp->getName() << endl;
	o << pp->getBeschreibung() << endl;
	return o;
}
