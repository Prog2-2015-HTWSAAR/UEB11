/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb11 *.o
 * @file ProjektDialog.h
 *
 * @date 13.07.2015
 * @author Simon Bastian & Andreas Schreiner
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
	/**
	* @brief ProjektDialog
	* @details Konstruktor
	*/
	ProjektDialog();
	/**
	* @brief ~ProjektDialog
	* @details dekonstruktor
	*/
	virtual ~ProjektDialog();
	/**
	* @brief createProjekt
	* @details Fkt Zur erstellen eines Projektbestandteils der art eines Projektes
	* @param name
	* @param beschreibung
	* @param stundensatz
	*/
	Projekt* createProjekt(string name, string beschreibung, double stundensatz);
	/**
	* @brief createProdukt
	* @details Fkt Zur erstellen eines Projektbestandteils der art eines Projektes
	* @param name
	* @param beschreibung
	* @param produktionskosten
	*/
	Produkt* createProdukt(string name, string beschreibung, double produktionskosten);
	/**
	* @brief createAufgabe
	* @details Fkt Zur erstellen eines Projektbestandteils der art eines Produktes
	* @param name
	* @param beschreibung
	* @param aufwand
	*/
	Aufgabe* createAufgabe(string name, string beschreibung, double aufwand);
	/**
	* @brief addProjekt
	* @details Fkt Zur hinzufuegen eines Projektbestandteils der art eines Projekt
	* @param projekt
	*/
	void addProjekt(Projekt* projekt);
	/**
	* @brief addProdukt
	* @details Fkt Zur hinzufuegen eines Projektbestandteils der art eines Produkt
	* @param projekt
	*/
	void addProdukt(Projekt* projekt);
	/**
	* @brief addAufgabe
	* @details Fkt Zur hinzufuegen eines Projektbestandteils der art eines Produkt
	* @param projekt
	*/
	void addAufgabe(Projekt* projekt);
	/**
	* @brief createAufgabe
	* @details Fkt Zur entfernen eines Projektbestandteils
	* @param projekt
	*/
	void removePart(Projekt* projekt);
	/**
	* @brief editProjektDialog
	* @details Dia zum aendern eines projektes
	* @param projekt
	*/
	void editProjektDialog(Projekt* projekt);
	/**
	* @brief startTestDialog
	* @details startTestDialog
	*/
	void startTestDialog();
	/**
	* @brief readIntegerInput
	* @details fkt zum lesen eines integers
	*/
	int readIntegerInput();
	/**
	* @brief readDoubleInput
	* @details fkt zum lesen eines double
	*/
	double readDoubleInput();
	/**
	* @brief readStringInput
	* @details fkt zum lesen eines strings
	*/
	string readStringInput();
	/**
	* @brief readStringInput
	* @details fkt zum leeren der eingabe 
	*/
	void clearInput();
};

#endif /* UEB11_PROJEKTDIALOG_H_ */
