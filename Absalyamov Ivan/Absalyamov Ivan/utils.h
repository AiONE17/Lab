#pragma once
#include <iostream>
inline int proves(int verhgran, int nizhgran, std::string textoffail) {
	float vvedchis;
	while ((std::cin >> vvedchis).fail() || (vvedchis - floor(vvedchis)) || (vvedchis > verhgran) || (vvedchis < nizhgran))
	{
		std::cout << textoffail;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	return vvedchis;
}
inline float proveofeffect(int verhgran, int nizhgran, std::string textoffail) {
	float vvedeffect;
	while ((std::cin >> vvedeffect).fail() || (vvedeffect > verhgran) || (vvedeffect < nizhgran))
	{
		std::cout << textoffail;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	return vvedeffect;
};
