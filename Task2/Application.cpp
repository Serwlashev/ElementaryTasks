#include "Application.h"

ISXApp::Application::Application()
{
	m_first_envelope = nullptr;
	m_second_envelope = nullptr;
	m_instruction = "Enter width and height of two envelopes and we will check if the first envelope can fit in the second envelope\n" 
		"All parameters must be greater than zero, enter them only in numbers.They can also be floating point numbers.\n\n";
}

ISXApp::Application::~Application()
{
	if (m_first_envelope != nullptr) {
		delete m_first_envelope;
	}
	if (m_second_envelope != nullptr) {
		delete m_second_envelope;
	}
}

void ISXApp::Application::Start(const int& argc, char** argv)
{
	bool should_continue = true;

	if (argc == 1) {
		ConsoleManager::PrintMessage(m_instruction);
	}
	else if (argc == 5) {
		m_first_envelope = CreateEnvelope(argv[1], argv[2]);

		if (m_first_envelope != nullptr) {							// If user passed only empty string we shouldn't ask for the second envelope and check them
			m_second_envelope = CreateEnvelope(argv[3], argv[4]);

			CompareEnvelopes();
		}
		should_continue = ConsoleManager::WantContinue();
	}
	else {
		ConsoleManager::PrintMessage("You passed wrong number of parameters!");
		ConsoleManager::PrintMessage(m_instruction);

		should_continue = ConsoleManager::WantContinue();
	}

	while (should_continue) {
		ConsoleManager::PrintMessage("The progamm allows you to check if the first envelope can fit in the second envelope\n");

		m_first_envelope = RequestEnvelopeInput("first envelope");

		if (m_first_envelope != nullptr) {							// If user passed only empty string we shouldn't ask for the second envelope and check them
			m_second_envelope = RequestEnvelopeInput("second envelope");
			
			CompareEnvelopes();
		}
		should_continue = ConsoleManager::WantContinue();
	};

	ConsoleManager::PrintMessage("Goodbay!\n");
}

Envelope* ISXApp::Application::RequestEnvelopeInput(const std::string envelope_name)
{
	std::string str_height = "";
	std::string str_width = "";

	ConsoleManager::PrintMessage("Enter parameters of the " + envelope_name + "\n");

	str_height = ConsoleManager::GetEnvelopeSide("first side");
	str_width = ConsoleManager::GetEnvelopeSide("first side");

	return CreateEnvelope(str_height, str_width);
}

Envelope* ISXApp::Application::CreateEnvelope(const std::string& str_height, const std::string& str_width)
{
	double height = ConvertToDouble(str_height);
	double width = ConvertToDouble(str_width);

	if (height > 0 && width > 0) {		// If we can create envelope we return it
		return new Envelope(height, width);
	}

	ConsoleManager::PrintMessage(m_instruction);

	return nullptr;
}

void ISXApp::Application::CompareEnvelopes() const
{
	if (m_first_envelope != nullptr && m_second_envelope != nullptr) {
		if (m_first_envelope < m_second_envelope) {
			ConsoleManager::PrintMessage("The first envelope can be placed in the second envelope");
		}
		else {
			ConsoleManager::PrintMessage("You do not have possibility to place the first envelope in the second envelope");
		}
	}
}

double ISXApp::Application::ConvertToDouble(const std::string& str)
{
	double res = -1;

	try {
		if (!str.empty() && str != "" && str != " " && HasStringOnlyDigitsPoint(str)) {
			res = stod(str);
		}
	}
	catch (std::out_of_range) {
		ConsoleManager::PrintMessage("You entered too long number");
	}

	return res;
}

bool ISXApp::Application::HasStringOnlyDigitsPoint(const std::string& str)
{
	int count_points = 0;
	for (int i = 0; i < str.length(); i++) {

		if (str[i] == '.') {
			count_points++;
			if (count_points <= 1) {    // If we have more than one point we get false as result
				continue;
			}
		}

		if (!isdigit(str[i])) {			// If we have other symbol
			return false;
		}
	}
	return true;
}