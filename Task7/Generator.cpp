#include "Generator.h"

ISXGenerator::Generator::Generator()
{
	m_current = 1ULL;
	m_max = 1ULL;
}

ISXGenerator::Generator::Generator(unsigned long long max) 
{
	m_current = 1ULL;
	m_max = max;
}

ISXGenerator::Generator& ISXGenerator::Generator::operator++()
{
	++m_current;

	return *this;
}

bool ISXGenerator::Generator::operator<=(const Generator& gen) const
{
	return m_current * m_current <= gen.GetMaxNumber();
}

bool ISXGenerator::Generator::operator>=(const Generator& gen) const
{
	return m_current * m_current >= gen.GetMaxNumber();
}

bool ISXGenerator::Generator::operator<(const Generator& gen) const
{
	return m_current * m_current < gen.GetMaxNumber();
}

bool ISXGenerator::Generator::operator>(const Generator& gen) const
{
	return m_current * m_current > gen.GetMaxNumber();
}

unsigned long long ISXGenerator::Generator::operator*() const
{
	return m_current;
}

unsigned long long ISXGenerator::Generator::GetMaxNumber() const
{
	return m_max;
}

unsigned long long ISXGenerator::Generator::GetMaxAllowedNumber()
{
	return m_max_allowed_number;
}

unsigned long long ISXGenerator::Generator::GetMinAllowedNumber()
{
	return m_min_allowed_number;
}

