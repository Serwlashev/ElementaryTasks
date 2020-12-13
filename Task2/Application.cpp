#include "Application.h"

ISXApp::Application::Application()
{
	m_first_envelope = nullptr;
	m_second_envelope = nullptr;
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

void ISXApp::Application::Start()
{
	bool should_continue = false;
	
	do {
		system("cls");
		ConsoleManager::PrintMessage("The progamm allows you to check if the first envelope can fit in the second envelope\n");

		m_first_envelope = CreateEnvelope("first envelope");

		if (m_first_envelope != nullptr) {							// If user passed only empty string we shouldn't ask for the second envelope and check them
			m_second_envelope = CreateEnvelope("second envelope");
			
			CompareEnvelopes();
		}

		should_continue = ConsoleManager::WantContinue();
	} while (should_continue);

	std::cout << "Goodbay!\n";
}

Envelope* ISXApp::Application::CreateEnvelope(const std::string& name)
{
	double height = -1;
	double width = -1;

	ConsoleManager::GetEnvelopeSize(name, height, width);

	if (height > 0 && width > 0) {		// If we can create envelope we return it
		return new Envelope(height, width);
	}

	ConsoleManager::PrintInstruction();

	return nullptr;
}

void ISXApp::Application::CompareEnvelopes() const
{
	if (m_first_envelope != nullptr && m_second_envelope != nullptr) {
		if (m_first_envelope > m_second_envelope) {
			ConsoleManager::PrintMessage("The first envelope can be placed in the second envelope");
		}
		else {
			ConsoleManager::PrintMessage("You do not have possibility to place the first envelope in the second envelope");
		}
	}
}
