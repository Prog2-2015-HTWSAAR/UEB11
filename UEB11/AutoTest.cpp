#include "AutoTest.h"
#include <iostream>
#include <math.h>
#include "Projekt.h"
#include "Aufgabe.h"
#include "Produkt.h" 

const int AutoTest::STD_ANSWER_VALUE = -1;
const int AutoTest::ZERO_VALUE = 0;
const int AutoTest::INPUT_ONE = 1;
const int AutoTest::HIGH_VALUE = 1000;
AutoTest::AutoTest(){}

void AutoTest::automaticTest(){
	Projekt *project = new Projekt("Testprojekt1", 100.0);
	string testwert = "qeqeweqwe";
	string testwertb = "bbbbb";
	string testwertc = "cccccf";

	int tesw = 2;
	const char* ERRORPHRASE = "Fehler: ";
	int testNummer = 0;
	while (testNummer != 100){
		try{
			cout << "Projekt: " << project << endl;
			switch (testNummer) {
			case CREATE_PROJECT:
				createProject(project, testwert, testwert, tesw);
				break;
			case CREATE_FAIL_PROJECT:
				createAufgabe(project, testwertb, testwertb, tesw);

				break;
			case CREATE_AUFGABE:
				createProdukt(project, testwertc, testwertc, tesw);

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
		}
		catch (ProjektException& e){
			cout << ERRORPHRASE << e.what() << endl;
		}
		testNummer++;
	}
}
void AutoTest::createProject(Projekt *project, string &name, string &beschreibung, int &wert){
	Projekt *proj = new Projekt(name, beschreibung, wert);
	project->add(proj);
}
void AutoTest::createProject(Projekt *project, string &name, int &wert){
	Projekt *proj = new Projekt(name, wert);
	project->add(proj);
}
void AutoTest::createAufgabe(Projekt *project, string &name, string &beschreibung, int &wert){
	Aufgabe *auf = new Aufgabe(name, beschreibung, wert);
	project->add(auf);
}
void AutoTest::createProdukt(Projekt *project, string &name, string &beschreibung, int &wert){
	Produkt *prod = new Produkt(name, beschreibung, wert);
	project->add(prod);
}

int AutoTest::readIntegerInput(){
	double number = readDoubleInput();
	if (!(fmod(number, INPUT_ONE) == ZERO_VALUE)){
		number = STD_ANSWER_VALUE;
	}
	return (int)number;
}
double AutoTest::readDoubleInput(){
	double number;
	if (cin >> number){
	}
	else {
		number = STD_ANSWER_VALUE;
	}
	clearInput();
	return number;
}
string AutoTest::readStringInput(){
	string input;
	cin >> input;
	clearInput();
	return input;
}
void AutoTest::clearInput(){
	cin.clear();
	cin.ignore(HIGH_VALUE, '\n');
}


