#pragma once

namespace ISXFibonacci
{
	class FibonacciGenerator
	{
	public:
		FibonacciGenerator();
		FibonacciGenerator(unsigned long long max);
		FibonacciGenerator(unsigned long long min, unsigned long long max);

		FibonacciGenerator& operator++();
		bool operator != (const FibonacciGenerator& gen) const;
		unsigned long long operator*() const;
		unsigned long long GetMaxNumber() const;

		static unsigned long long GetMaxAlowedNumber();
		static unsigned long long GetMinAlowedNumber();

	private:
		unsigned long long FindNum(unsigned long long number, bool is_previous);

		static const unsigned long long m_max_allowed_number = 4294967296;
		static const unsigned long long m_min_allowed_number = 1;

		unsigned long long m_max;
		unsigned long long m_min;
		unsigned long long m_current;
	};
}

