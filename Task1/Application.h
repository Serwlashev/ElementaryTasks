#pragma once
#include <string>
#include <tuple>

#include "Field.h"
#include "ConsoleManager.h"

using ISXField::Field;
using Console::ConsoleManager;

namespace ISXApplication
{

	class Application
	{
	public:
		Application();
		~Application();

		// The method prints the chess field according to entered parameters - height and width
		void Start(const int& argc, char** argv);

	private:
		bool CreateField(const std::string& passed_height, const std::string& passed_width);
		void PrintField() const;
		int Parse(const std::string& value);

		Field* m_field;
	};
}

