/*
 * Aufgabe.cpp
 *
 *  Created on: 10.07.2015
 *      Author: sbastian
 */

#include "Aufgabe.h"
const char* Aufgabe::meldungName = "Der Name der Aufgabe darf nicht leer sein!";
const char* Aufgabe::meldungAufwand = " Der Aufwand darf nicht negativ sein!";
Aufgabe::Aufgabe(string name, string beschreibung, int aufwand) : Projektbestandteil(name, beschreibung) , aufwand(aufwand) {
	if(name.empty()){
		throw ProjektException(meldungName);
	}
	if(aufwand < 0){
		throw ProjektException(meldungAufwand);
	}
}

Aufgabe::~Aufgabe() {
}

double Aufgabe::berechneKosten(double stundensatz){
	return stundensatz * aufwand;
}

ostream& Aufgabe::ausgeben(ostream& o){
	o << "Aufgabe: "<< getName() << endl;
	o << getBeschreibung() << endl;
	o << "Aufwand: " << aufwand << " Stunden" << endl;
	return o;
}
