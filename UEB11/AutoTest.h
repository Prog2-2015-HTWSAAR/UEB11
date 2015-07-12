#pragma once
class AutoTest
{
public:
	enum AutomTest{ CREATE_PROJECT, CREATE_FAIL_PROJECT, CREATE_PRODUCT, CREATE_FAIL_PRODUCT, CREATE_AUFGABE, CREATE_FAIL_AUFGABE, CREATE_SUB_PROJECT, CREATE_SUB_FAIL_PROJECT };
	void automaticTest();
	void createProject(string &name, string &beschreibung, int &wert);
	void createProject(string &name, int &wert);
	void createAufgabe(string &name, string &beschreibung, int &wert);
	void createProdukt(string &name, string &beschreibung, int &wert);
	AutoTest();
	~AutoTest();
private:
	Projekt *project;
};

