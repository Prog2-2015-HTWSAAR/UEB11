/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb11 *.o
 * @file Projektbestandteil.h
 *
 * @date 10.07.2015
 * @author Simon Bastian & Andreas Schreiner
 */

#ifndef PROJEKTBESTANDTEIL_H_
#define PROJEKTBESTANDTEIL_H_
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;
	class ProjektException : public std::logic_error {
	public:
		ProjektException(const std::string& msg = "") : logic_error(msg) {}
	};
class Projektbestandteil {
public:
	Projektbestandteil(string name, string beschreibung) : name(name),beschreibung(beschreibung){

	};
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
	virtual double berechneKosten(double stundensatz ) = 0;
	virtual ostream& ausgeben(ostream& o) = 0;
private:
	string name;
	string beschreibung;
};

#endif /* PROJEKTBESTANDTEIL_H_ */
