#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "przepis.h"

/** Wirtualna klasa przedstawiaj¹ca sk³adnik
* \param nazwa - nazwa sk³adnika
*/
class Skladnik {

protected:
	std::string nazwa;
public:

	/** Konstruktor klasy Skladnik
	* \param n - nazwa sk³adnika
	*/
	Skladnik(std::string n) {
		nazwa = n;
	}

	/** Wirtualna metoda pokazania sk³adników
	*/
	virtual void pokaz() = 0;
};

/** Klasa pochodna przedstawiaj¹ca przyprawy
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

/** Klasa pochodna przedstawiaj¹ca sk³adniki g³ówne
*/

class Skladniki_glowne : public Skladnik {
public:

	/** Konstruktor klasy Skladniki_glowne
	* \param n - nazwa sk³adnika g³ównego
	*/
	Skladniki_glowne(std::string n) : Skladnik(n) {
	}

	/** Metoda pokazania na ekran sk³adników g³ównych
	*/
	void pokaz() override {
		std::cout << "- sk³adnik g³ówny: " << nazwa << std::endl;
	}
};
/** Klasa pochodna przedstawiaj¹ca dodatki
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

/** Klasa przedstawiaj¹ca kroki potrzebne do wykonania dania
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
