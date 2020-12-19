#pragma once
#include <iostream>
#include <string>

#include "Envelope.h"
#include "..\AdditionalClasses\Console.h"
#include "..\AdditionalClasses\Validator.h"
#include "..\AdditionalClasses\Converter.h"

using ISXConsole::Console;
using ISXValidator::Validator;
using ISXEnvelope::Envelope;
using ISXNumberConverter::Converter;

namespace ISXApp
{
	class EnvelopeComparer
	{
	public:
		EnvelopeComparer();

		void Start(const int& argc, char** argv);

	private:
		std::unique_ptr<Envelope> RequestEnvelopeInput(const std::string envelope_name);
		std::unique_ptr<Envelope> CreateEnvelope(const std::string& str_height, const std::string& str_width);
		void CompareEnvelopes() const;

		std::unique_ptr<Envelope> m_first_envelope;
		std::unique_ptr<Envelope> m_second_envelope;
		std::string m_instruction;
	};
}

