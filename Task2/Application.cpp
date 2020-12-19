#include "Application.h"

ISXApp::EnvelopeComparer::EnvelopeComparer()
{
	m_instruction = "Enter width and height of two envelopes and we will check if the first envelope can fit in the second envelope\n" 
		"All parameters must be greater than zero, enter them only in numbers.They can also be floating point numbers.\n\n";
}

void ISXApp::EnvelopeComparer::Start(const int& argc, char** argv)
{
	bool should_continue = true;

	if (argc == 1) {
		Console::PrintMessage(m_instruction);
	}
	else if (argc == 5) {
		m_first_envelope = CreateEnvelope(argv[1], argv[2]);

		if (m_first_envelope) {							// If user passed only empty string we shouldn't ask for the second envelope and check them
			m_second_envelope = CreateEnvelope(argv[3], argv[4]);

			CompareEnvelopes();
		}
		should_continue = Console::WantContinue();
	}
	else {
		Console::PrintMessage("You passed wrong number of parameters!\n");
		Console::PrintMessage(m_instruction);

		should_continue = Console::WantContinue();
	}

	while (should_continue) {
		Console::PrintMessage("\nThe progamm allows you to check if the first envelope can fit in the second envelope\n");

		m_first_envelope = RequestEnvelopeInput("first envelope");

		if (m_first_envelope) {							// If user passed only empty string we shouldn't ask for the second envelope and check them
			m_second_envelope = RequestEnvelopeInput("second envelope");
			
			CompareEnvelopes();
		}
		should_continue = Console::WantContinue();
	};

	Console::PrintMessage("Goodbay!\n");
}

std::unique_ptr<Envelope> ISXApp::EnvelopeComparer::RequestEnvelopeInput(const std::string envelope_name)
{
	std::string str_height = "";
	std::string str_width = "";

	Console::PrintMessage("\nEnter parameters of the " + envelope_name + "\n");

	str_height = Console::GetStringValue("Please, enter first side of the envelope \n");
	str_width = Console::GetStringValue("Please, enter second side of the envelope \n");

	std::unique_ptr<Envelope> envelope = CreateEnvelope(str_height, str_width);

	return std::move(envelope);
}

std::unique_ptr<Envelope> ISXApp::EnvelopeComparer::CreateEnvelope(const std::string& str_height, const std::string& str_width)
{
	if (Validator::IsValid(ISXValidator::ValidationMode::Double, str_height) && Validator::IsValid(ISXValidator::ValidationMode::Double, str_width))
	{
		double height = Converter::ConvertToDouble(str_height);
		double width = Converter::ConvertToDouble(str_width);

		if (height > 0 && width > 0) {		// If we can create envelope we return it
			std::unique_ptr<Envelope> envelope = std::make_unique<Envelope>(height, width);
			return std::move(envelope);
		}
	}
	Console::PrintMessage(m_instruction);

	return nullptr;
}

void ISXApp::EnvelopeComparer::CompareEnvelopes() const
{
	if (m_first_envelope && m_second_envelope) {
		if (*m_first_envelope.get() > *m_second_envelope.get()) {
			Console::PrintMessage("The first envelope can be placed in the second envelope\n\n");
		}
		else {
			Console::PrintMessage("You do not have possibility to place the first envelope in the second envelope\n\n");
		}
	}
}
