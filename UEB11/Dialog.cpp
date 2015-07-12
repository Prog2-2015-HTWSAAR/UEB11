#include "Dialog.h"
#include <iostream>

#include "Projekt.h"
#include "Aufgabe.h"
#include "Produkt.h"

Dialog::Dialog()
{
	Projekt *p = new Projekt("Testprojekt1", 100.0);
	Aufgabe *entwurf = new Aufgabe("Entwurf", "Entwerfen des Produktes", 200);
	Aufgabe *produktion = new Aufgabe("Produktion", "Eigentliches Produzieren", 100);
	Produkt *prototyp = new Produkt("Prototyp", "...", 1000.0);
	Projekt *teilprojekt = new Projekt("Baugruppe");
}
void Dialog::automaticTest(){
	
}

