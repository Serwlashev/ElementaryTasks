#include "FibonacciGenerator.h"

ISXFibonacci::FibonacciGenerator::FibonacciGenerator()
{
	m_min = 0;
	m_max = 0;
	m_current = 0;
}

ISXFibonacci::FibonacciGenerator::FibonacciGenerator(unsigned long long max)
{
	m_min = m_current = 0;
	m_max = max;
}

ISXFibonacci::FibonacciGenerator::FibonacciGenerator(unsigned long long min, unsigned long long max)
{
	m_max = max;
	m_min = FindNum(min, true);
	m_current = FindNum(min, false);
}

ISXFibonacci::FibonacciGenerator& ISXFibonacci::FibonacciGenerator::operator++()
{
	unsigned long long tmp = m_current;
	m_current += m_min;
	m_min = tmp;

	return *this;
}

bool ISXFibonacci::FibonacciGenerator::operator!=(const FibonacciGenerator& gen) const
{
	return m_current <= gen.GetMaxNumber();
}

unsigned long long ISXFibonacci::FibonacciGenerator::operator*() const
{
	return m_current;
}

unsigned long long ISXFibonacci::FibonacciGenerator::GetMaxNumber() const
{
	return m_max;
}

unsigned long long ISXFibonacci::FibonacciGenerator::FindNum(unsigned long long number, bool is_previous)
{
	unsigned long long previous = 1;
	unsigned long long current = 1;
	unsigned long long tmp;

	while (current < number) {
		tmp = current;
		current += previous;
		previous = tmp;
	}
	if (is_previous) {
		return previous;
	}

	return current;
}
