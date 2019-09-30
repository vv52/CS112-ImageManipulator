#pragma once
#ifndef PIXEL_HPP
#define PIXEL_HPP
#include <string>
#include "PpmDocument.hpp"
using namespace std;

class Pixel
{
private:

	int _red = 0;
	int _green = 0;
	int _blue = 0;
	vector<int> _rgb;

public:

	Pixel(int red, int green, int blue)
	{
		_red = red;
		_green = green;
		_blue = blue;

		_rgb.push_back(_red);
		_rgb.push_back(_green);
		_rgb.push_back(_blue);
	}

	Pixel()
	{
	}

	int getRed() const
	{
		return _red;
	}

	int getGreen() const
	{
		return _green;
	}

	int getBlue() const
	{
		return _blue;
	}

	vector<int> getRgb()
	{
		_rgb.push_back(_red);
		_rgb.push_back(_green);
		_rgb.push_back(_blue);

		return _rgb;
	}

	void setRed(int newRed)
	{
		_red = newRed;
	}

	void setGreen(int newGreen)
	{
		_green = newGreen;
	}

	void setBlue(int newBlue)
	{
		_blue = newBlue;
	}

	void setRGB(int newRed, int newGreen, int newBlue)
	{
		_red = newRed;
		_green = newGreen;
		_blue = newBlue;

		_rgb.push_back(_red);
		_rgb.push_back(_green);
		_rgb.push_back(_blue);
	}
};
#endif // !PIXEL_HPP