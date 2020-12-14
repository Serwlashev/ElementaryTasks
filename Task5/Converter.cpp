#include "Converter.h"

ISXConverter::Converter::Converter()
{
	m_converter = new ISXNumberConverter::NumberToTextConverter();
}

ISXConverter::Converter::~Converter()
{
	if (m_converter != nullptr) {
		delete m_converter;
	}
}

void ISXConverter::Converter::ShowNumberAsText(const int& argc, char** argv)
{
	if (argc == 1) {
		std::cout << "You can pass an integer number to the main class call and we translate it into the text\n";
	}
	else if (argc > 2) {
		std::cout << "You passed wrong number of arguments!\n";
	}
	else {
		ConvertNumber(argv[1]);
	}
}

void ISXConverter::Converter::ConvertNumber(const std::string& value)
{
	try {
		if (m_converter != nullptr) {
			int number = Parse(value);

			std::cout << m_converter->Convert(number) << "\n";
		}
		else {
			std::cout << "Cannot create an instance of the number converter!\n";
		}
	}
	catch (std::invalid_argument ex) {
		std::cout << ex.what() << "\n";
	}
	catch (std::out_of_range) {
		std::cout << "You passed too long number! Your number should be from -2,147,483,648 to 2,147,483,647\n";
	}
}

int ISXConverter::Converter::Parse(const std::string& value)
{
	int res = 0;

	if (!value.empty() || value != " ") {
		res = std::stoi(value);

		if (value.compare(std::to_string(res)) != 0) {
			throw std::invalid_argument("You should pass an integer number!\n");
		}
	}

	return res;
}
