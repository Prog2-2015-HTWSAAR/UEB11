#ifndef AUTOTEST_H_
#define AUTOTEST_H_
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class AutoTest
{
public:
	enum AutomTest{ CREATE_PROJECT, CREATE_FAIL_PROJECT, CREATE_PRODUCT, CREATE_FAIL_PRODUCT, CREATE_AUFGABE, CREATE_FAIL_AUFGABE, CREATE_SUB_PROJECT, CREATE_SUB_FAIL_PROJECT };

	static const int STD_ANSWER_VALUE;
	static const int ZERO_VALUE;
	static const int INPUT_ONE;
	static const int HIGH_VALUE;
	void automaticTest();
	void createProject(string& name, string &beschreibung, int &wert);
	void createProject(string& name, int &wert);
	void createAufgabe(string& name, string &beschreibung, int &wert);
	void createProdukt(string& name, string &beschreibung, int &wert);
	int readIntegerInput();
	double readDoubleInput();
	string readStringInput();
	void clearInput();
	
	AutoTest();
	~AutoTest();
private:
 	Projekt *project;
};

#endif