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
const int AutoTest::TEST_VALUE_ONE = 100;
const int AutoTest::TEST_VALUE_TWO = 200;
const int AutoTest::TEST_VALUE_ZERO = 0;
const int AutoTest::TEST_VALUE_NEGATIVE = -1;
const string AutoTest::TEST_NAME_NOT_USED = "TEST_NAME_NOT_USED";
const string AutoTest::TEST_NAME_ONE = "TEST_NAME_1";
const string AutoTest::TEST_NAME_TWO = "TEST_NAME_2";
const string AutoTest::TEST_NAME_THREE = "TEST_NAME_3";
const string AutoTest::TEST_NAME_FOUR = "TEST_NAME_4";
const string AutoTest::TEST_NAME_EMPTY = "";
const string AutoTest::TEST_DISCRIPTION_ONE = "TEST_DISCRIPTION_1";
const string AutoTest::TEST_DISCRIPTION_TWO = "TEST_DISCRIPTION_2";
const string AutoTest::TEST_DISCRIPTION_THREE = "TEST_DISCRIPTION_3";
const string AutoTest::TEST_DISCRIPTION_FOUR = "TEST_DISCRIPTION_4";
const string AutoTest::TEST_DISCRIPTION_EMPTY = "";
const char* AutoTest::ERRORPHRASE = "Fehler: ";

AutoTest::AutoTest(){}

void AutoTest::automaticTest(){
	Projekt *project = new Projekt(TEST_NAME_ONE, TEST_DISCRIPTION_ONE, TEST_VALUE_ONE);
	int testNummer = 0;
	while (testNummer != 14){
		try{
			cout << "Projekt: " << project << endl;
			cout << "Projektkosten:" << project->berechneKosten() << endl;
			switch (testNummer) {

			case CREATE_PRODUCT:
				createProdukt(project, TEST_NAME_TWO, TEST_DISCRIPTION_TWO, TEST_VALUE_ONE);
				break;
			case CREATE_PRODUCT_EMPTY_NAME: 
				createProdukt(project, TEST_NAME_EMPTY, TEST_DISCRIPTION_TWO, TEST_VALUE_ONE);
				break;
			case CREATE_PRODUCT_NEGATIVE_VALUE:
				createProdukt(project, TEST_NAME_TWO, TEST_DISCRIPTION_TWO, TEST_VALUE_NEGATIVE);
				break;
			case CREATE_AUFGABE: 
				createAufgabe(project, TEST_NAME_THREE, TEST_DISCRIPTION_THREE, TEST_VALUE_TWO);
				break;
			case CREATE_AUFGABE_EMPTY_NAME:
				createAufgabe(project, TEST_NAME_EMPTY, TEST_DISCRIPTION_THREE, TEST_VALUE_TWO);
				break;
			case CREATE_AUFGABE_NEGATIVE_VALUE:
				createAufgabe(project, TEST_NAME_THREE, TEST_DISCRIPTION_THREE, TEST_VALUE_NEGATIVE);
				break;
			case CREATE_SUB_PROJECT: 
				createProject(project, TEST_NAME_FOUR, TEST_DISCRIPTION_FOUR, TEST_VALUE_TWO);
				break;
			case CREATE_SUB_PROJECT_EMPTY_NAME:
				createProject(project, TEST_NAME_EMPTY, TEST_DISCRIPTION_FOUR, TEST_VALUE_TWO);
				break;
			case CREATE_SUB_PROJECT_ZERO_VALUE:
				createProject(project, TEST_NAME_FOUR, TEST_DISCRIPTION_FOUR, TEST_VALUE_ZERO);
				break;
			case REMOVE_NOT_EXIST:
				project->remove(TEST_NAME_NOT_USED);
				break;
			case REMOVE_SUBPROJECT:
				project->remove(TEST_NAME_FOUR);
				break;
			case REMOVE_AUFGABE:
				project->remove(TEST_NAME_THREE);
				break;
			case REMOVE_PRODUCT:
				project->remove(TEST_NAME_TWO);
				break;
			case REMOVE_PROJECT:
				project->remove(TEST_NAME_ONE);
				break;
			}
		}
		catch (ProjektException& e){
			cout << ERRORPHRASE << e.what() << endl;
		}
		testNummer++;
	}
}
void AutoTest::createProject(Projekt *project, const string &name, const string &beschreibung, const int &wert){
	Projekt *proj = new Projekt(name, beschreibung, wert);
	project->add(proj);
}
void AutoTest::createProject(Projekt *project, const string &name, const int &wert){
	Projekt *proj = new Projekt(name, wert);
	project->add(proj);
}
void AutoTest::createAufgabe(Projekt *project, const string &name, const string &beschreibung, const int &wert){
	Aufgabe *auf = new Aufgabe(name, beschreibung, wert);
	project->add(auf);
}
void AutoTest::createProdukt(Projekt *project, const string &name, const string &beschreibung, const int &wert){
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


