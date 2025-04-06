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


/** Klasa przedstawiaj�ca og�ln� struktur� przepisu 
* \param nazwa - nazwa przepisu
* \param skladniki - wektor przechowuj�cy sk�adniki
* \param kroki - wektor przechowuj�cy kroki
*/

class Skladnik;
class Krok;


class Przepis {

	std::string nazwa;
	std::vector<Skladnik*> skladniki;	//wektor sk�adnik�w
	std::vector<Krok*> kroki;			//wektor przechowuj�cy kroki

public:

	/** Metoda czytania pliku z przepisem
	* \param sciezka_pliku - czytany plik
	* \param obiekt - tworzony przepis
	*/
	void czytaj_przepis(std::ifstream &sciezka_pliku, Przepis& obiekt); //Pierwsza linia to nazwa przepisu, druga to "Sk�adniki g��wne", czyta a� do natrafienia "Przyprawy", a potem robi to samo, a� natrafi na "dodatki, potem czyta sk�adniki a� do znalezienia s�owa "Kroki:", ko�czy na znalezieniu "*"

	/** Metoda dodania sk�adnika do wektora sk�adnik�w 
	* \param s - dodawany sk�adnik
	*/
	void dodaj_skladnik(Skladnik* s) {
		skladniki.push_back(s);
	}

	/** Metoda dodania kroku do wektora sk�adnik�w
	* \param k - dodawany krok
	*/
	void dodaj_krok(Krok* k) {
		kroki.push_back(k);
	}

	/** Metoda wypisania przepisu na ekran
	* \param obiekt - tworzony przepis
	*/
	void pokaz(Przepis& obiekt);	//pokazuje ca�o�� przepisu 
};



