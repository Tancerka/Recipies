#include "skladnik.h"
#include "przepis.h"

void Krok::wykonanie_kroku() {

	std::cout << kroki << std::endl;
	std::cout << "Naci�nij SPACE+ENTER, aby kontynuowa�...\n";	//spacja+enter	

	while (std::cin.get() != ' ') {
		//czeka na spacj�
	}
	system("cls");		//czyszczenie ekranu 
}