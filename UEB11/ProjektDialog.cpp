/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb11 *.o
 * ProjektDialog.cpp
 *
 *  @date 13.07.2015
 *  @author Simon Bastian & Andreas Schreiner
 */

#include "ProjektDialog.h"
const int ProjektDialog::STD_ANSWER_VALUE = -1;
const int ProjektDialog::ZERO_VALUE = 0;
const int ProjektDialog::INPUT_ONE = 1;
const int ProjektDialog::HIGH_VALUE = 1000;
const string ProjektDialog::SEPERATOR = "-------------------------------";
const string ProjektDialog::OPTION_TEILPROJEKT = "(1) TeilProjekt erstellen";
const string ProjektDialog::OPTION_PRODUKT_ERSTELLEN = "(2) Produkt erstellen";
const string ProjektDialog::OPTION_AUFGABE_ERSTELLEN = "(3) Aufgabe erstellen";
const string ProjektDialog::OPTION_PROJEKTBESTANTEIL_ENTFERNEN = "(4) Projektbestanteil entfernen";
const string ProjektDialog::PROJEKTKOSTEN_BERECHNEN = "(5) Projektkosten berechnen";
const string ProjektDialog::OPTION_BACK_TO_BASE_MENUE = "(0) Zurueck zur Auswahl";
const string ProjektDialog::STANDARD_CHOICE_PHRASE = "Waehlen sie eine Option : ";
const string ProjektDialog::PHRASE_NAME = "Name: ";
const string ProjektDialog::PHRASE_BESCHREIBUNG = "Beschreibung: ";
const string ProjektDialog::PHRASE_STUNDENSATZ = "Stundensatz: ";
const string ProjektDialog::PHRASE_PROJEKTKOSTEN = "Projektkosten: ";
const string ProjektDialog::PHRASE_PRODUKTIONSKOSTEN = "Produktionskosten: ";
const string ProjektDialog::PHRASE_AUFWAND = "Aufwand: ";

const char* ProjektDialog::ERRORPHRASE = "Fehler: ";
const char* ProjektDialog::INPUTERRORPHRASE = "-> FEHLERHAFTE EINGABE <-";

ProjektDialog::ProjektDialog() {}
ProjektDialog::~ProjektDialog() {}


Projekt* ProjektDialog::createProjekt(string name, string beschreibung, double stundensatz){
	return new Projekt(name, beschreibung, stundensatz);
}
Produkt* ProjektDialog::createProdukt(string name, string beschreibung, double produktionskosten){
	return new Produkt(name, beschreibung, produktionskosten);
}
Aufgabe* ProjektDialog::createAufgabe(string name, string beschreibung, double aufwand){
	return new Aufgabe(name, beschreibung, aufwand);
}

void ProjektDialog::startTestDialog(){
	string name, discription;
	int satz;
	cout << SEPERATOR << endl << PHRASE_NAME;
	name = readStringInput();
	cout << PHRASE_BESCHREIBUNG;
	discription = readStringInput();
	cout << PHRASE_STUNDENSATZ;
	satz = readIntegerInput();
	try{
		Projekt* projekt = createProjekt(name, discription, satz);
		editProjektDialog(projekt);
	}
	catch (ProjektException& e){
		cout << ERRORPHRASE << e.what() << endl;
	}
}
void ProjektDialog::editProjektDialog(Projekt* projekt){
	int answer = -1;
	do {
		try {
			cout << endl << SEPERATOR << endl
				<< projekt << SEPERATOR << endl;
			cout << OPTION_TEILPROJEKT << endl << OPTION_PRODUKT_ERSTELLEN << endl
				<< OPTION_AUFGABE_ERSTELLEN << endl << OPTION_PROJEKTBESTANTEIL_ENTFERNEN << endl
				<< PROJEKTKOSTEN_BERECHNEN << endl << OPTION_BACK_TO_BASE_MENUE << endl << STANDARD_CHOICE_PHRASE;
			answer = readIntegerInput();
			switch (answer) {
			case ADDPROJEKT:
				addProjekt(projekt);
				break;
			case ADDPRODUKT:
				addProdukt(projekt);
				break;
			case ADDAUFGABE:
				addAufgabe(projekt);
				break;
			case REMOVEPPART:
				removePart(projekt);
				break;
			case CALCCOSTS:
				cout << PHRASE_PROJEKTKOSTEN << projekt->berechneKosten() << endl;
				break;
			case EXIT:
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
				answer = -1;
				break;
			}
		}
		catch (ProjektException& e){
			cout << ERRORPHRASE << e.what() << endl;
		}
	} while (answer != EXIT);
}

void ProjektDialog::addProjekt(Projekt* projekt){
	string name, beschreibung;
	Projekt* neuProjekt = NULL;
	double stundensatz;
	cout << PHRASE_NAME;
	name = readStringInput();
	cout << PHRASE_BESCHREIBUNG;
	beschreibung = readStringInput();
	cout << PHRASE_STUNDENSATZ;
	stundensatz = readDoubleInput();
	neuProjekt = createProjekt(name,beschreibung,stundensatz);
	projekt->add(neuProjekt);
	editProjektDialog(neuProjekt);
}

void ProjektDialog::addProdukt(Projekt* projekt){
	string name, beschreibung;
	double produktionskosten;
	Produkt* produkt = NULL;
	cout << PHRASE_NAME;
	name = readStringInput();
	cout << PHRASE_BESCHREIBUNG;
	beschreibung = readStringInput();
	cout << PHRASE_PRODUKTIONSKOSTEN;
	produktionskosten = readDoubleInput();
	produkt = createProdukt(name, beschreibung, produktionskosten);
	projekt->add(produkt);
}

void ProjektDialog::addAufgabe(Projekt* projekt){
	string name, beschreibung;
	double aufwand;
	Aufgabe* aufgabe = NULL;
	cout << PHRASE_NAME;
	name = readStringInput();
	cout << PHRASE_BESCHREIBUNG;
	beschreibung = readStringInput();
	cout << PHRASE_AUFWAND;
	aufwand = readDoubleInput();
	aufgabe = createAufgabe(name, beschreibung, aufwand);
	projekt->add(aufgabe);
}
void ProjektDialog::removePart(Projekt* projekt){
	string name;
	cout << PHRASE_NAME;
	name = readStringInput();
	projekt->remove(name);
}

int ProjektDialog::readIntegerInput(){
	double number = readDoubleInput();
	if (!(fmod(number, INPUT_ONE) == ZERO_VALUE)){
		number = STD_ANSWER_VALUE;
	}
	return (int)number;
}
double ProjektDialog::readDoubleInput(){
	double number;
	if (cin >> number){
	}
	else {
		number = STD_ANSWER_VALUE;
	}
	clearInput();
	return number;
}
string ProjektDialog::readStringInput(){
	string input;
	cin >> input;
	clearInput();
	return input;
}
void ProjektDialog::clearInput(){
	cin.clear();
	cin.ignore(HIGH_VALUE, '\n');
}
