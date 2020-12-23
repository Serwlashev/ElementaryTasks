#pragma once
#include <string>

namespace ISXReplacer
{
	class ReplacerForString
	{
	public:
		ReplacerForString(const std::string& should_be_replaced, const std::string& for_replacing);

		std::string Replace(const std::string& maybe_repace);
	private:
		std::string m_should_be_replaced;
		std::string for_replacing;
	};

}
