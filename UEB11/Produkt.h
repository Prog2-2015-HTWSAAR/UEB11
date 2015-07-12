/*
 * Produkt.h
 *
 *  Created on: 10.07.2015
 *      Author: sbastian
 */

#ifndef PRODUKT_H_
#define PRODUKT_H_

#include "Projektbestandteil.h"

class Produkt: public Projektbestandteil {
public:
	Produkt(string name, string beschreibung, double produktionskosten);
	virtual ~Produkt();
	virtual double berechneKosten(double stundensatz);
	ostream& ausgeben(ostream& o);
	static const char* meldungName;
	static const char* meldungProduktionskosten;
private:
	double produktionskosten;
};

#endif /* PRODUKT_H_ */
