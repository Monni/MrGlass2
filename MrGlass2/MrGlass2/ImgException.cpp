#include <iostream>
#include <string>
class ImgException {
private:
	std::string message;								// N�ytett�v� viesti
public:
	ImgException(std::string m) : message(m) {}			// Muuttuvan viestin haku

	std::string getMessage() {
		return "ImgException: " + message;				// Viestin tulostus
	}
};