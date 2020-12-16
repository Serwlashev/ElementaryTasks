#pragma once

namespace ISXBaseGenerator
{
	class IGenerator
	{
	public:
		virtual unsigned long long operator* () const = 0;
		virtual unsigned long long GetMaxNumber() const = 0;
	};
}

