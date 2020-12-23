#include "Envelope.h"

ISXEnvelope::Envelope::Envelope(double height, double width)
{
	if (width > height)		// Width is always longer than height
	{
		m_height = height;
		m_width = width;
	}
	else
	{
		m_height = width;
		m_width = height;
	}
}

double ISXEnvelope::Envelope::GetHeight() const
{
	return m_height;
}

double ISXEnvelope::Envelope::GetWidth() const
{
	return m_width;
}

int ISXEnvelope::Envelope::GetRoundingMultiplier()
{
	return multiplier_for_rounding;
}

bool ISXEnvelope::operator<(const Envelope& env1, const Envelope& env2)
{
	//To avoid the influence of inaccuracy double type, round off the entered number to three digits after the point and then compare them
	return std::round(env1.m_height * Envelope::GetRoundingMultiplier()) / Envelope::GetRoundingMultiplier()
		< std::round(env2.m_height * Envelope::GetRoundingMultiplier()) / Envelope::GetRoundingMultiplier() &&
			std::round(env1.m_width * Envelope::GetRoundingMultiplier()) / Envelope::GetRoundingMultiplier()
		< std::round(env2.m_width * Envelope::GetRoundingMultiplier()) / Envelope::GetRoundingMultiplier();
}

bool ISXEnvelope::operator>(const Envelope& env1, const Envelope& env2)
{
	//To avoid the influence of inaccuracy double type, round off the entered number to three digits after the point and then compare them
	return std::round(env1.m_height * Envelope::GetRoundingMultiplier()) / Envelope::GetRoundingMultiplier() >
		std::round(env2.m_height * Envelope::GetRoundingMultiplier()) / Envelope::GetRoundingMultiplier() &&
			std::round(env1.m_width * Envelope::GetRoundingMultiplier()) / Envelope::GetRoundingMultiplier() >
		std::round(env2.m_width * Envelope::GetRoundingMultiplier()) / Envelope::GetRoundingMultiplier();

}
