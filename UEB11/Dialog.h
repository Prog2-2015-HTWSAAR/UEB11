#pragma once
class Dialog
{
public:
	void automaticTest();
	Dialog();
	~Dialog();
private:
	Projekt *project, *teilprojekt;
	Aufgabe *entwurf, *produktion;
	Produkt *prototyp;
};

