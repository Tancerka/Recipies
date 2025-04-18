#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "przepis.h"

/** Wirtualna klasa przedstawiająca składnik
* \param nazwa - nazwa składnika
*/
class Skladnik {

protected:
	std::string nazwa;
public:

	/** Konstruktor klasy Skladnik
	* \param n - nazwa składnika
	*/
	Skladnik(std::string n) {
		nazwa = n;
	}

	/** Wirtualna metoda pokazania składników
	*/
	virtual void pokaz() = 0;
};

/** Klasa pochodna przedstawiająca przyprawy
*/
class Przyprawy : public Skladnik {

public:

	/** Konstruktor klasy Przyprawy
	* \param n - nazwa przyprawy
	*/
	Przyprawy(std::string n) : Skladnik(n) {
	}

	/** Metoda pokazania na ekran przypraw
	*/
	void pokaz() override {
		std::cout << "- przyprawa:  " << nazwa << std::endl;
	}
};

/** Klasa pochodna przedstawiająca składniki główne
*/

class Skladniki_glowne : public Skladnik {
public:

	/** Konstruktor klasy Skladniki_glowne
	* \param n - nazwa składnika głównego
	*/
	Skladniki_glowne(std::string n) : Skladnik(n) {
	}

	/** Metoda pokazania na ekran składników głównych
	*/
	void pokaz() override {
		std::cout << "- składnik główny: " << nazwa << std::endl;
	}
};
/** Klasa pochodna przedstawiająca dodatki
*/

class Dodatki : public Skladnik {
public:

	/** Konstruktor klasy Dodatki
	* \param n - nazwa dodatku
	*/
	Dodatki(std::string n) : Skladnik(n) {
	}

	/** Metoda pokazania na ekran dodatków
	*/
	void pokaz() override {
		std::cout << "- dodatek: " << nazwa << std::endl;
	}
};

/** Klasa przedstawiająca kroki potrzebne do wykonania dania
* kroki - opis kroku
*/
class Krok {
	std::string kroki;

public:

	/** Metoda wykonania kroku
	*/
	void wykonanie_kroku();

	/** Konstruktor klasy Krok
	* \param k - opis kroku
	*  
	*/
	Krok(std::string k) : kroki(k) {
	}
};
