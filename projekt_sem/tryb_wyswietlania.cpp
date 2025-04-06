#include <iostream>
#include <fstream>
#include <sstream>
#include <locale.h>
#include "przepis.h"
#include "skladnik.h"


int main() {

	setlocale(LC_CTYPE, "Polish");
	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "Witamy! To twój najnowocześniejszy Termomix! Stęskniliśmy się za tobą (*^v^*)\n";
	std::cout << "-----------------------------------------------------------------------\n";

	int wybrana_opcja;
	std::string opcja_gotowe;
	std::ofstream oplikp;
	std::ifstream iplikp;

wybieranie_opcji:
	std::cout << "Od czego zaczynamy? Wybierz odpowiednią opcję:\n\nOpcja numer 1.: dodaj przepis\nOpcja numer 2.: użyj przepisu\nOpcja numer 3.: wyjdź\n";
	std::cin >> wybrana_opcja;
	std::string nazwa_przepis;
	if (wybrana_opcja == 1) {
		std::cout << "Jaki przepis chcesz dodać?\n";
		std::cin >> nazwa_przepis;
		std::ofstream plik_zbior_przepisow;
		plik_zbior_przepisow.open("zbior_przepisow.txt", std::ios_base::app);
		
		if (true) {

			plik_zbior_przepisow << nazwa_przepis << std::endl;
			plik_zbior_przepisow.close();		
		}

		Przepis p;
		oplikp.open(nazwa_przepis+".txt");
		
		std::cout << "Teraz możesz wpisać swój przepis!\n";
		std::cout << "Czy przepis jest gotowy?\n";
		std::cin >> opcja_gotowe;
		oplikp.close();
		if (opcja_gotowe == "Tak" || "tak") {
			goto wybieranie_opcji;
		}
	}
	else if (wybrana_opcja == 2) {
		std::cout << "Co chcesz dzisiaj ugotować? *_*\n";			//otwiera plik przepisów, wypisuje na ekran, po czym po wybraniu przepisu, otwiera go i używa, po skończeniu program się zamyka



		std::ifstream plik_zbior_przepisow;	//ścieżka pliku z daniami
		std::string nazwa;	//nazwa dania, którą ma wyświetlić program
		std::string opcja;	//opcja użytkownika
		int licznik_linii = 0;	//nr dania

			plik_zbior_przepisow.open("zbior_przepisow.txt");
			while(!plik_zbior_przepisow.eof()) {

				getline(plik_zbior_przepisow,nazwa);
				if (nazwa == " ") {		//NIE DZIAŁA
					break;
				}
				licznik_linii++;
				std::cout << licznik_linii<<" - "<< nazwa << "\n";

			}
			plik_zbior_przepisow.close();

			wybieranie_przepisu:		//etykieta potrzebna do funkcji goto, by powtórzyć pytanie przy złym wpisaniu danych
			std::cout << "Którego przepisu chcesz użyć? Wpisz nazwę przepisu bez używania polskich znaków >.<\n";
			std::cin >> opcja;		//tu trzeba wpisać nazwę

			iplikp.open(opcja+".txt");
			if (iplikp) {
			
				Przepis p;
				p.czytaj_przepis(iplikp,p);
				p.pokaz(p);		

				iplikp.close();
				std::cout << "Gotowanie zakończone! <3\nBayo bayo <333";
				exit(0);
			}
			else {
				std::cerr << "Taki plik nie istnieje!\n";
				goto wybieranie_przepisu;
			}
		
	}
	else if (wybrana_opcja == 3) {
		std::cout << "Papa (T_T)\n";
		exit(0);
	}
	else {
		std::cerr << "Wybrana opcja nie istnieje :<\n";
		exit(0);
	}

	return 0; 
}
