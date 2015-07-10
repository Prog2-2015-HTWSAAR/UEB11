/*
 * Projekt.h
 *
 *  Created on: 10.07.2015
 *      Author: sbastian
 */

#ifndef PROJEKT_H_
#define PROJEKT_H_

#include "Projektbestandteil.h"
class Projekt: public Projektbestandteil {
public:
	Projekt(string name, string Beschreibung, double stundenSatz );
	virtual ~Projekt();
	void add(Projektbestandteil* projekbestandteil);
	void remove(string name);
	static const int maxParts = 20;
	virtual double berechneKosten(double stundenSatz);
private:
	Projektbestandteil* findProjectPart(string name);
	void deleteAllParts();
	Projektbestandteil** teilTab;
	double stundenSatz;
	int teile;
};

#endif /* PROJEKT_H_ */
