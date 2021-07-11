#include "Point.h"

Point::Point() {}

Point::Point(const short& x, const short& y) :m_x(x), m_y(y)
{ }

Point& Point::SetValues(const short& x, const short& y)
{
	m_x = x;
	m_y = y;
	return *this;
}

Point Point::Move(const short& x, const short& y)
{
	m_x += x;
	m_y += y;
	return *this;
}

Point Point::MoveCopy(const short& x, const short& y) const
{
	Point copy(this->m_x + x, this->m_y + y);
	return copy;
}

Point Point::CopyNMove(const short& x, const short& y)
{
	Point temp(this->m_x, this->m_y);
	this->Move(this->m_x + x, this->m_y + y);
	return temp;
}

short Point::GetX() const
{
	return m_x;
}

short Point::GetY() const
{
	return m_y;
}

std::istream& operator>>(std::istream& is, Point& point)
{
	char let;
	do
	{
		switch (is >> let; let)
		{
		case 'A': case 'a':
			point.m_x = 0;
			break;
		case 'B': case 'b':
			point.m_x = 1;
			break;
		case 'C': case 'c':
			point.m_x = 2;
			break;
		case 'D': case 'd':
			point.m_x = 3;
			break;
		case 'E': case 'e':
			point.m_x = 4;
			break;
		case 'F': case 'f':
			point.m_x = 5;
			break;
		case 'G': case 'g':
			point.m_x = 6;
			break;
		case 'H': case 'h':
			point.m_x = 7;
			break;
		case 'I': case 'i':
			point.m_x = 8;
			break;
		case 'J': case 'j':
			point.m_x = 9;
			break;
		default:
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Неправильно введенная буква!\n";
			point.m_x = -1;
			break;
		}

		is >> point.m_y;
		--point.m_y;

		if (is.fail())
		{
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка ввода!\n";
		}
		else if (point.m_y < 0 || point.m_y > 9)
		{
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Неправильно введенная цифра!" << std::endl;
		}
		else if (point.m_x >= 0 && point.m_x <= 9)
		{
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return is;
		}
	} while (true);
}
