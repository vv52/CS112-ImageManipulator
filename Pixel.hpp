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
		_rgb.push_back(red);
		_rgb.push_back(green);
		_rgb.push_back(blue);

		//_red = red;
		//_green = green;
		//_blue = blue;

		//_rgb.push_back(_red);
		//_rgb.push_back(_green);
		//_rgb.push_back(_blue);
	}

	Pixel()
	{
	}

	int getRed() const
	{
		return _rgb[0];

		//return _red;
	}

	int getGreen() const
	{
		return _rgb[1];

		//return _green;
	}

	int getBlue() const
	{
		return _rgb[2];

		//return _blue;
	}

	vector<int> getRgb()
	{
		//_rgb.push_back(_red);
		//_rgb.push_back(_green);
		//_rgb.push_back(_blue);

		return _rgb;
	}

	void setRed(int newRed)
	{
		_rgb[0] = newRed;

		//_red = newRed;
	}

	void setGreen(int newGreen)
	{
		_rgb[1] = newGreen;

		//_green = newGreen;
	}

	void setBlue(int newBlue)
	{
		_rgb[2] = newBlue;

		//_blue = newBlue;
	}

	void setRGB(int newRed, int newGreen, int newBlue)
	{
		_rgb[0] = newRed;
		_rgb[1] = newGreen;
		_rgb[2] = newBlue;

		//_red = newRed;
		//_green = newGreen;
		//_blue = newBlue;

		//_rgb.push_back(_red);
		//_rgb.push_back(_green);
		//_rgb.push_back(_blue);
	}
};
#endif // !PIXEL_HPP