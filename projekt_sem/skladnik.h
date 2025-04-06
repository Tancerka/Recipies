#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "przepis.h"

/** Wirtualna klasa przedstawiaj�ca sk�adnik
* \param nazwa - nazwa sk�adnika
*/
class Skladnik {

protected:
	std::string nazwa;
public:

	/** Konstruktor klasy Skladnik
	* \param n - nazwa sk�adnika
	*/
	Skladnik(std::string n) {
		nazwa = n;
	}

	/** Wirtualna metoda pokazania sk�adnik�w
	*/
	virtual void pokaz() = 0;
};

/** Klasa pochodna przedstawiaj�ca przyprawy
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

/** Klasa pochodna przedstawiaj�ca sk�adniki g��wne
*/

class Skladniki_glowne : public Skladnik {
public:

	/** Konstruktor klasy Skladniki_glowne
	* \param n - nazwa sk�adnika g��wnego
	*/
	Skladniki_glowne(std::string n) : Skladnik(n) {
	}

	/** Metoda pokazania na ekran sk�adnik�w g��wnych
	*/
	void pokaz() override {
		std::cout << "- sk�adnik g��wny: " << nazwa << std::endl;
	}
};
/** Klasa pochodna przedstawiaj�ca dodatki
*/

class Dodatki : public Skladnik {
public:

	/** Konstruktor klasy Dodatki
	* \param n - nazwa dodatku
	*/
	Dodatki(std::string n) : Skladnik(n) {
	}

	/** Metoda pokazania na ekran dodatk�w
	*/
	void pokaz() override {
		std::cout << "- dodatek: " << nazwa << std::endl;
	}
};

/** Klasa przedstawiaj�ca kroki potrzebne do wykonania dania
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
