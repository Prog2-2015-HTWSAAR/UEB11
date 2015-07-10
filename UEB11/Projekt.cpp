/*
 * Projekt.cpp
 *
 *  Created on: 10.07.2015
 *      Author: sbastian
 */

#include "Projekt.h"

Projekt::Projekt(string name, string beschreibung, double stundenSatz) : Projektbestandteil(name, beschreibung), stundenSatz(stundenSatz){
	teilTab = new Projektbestandteil*[maxParts];
	teile = 0;
}

Projekt::~Projekt() {
	// TODO Auto-generated destructor stub
}

double Projekt::berechneKosten(double stundenSatz) {
	int kosten = 0;
	for (int i = 0; i < teile; ++i) {
		kosten += teilTab[i]->berechneKosten(stundenSatz);
	}
	return kosten;
}
