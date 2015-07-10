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

ostream& operator<<(ostream& o, Aufgabe* ap){
	o << ap->getName() << endl;
	o << ap->getBeschreibung() << endl;
	return o;
}
