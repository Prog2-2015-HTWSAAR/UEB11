/*
 * ProjektDialog.h
 *
 *  Created on: 13.07.2015
 *      Author: Simon
 */

#ifndef UEB11_PROJEKTDIALOG_H_
#define UEB11_PROJEKTDIALOG_H_
#include "Projekt.h"
#include "Produkt.h"
#include "Aufgabe.h"
enum ProjektOption{ EXIT, ADDPROJEKT, ADDPRODUKT, ADDAUFGABE, REMOVEPPART, CALCCOSTS};
class ProjektDialog {
public:
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

};

#endif /* UEB11_PROJEKTDIALOG_H_ */
