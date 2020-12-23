#pragma once
#include <cmath>

namespace ISXEnvelope
{

	class Envelope
	{
	public:
		Envelope(double length, double width);

		double GetHeight() const;
		double GetWidth() const;

		static int GetRoundingMultiplier();

		friend bool operator <(const Envelope& env1, const Envelope& env2);
		friend bool operator >(const Envelope& env1, const Envelope& env2);

	private:
		static const int multiplier_for_rounding = 1000;

		double m_height;
		double m_width;
	};

}

