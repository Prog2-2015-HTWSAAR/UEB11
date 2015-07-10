/*
 * Aufgabe.h
 *
 *  Created on: 10.07.2015
 *      Author: sbastian
 */

#ifndef AUFGABE_H_
#define AUFGABE_H_

#include "Projektbestandteil.h"

class Aufgabe: public Projektbestandteil {
public:
	Aufgabe(string name, string beschreibung, int aufwand);
	virtual ~Aufgabe();
	virtual double berechneKosten(double stundensatz);
private:
	int aufwand;
};

#endif /* AUFGABE_H_ */
