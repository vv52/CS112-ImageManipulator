#pragma once
#ifndef PIXEL_HPP
#define PIXEL_HPP
#include <string>
#include "PpmDocument.hpp"
using namespace std;

// TODO: add overloaded constructor Pixel(vector<int> rgbVector)
//       add overloaded constructor Pixel(int rgbArray[])

class Pixel
{
private:

	int _red = 0;
	int _green = 0;
	int _blue = 0;

public:

	Pixel(int red, int green, int blue)
	{
		_red = red;
		_green = green;
		_blue = blue;
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
		vector<int> rgbValues{ _red, _green, _blue };

		return rgbValues;
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
	}
};
#endif // !PIXEL_HPP