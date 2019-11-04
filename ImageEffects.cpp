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

PpmDocument addNoise(PpmDocument& project)
{
	vector<Pixel> editedPixelData = project.getPixelData();
	int noiseValue = 0;

	for (int i = 0; i < project.getPixelCount(); i++)
	{
		noiseValue = ((rand() % 21) - 10);

		int currentRed = editedPixelData[i].getRed();
		currentRed += noiseValue;
		if (currentRed < 0) {
			currentRed = 0;
		}
		else if (currentRed > 255) {
			currentRed = 255;
		}
		editedPixelData[i].setRed(currentRed);

		int currentGreen = editedPixelData[i].getGreen();
		currentGreen += noiseValue;
		if (currentGreen < 0) {
			currentGreen = 0;
		}
		else if (currentGreen > 255) {
			currentGreen = 255;
		}
		editedPixelData[i].setGreen(currentGreen);

		int currentBlue = editedPixelData[i].getBlue();
		currentBlue += noiseValue;
		if (currentBlue < 0) {
			currentBlue = 0;
		}
		else if (currentBlue > 255) {
			currentBlue = 255;
		}
	}

	project.setPixelData(editedPixelData);

	return project;
}

PpmDocument highContrast(PpmDocument& project)
{
	vector<Pixel> editedPixelData = project.getPixelData();

	for (int i = 0; i < project.getPixelCount(); i++)
	{
		int currentRed = editedPixelData[i].getRed();
		if (currentRed > 127) {
			currentRed = 255;
		} else {
			currentRed = 0;
		}

		int currentGreen = editedPixelData[i].getGreen();
		if (currentGreen > 127) {
			currentGreen = 255;
		} else {
			currentGreen = 0;
		}

		int currentBlue = editedPixelData[i].getBlue();
		if (currentBlue > 127) {
			currentBlue = 255;
		} else {
			currentBlue = 0;
		}

		editedPixelData[i].setRGB(currentRed, currentGreen, currentBlue);
	}

	project.setPixelData(editedPixelData);

	return project;
}

/*PpmDocument flipHorizontal(PpmDocument& project) {
	vector<vector<Pixel>> flippedImage;
	vector<Pixel> formattedFlip;
	vector<Pixel> temp = project.getPixelData();

	flippedImage.resize(project.getHeight());

	for (int k = 0; k < flippedImage.size(); k++)
	{
		flippedImage[k].resize(project.getWidth());
	}

	for (int i = 0; i < project.getHeight(); i++)
	{
		for (int j = project.getWidth(); j > 0; j--)
		{
			flippedImage[i][j] = temp[i]; //STILL FIX THIS LINE
		}
	}

	for (int l = 0; l < project.getHeight(); l++)
	{
		for (int m = 0; m < project.getWidth(); m++)
		{
			formattedFlip.push_back(flippedImage[l][m]);
		}
	}

	project.setPixelData(formattedFlip);
	return project;
}*/

PpmDocument flipVertical(PpmDocument& project) {
	vector<vector<Pixel>> dataYX;
	vector<Pixel> dataRaw = project.getPixelData();
	Pixel temp;
	Pixel temp2;
	vector<Pixel> dataRawNew;
	dataRawNew.resize(dataRaw.size());
	int ticker = 0;

	dataYX.resize(project.getHeight());

	for (int i = 0; i < dataYX.size(); i++)
	{
		dataYX[i].resize(project.getWidth());
	}

	for (int j = 0; j < dataYX.size(); j++)
	{
		for (int k = 0; k < dataYX[j].size(); k++)
		{
			dataYX[j][k] = dataRaw[ticker];
			ticker++;
		}
	}

	for (int l = 0; l < dataYX[0].size(); l++)
	{
		for (int m = 0; m < (dataYX.size() / 2); m++)
		{
			int heightTemp = project.getHeight() - 1 - m;
			temp = dataYX[m][l];
			temp2 = dataYX[heightTemp][l];
			dataYX[m][l] = temp2;
			dataYX[heightTemp][l] = temp;
		}
	}

	int newTicker = 0;

	for (int n = 0; n < dataYX.size(); n++)
	{
		for (int o = 0; o < dataYX[n].size(); o++)
		{
			dataRawNew[newTicker] = dataYX[n][o];
			newTicker++;
		}
	}

	project.setPixelData(dataRawNew);
	return project;
}
	/*for (int i = 0; i < dataRaw.size(); i++)
	{
		if (ticker > project.getWidth())
		{
			row++;
		}
		dataXY[row].push_back(dataRaw[i]);
		ticker++;
	}
	
	for (int j = 0; j < project.getWidth(); j++)
	{
		for (int k = 0; k < (project.getHeight() / 2); k++)
		{
			temp = dataXY[project.getHeight() - k][j];
			dataXY[project.getHeight() - k][j] = dataXY[k][j];
			dataXY[k][j] = temp;
		}
	}

	for (int l = 0; l < project.getHeight(); l++)
	{
		for (int m = 0; m < project.getWidth(); m++)
		{
			dataRawNew.push_back(dataXY[l][m]);
		}
	}

	project.setPixelData(dataRawNew);
	return project;*/

/*
PpmDocument rotateNinety(PpmDocument& project) {

}

PpmDocument blurImage(PpmDocument& project) {

}

PpmDocument pixelateImage(PpmDocument& project) {

}
*/