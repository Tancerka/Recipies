#include "skladnik.h"
#include "przepis.h"

void Krok::wykonanie_kroku() {

	std::cout << kroki << std::endl;
	std::cout << "Naciœnij SPACE+ENTER, aby kontynuowaæ...\n";	//spacja+enter	

	while (std::cin.get() != ' ') {
		//czeka na spacjê
	}
	system("cls");		//czyszczenie ekranu 
}