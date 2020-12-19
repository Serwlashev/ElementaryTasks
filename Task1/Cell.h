#pragma once
namespace ISXCell
{
	class Cell
	{
	public:
		Cell();
		void SetSymb(const char& symb);
		char GetSumbol() const;
	private:
		char m_symb;
	};
 }

