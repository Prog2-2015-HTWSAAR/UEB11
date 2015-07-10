/**
 * @file Projektbestandteil.h
 *
 * @date 10.07.2015
 * @author Simon Bastian & Andreas Schreiner
 */

#ifndef PROJEKTBESTANDTEIL_H_
#define PROJEKTBESTANDTEIL_H_
#include <string>
#include <iostream>
using namespace std;
class Projektbestandteil {
public:
	Projektbestandteil(string name, string beschreibung) : name(name),beschreibung(beschreibung){};
	virtual ~Projektbestandteil(){};
	const string& getBeschreibung() const {
		return beschreibung;
	}

	void setBeschreibung(const string& beschreibung) {
		this->beschreibung = beschreibung;
	}

	const string& getName() const {
		return name;
	}

	void setName(const string& name) {
		this->name = name;
	}
	virtual double berechneKosten(double stundenSatz ) = 0;
private:
	string name;
	string beschreibung;
};

#endif /* PROJEKTBESTANDTEIL_H_ */
