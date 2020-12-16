#pragma once
#include "..\AdditionalClasses\IGenerator.h"

using ISXBaseGenerator::IGenerator;

namespace ISXFibonacci
{
	class FibonacciGenerator : public IGenerator
	{
	public:
		FibonacciGenerator();
		FibonacciGenerator(unsigned long long max);
		FibonacciGenerator(unsigned long long min, unsigned long long max);

		FibonacciGenerator& operator++();
		bool operator != (const FibonacciGenerator& gen) const;
		unsigned long long operator*() const override;
		unsigned long long GetMaxNumber() const override;
	private:
		unsigned long long FindNum(unsigned long long number, bool is_previous);

		unsigned long long m_max;
		unsigned long long m_min;
		unsigned long long m_current;
	};
}

