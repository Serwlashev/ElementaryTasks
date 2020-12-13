#pragma once
#include <cmath>

namespace ISXEnvelope
{

	class Envelope
	{
	public:
		Envelope(double length, double width);

		friend bool operator <(const Envelope& env1, const Envelope& env2);
		friend bool operator >(const Envelope& env1, const Envelope& env2);

	private:
		double m_height;
		double m_width;
	};

}
