/*****************************************************************//**
 * \file   "przepis.h"
 * \brief  plik zawiera definicje klasy przepis
 * 
 * \author Victoria Morawiec
 * \date   July 2023
 *********************************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "skladnik.h"


/** Klasa przedstawiaj¹ca ogóln¹ strukturê przepisu 
* \param nazwa - nazwa przepisu
* \param skladniki - wektor przechowuj¹cy sk³adniki
* \param kroki - wektor przechowuj¹cy kroki
*/

class Skladnik;
class Krok;


class Przepis {

	std::string nazwa;
	std::vector<Skladnik*> skladniki;	//wektor sk³adników
	std::vector<Krok*> kroki;			//wektor przechowuj¹cy kroki

public:

	/** Metoda czytania pliku z przepisem
	* \param sciezka_pliku - czytany plik
	* \param obiekt - tworzony przepis
	*/
	void czytaj_przepis(std::ifstream &sciezka_pliku, Przepis& obiekt); //Pierwsza linia to nazwa przepisu, druga to "Sk³adniki g³ówne", czyta a¿ do natrafienia "Przyprawy", a potem robi to samo, a¿ natrafi na "dodatki, potem czyta sk³adniki a¿ do znalezienia s³owa "Kroki:", koñczy na znalezieniu "*"

	/** Metoda dodania sk³adnika do wektora sk³adników 
	* \param s - dodawany sk³adnik
	*/
	void dodaj_skladnik(Skladnik* s) {
		skladniki.push_back(s);
	}

	/** Metoda dodania kroku do wektora sk³adników
	* \param k - dodawany krok
	*/
	void dodaj_krok(Krok* k) {
		kroki.push_back(k);
	}

	/** Metoda wypisania przepisu na ekran
	* \param obiekt - tworzony przepis
	*/
	void pokaz(Przepis& obiekt);	//pokazuje ca³oœæ przepisu 
};



