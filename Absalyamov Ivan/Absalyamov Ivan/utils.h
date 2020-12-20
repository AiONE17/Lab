#pragma once
#include <iostream>
inline int proves(int verhgran, int nizhgran) {
	float vvedchis;
	while ((std::cin >> vvedchis).fail() || (vvedchis - floor(vvedchis)) || (vvedchis > verhgran) || (vvedchis < nizhgran))
	{
		std::cout << "Некорректно заданное число\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	return vvedchis;
}
inline float proveofeffect(int verhgran, int nizhgran) {
	float vvedeffect;
	while ((std::cin >> vvedeffect).fail() || (vvedeffect > verhgran) || (vvedeffect < nizhgran))
	{
		std::cout << "Некорректно заданное число\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	return vvedeffect;
}
 inline int provewith0(int verhgran, int nizhgran) {
	 float vvedchis;
	 while ((std::cin >> vvedchis).fail() || (vvedchis - floor(vvedchis)) || (vvedchis > verhgran) || (vvedchis < nizhgran) && (vvedchis != 0))
	 {
		 std::cout << "Некорректно заданное число\n";
		 std::cin.clear();
		 std::cin.ignore(256, '\n');
	 }
	 return vvedchis;
 }
