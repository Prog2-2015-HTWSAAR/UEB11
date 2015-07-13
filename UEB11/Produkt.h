/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb11 *.o
 * @file Produkt.h
 *
 * @date 10.07.2015
 * @author Simon Bastian & Andreas Schreiner
 */

#ifndef PRODUKT_H_
#define PRODUKT_H_

#include "Projektbestandteil.h"

class Produkt: public Projektbestandteil {
public:
	/**
	* @brief Produkt
	* @details Konstruktor
	* @param name
	* @param beschreibung
	* @param produktionskosten
	*/
	Produkt(string name, string beschreibung, double produktionskosten);
	/**
	* @brief ~Produkt
	* @details Dekonstruktor

	*/
	virtual ~Produkt();
	/**
	* @brief berechneKosten
	* @details fkt zur berechnung des Stundensatz
	* @param stundensatz
	*/
	virtual double berechneKosten(double stundensatz);
	/**
	* @brief ausgeben
	* @details Ausgabe Fkt
	* @param o
	*/
	ostream& ausgeben(ostream& o);
	static const char* meldungName;
	static const char* meldungProduktionskosten;
private:
	double produktionskosten;
};

#endif /* PRODUKT_H_ */
