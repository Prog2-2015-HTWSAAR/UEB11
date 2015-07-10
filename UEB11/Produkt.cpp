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

