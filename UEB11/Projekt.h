/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb11 *.o
 * @file Projekt.h
 *
 * @date 10.07.2015
 * @author Simon Bastian & Andreas Schreiner
 */

#ifndef PROJEKT_H_
#define PROJEKT_H_

#include "Projektbestandteil.h"
class Projekt: public Projektbestandteil {
public:
	Projekt(string name, string Beschreibung, double stundensatz );
	Projekt(string name, double stundensatz = 0);
	virtual ~Projekt();
	void add(Projektbestandteil* projekbestandteil);
	void remove(string name);
	static const int maxParts = 20;
	virtual double berechneKosten();
	virtual double berechneKosten(double stundensatz);
	ostream& ausgeben(ostream& o);
	friend ostream& operator<<(ostream& o, Projekt* pp);
	static const char* meldungName;
	static const char* meldungStundensatz;
	static const char* meldungProjektVoll;
	static const char* meldungNameVorhanden;
private:
	int findProjectPart(string name);
	void deleteAllParts();
	Projektbestandteil** teilTab;
	double stundensatz;
	int teile;
};

#endif /* PROJEKT_H_ */
