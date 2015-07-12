/*
 * Projekt.cpp
 *
 *  Created on: 10.07.2015
 *      Author: sbastian
 */

#include "Projekt.h"

const char* Projekt::meldungName = "Der Name des Projekts darf nicht leer sein!";
const char* Projekt::meldungStundensatz = "Der Stundensatz muss positiv sein!";

Projekt::Projekt(string name, string beschreibung, double stundensatz) : Projektbestandteil(name, beschreibung), stundenSatz(stundenSatz){
	if(name.empty()){
		throw ProjektException(meldungName);
	}
	if(stundensatz <= 0){
		throw ProjektException(meldungStundensatz);
	}
	teilTab = new Projektbestandteil*[maxParts];
	teile = 0;
}

Projekt::Projekt(string name, double stundenSatz) : Projektbestandteil(name, "keine Beschreibung"), stundenSatz(stundenSatz){
	teilTab = new Projektbestandteil*[maxParts];
	teile = 0;
}

Projekt::~Projekt() {
	// TODO Auto-generated destructor stub
}

void Projekt::add(Projektbestandteil* pbp){
	teilTab[teile++] = pbp;
}

void Projekt::remove(string name){
	int pos = findProjectPart(name);
	if(pos >= 0){
		delete teilTab[pos];
		teilTab[pos] = teilTab[teile];
		teile--;
	}

}

int Projekt::findProjectPart(string name){
	Projektbestandteil* teil = NULL;
	for (int i = 0; i < teile; ++i) {
		teil = teilTab[i];
		if(name.compare(teil->getName()) == 0){
			return i;
		}
	}
	return -1;
}
double Projekt::berechneKosten() {
	int kosten = 0;
	for (int i = 0; i < teile; ++i) {
		kosten += teilTab[i]->berechneKosten(stundenSatz);
	}
	return kosten;
}

double Projekt::berechneKosten(double stundenSatz){
	return berechneKosten();
}
 ostream& Projekt::ausgeben(ostream& o){
	o << getName() << endl;
	o << getBeschreibung() << endl;
	for (int i = 0; i < teile; ++i) {
		teilTab[i]->ausgeben(o);
	}
	return o;
}
ostream& operator<<(ostream& o, Projekt* pp){
	o << pp->getName() << endl;
	o << pp->getBeschreibung() << endl;
	for (int i = 0; i < pp->teile; ++i) {
		pp->teilTab[i]->ausgeben(o);
	}
	return o;
}
