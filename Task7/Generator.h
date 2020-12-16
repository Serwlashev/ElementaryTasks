#pragma once
#include "..\AdditionalClasses\IGenerator.h"

using ISXBaseGenerator::IGenerator;

namespace ISXGenerator
{
	class Generator : public IGenerator
	{
	public:
		Generator();
		Generator(unsigned long long max);

		Generator& operator++();
		bool operator != (const Generator& gen) const;
		unsigned long long operator*() const override;
		unsigned long long GetMaxNumber() const override;
	private:
		unsigned long long m_max;
		unsigned long long m_current;
	};

}
