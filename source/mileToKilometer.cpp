#include <iostream>
#include <string>

int calc(int mile){
	int Kilometer=0;
	Kilometer=mile/0.62137;
	return Kilometer;
	}

int main()
{
	int mile;
	std::cout << "Bitte Meilen eingeben: " << std::endl;
	std::cin >> mile;
	std::cout << mile << " Meilen in Kilometer umgerechnet ergibt ca: " << calc(mile) << std::endl;
	return 0;
}
