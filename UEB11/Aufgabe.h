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
	/**
	* @brief Aufgabe
	* @details Konstruktor
	* @param name
	* @param beschreibung
	* @param aufwand
	*/
	Aufgabe(string name, string beschreibung, int aufwand);
	/**
	* @brief ~Aufgabe
	* @details Dekonstruktor
	*/
	virtual ~Aufgabe();
	/**
	* @brief berechneKosten
	* @details Fkt Zur berechnung der Kosten
	* @param stundensatz
	*/
	virtual double berechneKosten(double stundensatz);
	/**
	* @brief ausgeben
	* @details Ausgabe fkt
	* @param o
	*/
	virtual ostream& ausgeben(ostream& o);
	static const char* meldungName;
	static const char* meldungAufwand;
private:
	int aufwand;
};

#endif /* AUFGABE_H_ */
