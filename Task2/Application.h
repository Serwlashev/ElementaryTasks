#pragma once
#include <string>

#include "ConsoleManager.h"
#include "Envelope.h"

using ISXConsoleMngr::ConsoleManager;
using ISXEnvelope::Envelope;

namespace ISXApp
{
	class Application
	{
	public:
		Application();
		~Application();

		void Start(const int& argc, char** argv);

	private:
		Envelope* RequestEnvelopeInput(const std::string envelope_name);
		Envelope* CreateEnvelope(const std::string& str_height, const std::string& str_width);
		void CompareEnvelopes() const;
		double ConvertToDouble(const std::string& str);
		bool HasStringOnlyDigitsPoint(const std::string& str);

		Envelope* m_first_envelope;
		Envelope* m_second_envelope;
		std::string m_instruction;
	};
}

