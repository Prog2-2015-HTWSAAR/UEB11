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
	static const string SEPERATOR;
	static const string OPTION_TEILPROJEKT;
	static const string OPTION_PRODUKT_ERSTELLEN;
	static const string OPTION_AUFGABE_ERSTELLEN;
	static const string OPTION_PROJEKTBESTANTEIL_ENTFERNEN;
	static const string PROJEKTKOSTEN_BERECHNEN;
	static const string OPTION_BACK_TO_BASE_MENUE;
	static const string STANDARD_CHOICE_PHRASE;
	static const string PHRASE_NAME;
	static const string PHRASE_BESCHREIBUNG;
	static const string PHRASE_PROJEKTKOSTEN;
	static const string PHRASE_STUNDENSATZ;
	static const string PHRASE_PRODUKTIONSKOSTEN;
	static const string PHRASE_AUFWAND;
	static const char* ERRORPHRASE;
	static const char* INPUTERRORPHRASE;

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
