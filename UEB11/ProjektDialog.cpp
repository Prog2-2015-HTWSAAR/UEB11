/*
 * ProjektDialog.cpp
 *
 *  Created on: 13.07.2015
 *      Author: Simon
 */

#include "ProjektDialog.h"

ProjektDialog::ProjektDialog() {
	// Nothing to do here

}

ProjektDialog::~ProjektDialog() {
	// Nothing to do here
}


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
	Projekt* projekt = createProjekt("TestProjekt", "Tolle Beschreibung", 10);
	editProjektDialog(projekt);
}
void ProjektDialog::editProjektDialog(Projekt* projekt){
	int answer = -1;
	do {
		cout << endl << "------------------------------" << endl
			<< projekt << "------------------------------" << endl;
		cout << "(1) TeilProjekt erstellen" << endl << "(2) Produkt erstellen" << endl
			<< "(3) Aufgabe erstellen" << endl <<"(4) Projektbestanteil entfernen" << endl
			<< "(5) Projektkosten berechnen" << endl << "(0) Ende" << endl;
		cin >> answer;
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
				cout << "Projektkosten: " << projekt->berechneKosten() << endl;
				break;
			case EXIT:
				break;
			default:
				cout << "Fehlerhafte Eingabe!" << endl;
				answer = -1;
				break;
		}
	} while (answer != EXIT);
}

void ProjektDialog::addProjekt(Projekt* projekt){
	string name = "";
	string beschreibung = "";
	Projekt* neuProjekt = NULL;
	double stundensatz = 0.0;
	cout << "Name: ";
	cin >> name;
	cout << "Beschreibung:" << endl;
	cin >> beschreibung;
	cout << "Stundensatz: ";
	cin >> stundensatz;
	neuProjekt = createProjekt(name,beschreibung,stundensatz);
	projekt->add(neuProjekt);
	editProjektDialog(neuProjekt);
}

void ProjektDialog::addProdukt(Projekt* projekt){
	string name = "";
	string beschreibung = "";
	double produktionskosten = 0.0;
	Produkt* produkt = NULL;
	cout << "Name: ";
	cin >> name;
	cout << "Beschreibung:" << endl;
	cin >> beschreibung;
	cout << "Produktionskosten: ";
	cin >> produktionskosten;
	produkt = createProdukt(name, beschreibung, produktionskosten);
	projekt->add(produkt);
}

void ProjektDialog::addAufgabe(Projekt* projekt){
	string name = "";
	string beschreibung = "";
	double aufwand = 0.0;
	Aufgabe* aufgabe = NULL;
	cout << "Name: ";
	cin >> name;
	cout << "Beschreibung:" << endl;
	cin >> beschreibung;
	cout << "Aufwand: ";
	cin >> aufwand;
	aufgabe = createAufgabe(name, beschreibung, aufwand);
	projekt->add(aufgabe);
}
void ProjektDialog::removePart(Projekt* projekt){
	string name = "";
	cout << "Name: ";
	cin >> name;
	projekt->remove(name);
}
