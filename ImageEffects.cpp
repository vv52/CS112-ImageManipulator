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

PpmDocument flipHorizontal(PpmDocument& project) {
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

	for (int l = 0; l < dataYX.size(); l++)
	{
		for (int m = 0; m < (dataYX[l].size() / 2); m++)
		{
			int widthTemp = project.getWidth() - 1 - m;
			temp = dataYX[l][m];
			temp2 = dataYX[l][widthTemp];
			dataYX[l][m] = temp2;
			dataYX[l][widthTemp] = temp;
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

PpmDocument rotateNinety(PpmDocument& project) {
	vector<vector<Pixel>> dataYX;
	vector<vector<Pixel>> dataYX_rotated;
	vector<Pixel> dataRaw = project.getPixelData();
	vector<Pixel> dataRawNew;
	dataRawNew.resize(dataRaw.size());
	int ticker = 0;
	int newTicker = 0;
	int x = 0;

	dataYX.resize(project.getHeight());
	dataYX_rotated.resize(dataYX.size());

	for (int i = 0; i < dataYX.size(); i++)
	{
		dataYX[i].resize(project.getWidth());
		dataYX_rotated[i].resize(dataYX.size());
	}

	for (int j = 0; j < dataYX.size(); j++)
	{
		for (int k = 0; k < dataYX[j].size(); k++)
		{
			dataYX[j][k] = dataRaw[ticker];
			ticker++;
		}
	}

	for (int m = project.getWidth() - 1; m >= 0; m--)
	{
		for (int l = 0; l < project.getHeight(); l++)
		{
			dataYX_rotated[x][l] = dataYX[l][m];
		}
		x++;
	}

	for (int n = 0; n < dataYX_rotated.size(); n++)
	{
		for (int o = 0; o < dataYX_rotated[n].size(); o++)
		{
			dataRawNew[newTicker] = dataYX_rotated[n][o];
			newTicker++;
		}
	}

	project.setPixelData(dataRawNew);
	return project;
}

PpmDocument blurImage(PpmDocument& project) {
	vector<vector<Pixel>> dataYX;
	vector<vector<Pixel>> dataYX_rotated;
	vector<Pixel> dataRaw = project.getPixelData();
	vector<Pixel> dataRawNew;
	dataRawNew.resize(dataRaw.size());
	int ticker = 0;
	int newTicker = 0;
	int x = 0;
	int tempRed = 0;
	int tempGreen = 0;
	int tempBlue = 0;

	dataYX.resize(project.getHeight());
	dataYX_rotated.resize(dataYX.size());

	for (int i = 0; i < dataYX.size(); i++)
	{
		dataYX[i].resize(project.getWidth());
		dataYX_rotated[i].resize(dataYX.size());
	}

	for (int j = 0; j < dataYX.size(); j++)
	{
		for (int k = 0; k < dataYX[j].size(); k++)
		{
			dataYX[j][k] = dataRaw[ticker];
			ticker++;
		}
	}

	//iterate thru x dimension averaging values

	for (int l = 0; l < dataYX.size(); l++)
	{
		for (int m = 0; m < dataYX[l].size(); m++)
		{
			if (m == 0)
			{
				tempRed = (dataYX[l][0].getRed() + dataYX[l][1].getRed()) / 2;
				tempGreen = (dataYX[l][0].getGreen() + dataYX[l][1].getGreen()) / 2;
				tempBlue = (dataYX[l][0].getBlue() + dataYX[l][1].getBlue()) / 2;
				dataYX_rotated[l][0].setRGB(tempRed, tempGreen, tempBlue);
			}
			else if (m == (project.getWidth() - 1))
			{
				tempRed = (dataYX[l][project.getWidth() - 1].getRed()
					+ dataYX[l][project.getWidth() - 2].getRed()) / 2;
				tempGreen = (dataYX[l][project.getWidth() - 1].getGreen()
					+ dataYX[l][project.getWidth() - 2].getGreen()) / 2;
				tempBlue = (dataYX[l][project.getWidth() - 1].getBlue()
					+ dataYX[l][project.getWidth() - 2].getBlue()) / 2;
				dataYX_rotated[l][project.getWidth() - 1].setRGB(tempRed, tempGreen, tempBlue);
			}
			else {
				tempRed = (dataYX[l][m - 1].getRed() + dataYX[l][m].getRed()
					+ dataYX[l][m + 1].getRed()) / 3;
				tempGreen = (dataYX[l][m - 1].getGreen() + dataYX[l][m].getGreen()
					+ dataYX[l][m + 1].getGreen()) / 3;
				tempBlue = (dataYX[l][m - 1].getBlue() + dataYX[l][m].getBlue()
					+ dataYX[l][m + 1].getBlue()) / 3;
				dataYX_rotated[l][m].setRGB(tempRed, tempGreen, tempBlue);
			}

		}
	}

	//iterate thru y dimensions averaging values

	for (int p = 0; p < dataYX[0].size(); p++)
	{
		for (int q = 0; q < dataYX.size(); q++)
		{
			if (q == 0)
			{
				tempRed = (dataYX[0][p].getRed() + dataYX[1][p].getRed()) / 2;
				tempGreen = (dataYX[0][p].getGreen() + dataYX[1][p].getGreen()) / 2;
				tempBlue = (dataYX[0][p].getBlue() + dataYX[1][p].getBlue()) / 2;
				dataYX_rotated[0][p].setRGB(tempRed, tempGreen, tempBlue);
			}
			else if (q == (project.getHeight() - 1))
			{
				tempRed = (dataYX[project.getHeight() - 1][p].getRed()
					+ dataYX[project.getHeight() - 2][p].getRed()) / 2;
				tempGreen = (dataYX[project.getHeight() - 1][p].getGreen()
					+ dataYX[project.getHeight() - 2][p].getGreen()) / 2;
				tempBlue = (dataYX[project.getHeight() - 1][p].getBlue()
					+ dataYX[project.getHeight() - 2][p].getBlue()) / 2;
				dataYX_rotated[project.getHeight() - 1][p].setRGB(tempRed, tempGreen, tempBlue);
			}
			else {
				tempRed = (dataYX[q - 1][p].getRed() + dataYX[q][p].getRed()
					+ dataYX[q + 1][p].getRed()) / 3;
				tempGreen = (dataYX[q - 1][p].getGreen() + dataYX[q][p].getGreen()
					+ dataYX[q + 1][p].getGreen()) / 3;
				tempBlue = (dataYX[q - 1][p].getBlue() + dataYX[q][p].getBlue()
					+ dataYX[q + 1][p].getBlue()) / 3;
				dataYX_rotated[q][p].setRGB(tempRed, tempGreen, tempBlue);
			}

		}
	}

	for (int n = 0; n < dataYX_rotated.size(); n++)
	{
		for (int o = 0; o < dataYX_rotated[n].size(); o++)
		{
			dataRawNew[newTicker] = dataYX_rotated[n][o];
			newTicker++;
		}
	}

	project.setPixelData(dataRawNew);
	return project;
}

/*
PpmDocument pixelateImage(PpmDocument& project) {

}
*/