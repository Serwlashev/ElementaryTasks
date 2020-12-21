#pragma once
#include <string>
#include <tuple>

#include "Field.h"
#include "ConsoleManager.h"
#include "../AdditionalClasses/Validator.h"
#include "../AdditionalClasses/Converter.h"

using ISXNumberConverter::Converter;
using ISXField::Field;
using ISXManager::ConsoleManager;

namespace ISXApplication
{

	class Application
	{
	public:
		// The method prints the chess field according to entered parameters - height and width
		void Start(const int& argc, char** argv);

	private:
		bool TryCreateField(const std::string& passed_height, const std::string& passed_width);
		std::unique_ptr<Field> CreateField(unsigned int height, unsigned int width);
		void PrintField() const;


		std::unique_ptr<Field> m_field;
	};
}

