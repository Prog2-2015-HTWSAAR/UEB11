/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb06 *.o
* @file ueb11.cpp
* @author Andreas Schreiner & Simon Bastian
*
* @date 10.07.2015
*
* Main Funktion
*

*/
#include <iostream>
#include "AutoTest.h"
#include "Projekt.h"
#include "Aufgabe.h"
#include "Produkt.h"
/**
* @brief Main Function
*/
int main(){
	AutoTest autoT;
	autoT.automaticTest();
	//// Projektobjekt konstruieren mit Name und weiteren Paremetern
	//Projekt *p = new Projekt("Testprojekt1", 100.0);
	//// Aufgaben konstruieren mit Name, Beschreibung und Aufwand
	//Aufgabe *entwurf = new Aufgabe("Entwurf", "Entwerfen des Produktes", 200);
	//Aufgabe *produktion = new Aufgabe("Produktion", "Eigentliches Produzieren", 100);
	//// Produkte konstruieren mit Name, Beschreibung, Produktionskosten
	//Produkt *prototyp = new Produkt("Prototyp", "...", 1000.0);
	//// Teilprojekt anlegen
	//Projekt *teilprojekt = new Projekt("Baugruppe");
	//// hier irgendwelche Aufgaben und Produkte zuordnen
	//// Projekt zusammenbauen
	//p->add(entwurf); // das übergebene Objekt muss nicht kopiert werden
	//p->add(produktion);
	//p->add(prototyp);
	//p->add(teilprojekt);
	//// Projekt mit allen Bestandteilen ausgeben und Kosten kalkulieren
	//cout << "Projekt: " << p << endl;
	//cout << "Projektkosten:" << p->berechneKosten() << endl;
	//p->remove("Baugruppe"); // Projektbestandteil mit bestimmtem Namen löschen
	return 0;
}
