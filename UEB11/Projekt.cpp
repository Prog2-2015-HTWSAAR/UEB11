/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb11 *.o
 * @file Projekt.cpp
 *
 * @date 10.07.2015
 * author sbastian
 */

#include "Projekt.h"

const char* Projekt::meldungName = "Der Name des Projekts darf nicht leer sein!";
const char* Projekt::meldungStundensatz = "Der Stundensatz muss positiv sein!";
const char* Projekt::meldungPojektVoll = "Die maximale Anzahl an Projektbestandteilen ist erreicht!";

Projekt::Projekt(string name, string beschreibung, double stundensatz) : Projektbestandteil(name, beschreibung), stundensatz(stundensatz){
	if(name.empty()){
		throw ProjektException(meldungName);
	}
	if(stundensatz <= 0){
		throw ProjektException(meldungStundensatz);
	}
	teilTab = new Projektbestandteil*[maxParts];
	teile = 0;
}

Projekt::Projekt(string name, double stundensatz) : Projektbestandteil(name, "keine Beschreibung"), stundensatz(stundensatz){
	teilTab = new Projektbestandteil*[maxParts];
	teile = 0;
}

Projekt::~Projekt() {
	deleteAllParts();
}

void Projekt::add(Projektbestandteil* pbp){
	if(teile < maxParts){
		teilTab[teile++] = pbp;
	}else{
		throw ProjektException(meldungPojektVoll);
	}
}

void Projekt::remove(string name){
	int pos = findProjectPart(name);
	if(pos >= 0){
		delete teilTab[pos];
		if (pos != teile - 1){
			teilTab[pos] = teilTab[teile - 1];
		}
		teilTab[teile - 1] = 0;
		teile--;
	}
}

void Projekt::deleteAllParts(){
	for (int i = 0; i < teile; ++i) {
		delete teilTab[i];
	}
	delete[] teilTab;
	teile = 0;
}
int Projekt::findProjectPart(string name){
	Projektbestandteil* teil = NULL;
	for (int i = 0; i < teile; ++i) {
		teil = teilTab[i];
		if(name.compare(teil->getName()) == 0){
			return i;
		}
	}
	return -1;
}
double Projekt::berechneKosten() {
	int kosten = 0;
	for (int i = 0; i < teile; ++i) {
		kosten += teilTab[i]->berechneKosten(stundensatz);
	}
	return kosten;
}

double Projekt::berechneKosten(double stundensatz){
	return berechneKosten();
}
 ostream& Projekt::ausgeben(ostream& o){
	o << "Projekt: " << getName() << endl;
	o << getBeschreibung() << endl;
	o << "Stundensatz: " << stundensatz << endl;
	o << "Projektbestandteile: " << endl;
	for (int i = 0; i < teile; ++i) {
		teilTab[i]->ausgeben(o);
	}
	o << "Ende Bestandteile" << endl;
	return o;
}
ostream& operator<<(ostream& o, Projekt* pp){
	pp->ausgeben(o);
	return o;
}
