/*
 * ProjektDialog.h
 *
 *  Created on: 13.07.2015
 *      Author: Simon
 */

#ifndef UEB11_PROJEKTDIALOG_H_
#define UEB11_PROJEKTDIALOG_H_
#include <math.h>

#include "Projekt.h"
#include "Produkt.h"
#include "Aufgabe.h"
enum ProjektOption{ EXIT, ADDPROJEKT, ADDPRODUKT, ADDAUFGABE, REMOVEPPART, CALCCOSTS};
class ProjektDialog {
public:
	static const int STD_ANSWER_VALUE;
	static const int ZERO_VALUE;
	static const int INPUT_ONE;
	static const int HIGH_VALUE;
	ProjektDialog();
	virtual ~ProjektDialog();
	Projekt* createProjekt(string name, string beschreibung, double stundensatz);
	Produkt* createProdukt(string name, string beschreibung, double produktionskosten);
	Aufgabe* createAufgabe(string name, string beschreibung, double aufwand);
	void addProjekt(Projekt* projekt);
	void addProdukt(Projekt* projekt);
	void addAufgabe(Projekt* projekt);
	void removePart(Projekt* projekt);
	void editProjektDialog(Projekt* projekt);
	void startTestDialog();
	int readIntegerInput();
	double readDoubleInput();
	string readStringInput();
	void clearInput();
};

#endif /* UEB11_PROJEKTDIALOG_H_ */
