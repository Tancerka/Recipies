#include "przepis.h"
#include "skladnik.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


//Pierwsza linia to nazwa przepisu, druga to "Sk³adniki g³ówne", czyta a¿ do natrafienia "Przyprawy", a potem robi to samo, a¿ natrafi na "Dodatki", potem czyta sk³adniki a¿ do znalezienia s³owa "Kroki:"
void Przepis::czytaj_przepis(std::ifstream& sciezka_pliku, Przepis& obiekt) {		

	std::string linia;

	getline(sciezka_pliku, obiekt.nazwa);	//wpisanie nazwy

	while (getline(sciezka_pliku, linia)) {

		if (linia == "Skladniki glowne:") {	//wpisanie sk³adników
			while (getline(sciezka_pliku, linia)) {

				if (linia == "Przyprawy:") {
					break;
				}
				Skladnik* skladnik_glowny = new Skladniki_glowne(linia);
				obiekt.dodaj_skladnik(skladnik_glowny);
			}
		}

		if (linia == "Przyprawy:") {
			while (getline(sciezka_pliku, linia)) {

				if (linia == "Dodatki:") {
					break;
				}
				Skladnik* przyprawa = new Przyprawy(linia);
				obiekt.dodaj_skladnik(przyprawa);
			}
		}

		if (linia == "Dodatki:") {
			while (getline(sciezka_pliku, linia)) {
				if (linia == "Kroki:") {
					break;
				}
				Skladnik* dodatek = new Dodatki(linia);
				obiekt.dodaj_skladnik(dodatek);
			}
		}
		if (linia == "Kroki:") {
			while (getline(sciezka_pliku, linia)) {

				Krok* krok = new Krok(linia);
				obiekt.dodaj_krok(krok);
			}
		}
	}
}	

void Przepis::pokaz(Przepis &obiekt) {
	std::cout << obiekt.nazwa << std::endl;
	std::cout << "Sk³adniki:\n";
	for (const auto& s : skladniki) {
		s->pokaz();
	}
	std::cout << "Kroki:\n";

	for (auto& k : kroki) {
		k->wykonanie_kroku();
	}
}
