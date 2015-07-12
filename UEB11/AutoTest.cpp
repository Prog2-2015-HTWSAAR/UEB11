#include "AutoTest.h"
#include <iostream>

#include "Projekt.h"
#include "Aufgabe.h"
#include "Produkt.h"

AutoTest::AutoTest(){}
void AutoTest::automaticTest(){
	int testNummer = 0;
	while (testNummer == 100){
		switch (testNummer) {
		case CREATE_PROJECT:

			break;
		case CREATE_FAIL_PROJECT:
			break;

		case CREATE_AUFGABE:

			break;
		case CREATE_FAIL_AUFGABE:

			break;
		case CREATE_PRODUCT:

			break;
		case CREATE_FAIL_PRODUCT:

			break;
		case CREATE_SUB_PROJECT:

			break;
		case CREATE_SUB_FAIL_PROJECT:
			
			break;
		}
		testNummer++;
	}
}
void AutoTest::createProject(string &name, string &beschreibung, int &wert){
	Projekt *proj = new Projekt(name, beschreibung, wert);
	project->add(proj);
}
void AutoTest::createProject(string &name, int &wert){
	Projekt *proj = new Projekt(name, wert);
	project->add(proj);
}
void AutoTest::createAufgabe(string &name, string &beschreibung, int &wert){
	Aufgabe *auf = new Aufgabe(name, beschreibung, wert);
	project->add(auf);
}
void AutoTest::createProdukt(string &name, string &beschreibung, int &wert){
	Produkt *prod = new Produkt(name, beschreibung, wert);
	project->add(prod);
}




