#include "ReplacerForString.h"

ISXReplacer::ReplacerForString::ReplacerForString(const std::string& should_be_replaced, const std::string& for_replacing) :
	m_should_be_replaced(should_be_replaced), for_replacing(for_replacing) { }

std::string ISXReplacer::ReplacerForString::Replace(const std::string& maybe_repace)
{
	if (maybe_repace.compare(m_should_be_replaced) == 0) {
		return for_replacing;
	}
	return maybe_repace;
}
