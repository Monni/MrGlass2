#include <iostream>
#include <string>
class ImgException {
private:
	std::string message;
public:
	ImgException(std::string m) : message(m) {}

	std::string getMessage() {
		return "ImgException: " + message;
	}
};