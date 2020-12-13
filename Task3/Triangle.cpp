#include "Triangle.h"

ISXTriangle::Triangle::Triangle(std::string name, double first_side, double second_side, double third_side)
{
    m_name = name;
    m_first_side = first_side;
    m_second_side = second_side;
    m_third_side = third_side;
}

double ISXTriangle::Triangle::GetSquare() const
{
    double p = (m_first_side + m_second_side + m_third_side) / 2;
    
    return std::sqrt(p * (p - m_first_side) * (p - m_second_side) * (p - m_third_side));
}

std::string ISXTriangle::Triangle::GetName() const
{
    return m_name;
}

std::string ISXTriangle::Triangle::GetTriangleData() const
{
    return "[Triangle " + m_name + "]: " + std::to_string(GetSquare()) + " cm\n";
}

bool ISXTriangle::operator>(const Triangle& tr1, const Triangle& tr2)
{
    return tr1.GetSquare() > tr2.GetSquare();
}

bool ISXTriangle::operator<(const Triangle& tr1, const Triangle& tr2)
{
    return tr1.GetSquare() < tr2.GetSquare();
}

