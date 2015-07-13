#ifndef AUTOTEST_H_
#define AUTOTEST_H_
#include <iostream>
#include <string>
#include <cstring>
#include "Projekt.h"

using namespace std;

class AutoTest
{
public:
	enum AutomTest{
		CREATE_PRODUCT, CREATE_PRODUCT_EMPTY_NAME, CREATE_PRODUCT_NEGATIVE_VALUE, CREATE_AUFGABE, CREATE_AUFGABE_EMPTY_NAME,
		CREATE_AUFGABE_NEGATIVE_VALUE, CREATE_SUB_PROJECT, CREATE_SUB_PROJECT_EMPTY_NAME, CREATE_SUB_PROJECT_ZERO_VALUE, REMOVE_NOT_EXIST, 
		REMOVE_SUBPROJECT, REMOVE_AUFGABE, REMOVE_PRODUCT ,REMOVE_PROJECT
	};


	static const int TEST_VALUE_ONE;
	static const int TEST_VALUE_TWO;
	static const int TEST_VALUE_ZERO;
	static const int TEST_VALUE_NEGATIVE;
	static const string TEST_NAME_NOT_USED;
	static const string TEST_NAME_ONE;
	static const string TEST_NAME_TWO;
	static const string TEST_NAME_THREE;
	static const string TEST_NAME_FOUR;
	static const string TEST_NAME_EMPTY;
	static const string TEST_DISCRIPTION_ONE;
	static const string TEST_DISCRIPTION_TWO;
	static const string TEST_DISCRIPTION_THREE;
	static const string TEST_DISCRIPTION_FOUR;
	static const string TEST_DISCRIPTION_EMPTY;
	static const char* ERRORPHRASE;
	void automaticTest();
	void createProject(Projekt *project, const string& name, const string &beschreibung, const int &wert);
	void createProject(Projekt *project, const string& name, const int &wert);
	void createAufgabe(Projekt *project, const string& name, const string &beschreibung, const int &wert);
	void createProdukt(Projekt *project, const string& name, const string &beschreibung, const int &wert);

	
	AutoTest();
};

#endif