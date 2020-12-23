#pragma once

namespace ISXGenerator
{
	class Generator
	{
	public:
		Generator();
		Generator(unsigned long long max);

		Generator& operator++();
		bool operator <= (const Generator& gen) const;
		bool operator >= (const Generator& gen) const;
		bool operator < (const Generator& gen) const;
		bool operator > (const Generator& gen) const;
		unsigned long long operator*() const;
		unsigned long long GetMaxNumber() const;
		static unsigned long long GetMaxAllowedNumber();
		static unsigned long long GetMinAllowedNumber();

	private:
		unsigned long long m_max;
		unsigned long long m_current;
		static const unsigned long long m_max_allowed_number = 4294967296ULL;
		static const unsigned long long m_min_allowed_number = 1ULL;
	};	

}
