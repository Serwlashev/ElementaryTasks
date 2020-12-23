#pragma once
#include <iostream>
#include <string>

#include "Envelope.h"
#include "EnvelopeView.h"
#include "EnvelopeParser.h"

using ISXEnvConsole::EnvelopeView;
using ISXEnvelopeParser::EnvelopeParser;
using ISXEnvelope::Envelope;

namespace ISXApp
{
	class EnvelopeComparer
	{
	public:
		EnvelopeComparer();

		void Start(const int argc, char** argv);

	private:
		const int num_required_params = 5;
		const int empty_params = 1;

		std::unique_ptr<Envelope> RequestEnvelopeInput(const std::string& envelope_name);
		std::unique_ptr<Envelope> CreateEnvelope(const std::string& str_height, const std::string& str_width);
		void CompareEnvelopes() const;

		std::unique_ptr<Envelope> m_first_envelope;
		std::unique_ptr<Envelope> m_second_envelope;
		std::string m_instruction;
	};
}

