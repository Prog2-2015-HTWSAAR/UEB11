/*
 * Aufgabe.cpp
 *
 *  Created on: 10.07.2015
 *      Author: sbastian
 */

#include "Aufgabe.h"

Aufgabe::Aufgabe(string name, string beschreibung, int aufwand) : Projektbestandteil(name, beschreibung) , aufwand(aufwand) {
	// TODO Exception
}

Aufgabe::~Aufgabe() {
}

double Aufgabe::berechneKosten(double stundenSatz){
	return stundenSatz * aufwand;
}

ostream& Aufgabe::ausgeben(ostream& o){
	o << getName() << endl;
	o << getBeschreibung() << endl;
	return o;
}
