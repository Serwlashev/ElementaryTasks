#pragma once
#include <memory> 
#include <string>

#include "Field.h"

namespace ISXFactory
{
	class FieldFactory
	{
	public:
		virtual std::unique_ptr<ISXField::Field> Create(const std::string& height, const std::string& width) = 0;
	};

}
