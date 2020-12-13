#pragma once
#include <string>

#include "ConsoleManager.h"
#include "Envelope.h"

using ISXConsole::ConsoleManager;
using ISXEnvelope::Envelope;

namespace ISXApp
{

	class Application
	{
	public:
		Application();
		~Application();

		void Start();

	private:
		Envelope* CreateEnvelope(const std::string& name);
		void CompareEnvelopes() const;

		Envelope* m_first_envelope;
		Envelope* m_second_envelope;

	};
}

