#pragma once
namespace ISXField
{
	class Field
	{
	public:
		Field(int height, int width);

		int get_height() const;
		int get_width() const;

	private:
		int m_height;
		int m_width;
	};
}