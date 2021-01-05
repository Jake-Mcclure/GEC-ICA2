#include "Rectangle.h"

void Rectangle::Translate(int dx, int dy)
{
	m_left += dx;
	m_right += dx;
	m_top += dy;
	m_bottom += dy;
}

void Rectangle::ClipTo(const Rectangle& other)
{
	if (m_right > other.m_right)
	{
		m_right = other.m_right;
	}
	if (m_left < other.m_left)
	{
		m_left = other.m_left;
	}
	if (m_bottom > other.m_bottom)
	{
		m_bottom = other.m_bottom;
	}
	if (m_top < other.m_top)
	{
		m_top = other.m_top;
	}
}

int Rectangle::width() const
{
	return m_right - m_left;
}

int Rectangle::height() const
{
	return m_bottom - m_top;
}

bool Rectangle::isOnScreen(const Rectangle& other)
{
	if (m_right < other.m_left)
	{
		return false;
	}
	if (m_left > other.m_right)
	{
		return false;
	}
	if (m_top > other.m_bottom)
	{
		return false;
	}
	if (m_bottom < other.m_top)
	{
		return false;
	}
	return true;
}
