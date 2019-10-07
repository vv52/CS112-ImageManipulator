#include "ImageEffects.h"

PpmDocument removeRed(PpmDocument& project)
{
	vector<Pixel> editedPixelData = project.getPixelData();

	for (int i = 0; i < project.getPixelCount(); i++)
	{
		editedPixelData[i].setRed(0);
	}

	project.setPixelData(editedPixelData);

	return project;
}

PpmDocument removeBlue(PpmDocument& project)
{
	vector<Pixel> editedPixelData = project.getPixelData();

	for (int i = 0; i < project.getPixelCount(); i++)
	{
		editedPixelData[i].setBlue(0);
	}

	project.setPixelData(editedPixelData);

	return project;
}

PpmDocument removeGreen(PpmDocument& project)
{
	vector<Pixel> editedPixelData = project.getPixelData();

	for (int i = 0; i < project.getPixelCount(); i++)
	{
		editedPixelData[i].setGreen(0);
	}

	project.setPixelData(editedPixelData);

	return project;
}

PpmDocument negateRed(PpmDocument& project)
{
	vector<Pixel> editedPixelData = project.getPixelData();

	for (int i = 0; i < project.getPixelCount(); i++)
	{
		int currentRed = editedPixelData[i].getRed();
		editedPixelData[i].setRed(255 - currentRed);
	}

	project.setPixelData(editedPixelData);

	return project;
}

PpmDocument negateBlue(PpmDocument& project)
{
	vector<Pixel> editedPixelData = project.getPixelData();

	for (int i = 0; i < project.getPixelCount(); i++)
	{
		int currentBlue = editedPixelData[i].getBlue();
		editedPixelData[i].setBlue(255 - currentBlue);
	}

	project.setPixelData(editedPixelData);

	return project;
}

PpmDocument negateGreen(PpmDocument& project)
{
	vector<Pixel> editedPixelData = project.getPixelData();

	for (int i = 0; i < project.getPixelCount(); i++)
	{
		int currentGreen = editedPixelData[i].getGreen();
		editedPixelData[i].setGreen(255 - currentGreen);
	}

	project.setPixelData(editedPixelData);

	return project;
}

PpmDocument toGreyscale(PpmDocument& project)
{
	vector<Pixel> editedPixelData = project.getPixelData();

	for (int i = 0; i < project.getPixelCount(); i++)
	{
		int currentRed = editedPixelData[i].getRed();
		int currentGreen = editedPixelData[i].getGreen();
		int currentBlue = editedPixelData[i].getBlue();

		int rgbAverage = (currentRed + currentGreen + currentBlue) / 3;
		editedPixelData[i].setRGB(rgbAverage, rgbAverage, rgbAverage);
	}

	project.setPixelData(editedPixelData);

	return project;
}
