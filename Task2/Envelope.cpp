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

bool ISXEnvelope::operator<(const Envelope& env1, const Envelope& env2)
{
	//To avoid the influence of inaccuracy double type, round off the entered number to three digits after the point and then compare them
	return std::round(env1.m_height * 1000) / 1000 < std::round(env2.m_height * 1000) / 1000 &&
			std::round(env1.m_width * 1000) / 1000 < std::round(env2.m_width * 1000) / 1000;
}

bool ISXEnvelope::operator>(const Envelope& env1, const Envelope& env2)
{
	//To avoid the influence of inaccuracy double type, round off the entered number to three digits after the point and then compare them
	return std::round(env1.m_height * 1000) / 1000 > std::round(env2.m_height * 1000) / 1000 &&
			std::round(env1.m_width * 1000) / 1000 > std::round(env2.m_width * 1000) / 1000;

}
