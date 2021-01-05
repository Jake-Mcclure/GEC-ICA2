#pragma once
class Rectangle
{
public:
	int m_left, m_right, m_top, m_bottom;

	Rectangle(int left, int right, int top, int bottom) : m_left(left), m_right(right), m_top(top), m_bottom(bottom) {};

	void Translate(int dx, int dy);
	void ClipTo(const Rectangle& other);

	int width() const;
	int height() const;
	bool isOnScreen(const Rectangle&other);
};

