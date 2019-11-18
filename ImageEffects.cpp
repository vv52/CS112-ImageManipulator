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
	vector<vector<Pixel>> dataYX_blur;
	vector<Pixel> dataRaw = project.getPixelData();
	vector<Pixel> dataRawNew;
	dataRawNew.resize(dataRaw.size());
	int ticker = 0;
	int newTicker = 0;
	int tempRed = 0;
	int tempGreen = 0;
	int tempBlue = 0;
	int imgWidth = 0;
	int imgHeight = 0;

	dataYX.resize(project.getHeight());
	dataYX_blur.resize(dataYX.size());

	for (int i = 0; i < dataYX.size(); i++)
	{
		dataYX[i].resize(project.getWidth());
		dataYX_blur[i].resize(dataYX.size());
	}

	for (int j = 0; j < dataYX.size(); j++)
	{
		for (int k = 0; k < dataYX[j].size(); k++)
		{
			dataYX[j][k] = dataRaw[ticker];
			ticker++;
		}
	}

	imgHeight = dataYX.size() - 1;
	imgWidth = dataYX[0].size() - 1;

	for (int irow = 0; irow < imgHeight; irow++)
	{
		for (int icol = 0; icol < imgWidth; icol++)
		{
			if (irow == 0 && icol == 0)
			{
				tempRed = (dataYX[irow][icol].getRed() + dataYX[irow + 1][icol].getRed()
					+ dataYX[irow][icol + 1].getRed()) / 3;
				tempGreen = (dataYX[irow][icol].getGreen() + dataYX[irow + 1][icol].getGreen()
					+ dataYX[irow][icol + 1].getGreen()) / 3;
				tempBlue - (dataYX[irow][icol].getBlue() + dataYX[irow + 1][icol].getBlue()
					+ dataYX[irow][icol + 1].getBlue()) / 3;
			}
			else if (irow == 0 && icol != 0 && icol != imgWidth)
			{
				tempRed = (dataYX[irow][icol].getRed() + dataYX[irow + 1][icol].getRed()
					+ dataYX[irow][icol - 1].getRed() + dataYX[irow][icol].getRed()) / 4;
				tempGreen = (dataYX[irow][icol].getGreen() + dataYX[irow + 1][icol].getGreen()
					+ dataYX[irow][icol - 1].getGreen() + dataYX[irow][icol + 1].getGreen()) / 4;
				tempBlue = (dataYX[irow][icol].getBlue() + dataYX[irow + 1][icol].getBlue()
					+ dataYX[irow][icol - 1].getBlue() + dataYX[irow][icol + 1].getBlue()) / 4;
			}
			else if (icol == 0 && irow != 0 && irow != imgHeight)
			{
				tempRed = (dataYX[irow][icol].getRed() + dataYX[irow][icol + 1].getRed()
					+ dataYX[irow - 1][icol].getRed() + dataYX[irow + 1][icol].getRed()) / 4;
				tempGreen = (dataYX[irow][icol].getGreen() + dataYX[irow][icol + 1].getGreen()
					+ dataYX[irow - 1][icol].getGreen() + dataYX[irow + 1][icol].getGreen()) / 4;
				tempBlue = (dataYX[irow][icol].getBlue() + dataYX[irow][icol + 1].getBlue()
					+ dataYX[irow - 1][icol].getBlue() + dataYX[irow + 1][icol].getBlue()) / 4;
			}
			else if (irow == 0 && icol == imgWidth)
			{
				tempRed = (dataYX[irow][icol].getRed() + dataYX[irow + 1][icol].getRed()
					+ dataYX[irow][icol - 1].getRed()) / 3;
				tempGreen = (dataYX[irow][icol].getGreen() + dataYX[irow + 1][icol].getGreen()
					+ dataYX[irow][icol - 1].getGreen()) / 3;
				tempBlue = (dataYX[irow][icol].getBlue() + dataYX[irow + 1][icol].getBlue()
					+ dataYX[irow][icol - 1].getBlue()) / 3;
			}
			else if (icol == 0 && irow == imgHeight)
			{
				tempRed = (dataYX[irow][icol].getRed() + dataYX[irow - 1][icol].getRed()
					+ dataYX[irow][icol + 1].getRed()) / 3;
				tempGreen = (dataYX[irow][icol].getGreen() + dataYX[irow - 1][icol].getGreen()
					+ dataYX[irow][icol + 1].getGreen()) / 3;
				tempBlue = (dataYX[irow][icol].getBlue() + dataYX[irow - 1][icol].getBlue()
					+ dataYX[irow][icol + 1].getBlue()) / 3;
			}
			else if (icol == imgHeight && irow == imgWidth)
			{
				tempRed = (dataYX[irow][icol].getRed() + dataYX[irow - 1][icol].getRed()
					+ dataYX[irow][icol - 1].getRed()) / 3;
				tempGreen = (dataYX[irow][icol].getGreen() + dataYX[irow - 1][icol].getGreen()
					+ dataYX[irow][icol - 1].getGreen()) / 3;
				tempBlue = (dataYX[irow][icol].getBlue() + dataYX[irow - 1][icol].getBlue()
					+ dataYX[irow][icol - 1].getBlue()) / 3;
			}
			else if ((irow == imgHeight) && (icol != 0) && (icol != imgWidth))
			{
				tempRed = (dataYX[irow][icol].getRed() + dataYX[irow - 1][icol].getRed()
					+ dataYX[irow][icol + 1].getRed() + dataYX[irow][icol - 1].getRed()) / 4;
				tempGreen = (dataYX[irow][icol].getGreen() + dataYX[irow - 1][icol].getGreen()
					+ dataYX[irow][icol + 1].getGreen() + dataYX[irow][icol - 1].getGreen()) / 4;
				tempBlue = (dataYX[irow][icol].getBlue() + dataYX[irow - 1][icol].getBlue()
					+ dataYX[irow][icol + 1].getBlue() + dataYX[irow][icol - 1].getBlue()) / 4;
			}
			else if ((icol == imgWidth) && (irow != 0) && (irow != imgHeight))
			{
				tempRed = (dataYX[irow][icol].getRed() + dataYX[irow][icol - 1].getRed()
					+ dataYX[irow + 1][icol].getRed() + dataYX[irow - 1][icol].getRed()) / 4;
				tempGreen = (dataYX[irow][icol].getGreen() + dataYX[irow][icol - 1].getGreen()
					+ dataYX[irow + 1][icol].getGreen() + dataYX[irow - 1][icol].getGreen()) / 4;
				tempBlue = (dataYX[irow][icol].getBlue() + dataYX[irow][icol - 1].getBlue()
					+ dataYX[irow + 1][icol].getBlue() + dataYX[irow][icol - 1].getBlue()) / 4;
			}
			else {
				tempRed = (dataYX[irow][icol].getRed() + dataYX[irow - 1][icol].getRed()
					+ dataYX[irow][icol - 1].getRed() + dataYX[irow + 1][icol].getRed()
					+ dataYX[irow][icol + 1].getRed()) / 5;
				tempGreen = (dataYX[irow][icol].getGreen() + dataYX[irow - 1][icol].getGreen()
					+ dataYX[irow][icol - 1].getGreen() + dataYX[irow + 1][icol].getGreen()
					+ dataYX[irow][icol + 1].getGreen()) / 5;
				tempBlue = (dataYX[irow][icol].getBlue() + dataYX[irow - 1][icol].getBlue()
					+ dataYX[irow][icol - 1].getBlue() + dataYX[irow + 1][icol].getBlue()
					+ dataYX[irow][icol + 1].getBlue()) / 5;
			}
			dataYX_blur[irow][icol].setRGB(tempRed, tempGreen, tempBlue);
		}
	}

	for (int n = 0; n < dataYX_blur.size(); n++)
	{
		for (int o = 0; o < dataYX_blur[n].size(); o++)
		{
			dataRawNew[newTicker] = dataYX_blur[n][o];
			newTicker++;
		}
	}

	project.setPixelData(dataRawNew);
	return project;
}

PpmDocument pixelateImage(PpmDocument& project) {
	vector<vector<Pixel>> dataYX;
	vector<Pixel> dataRaw = project.getPixelData();
	int ticker = 0;
	int newTicker = 0;
	int x = 0;
	int pixelDiv = 3;

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

	//Find a clean divisor for pixelation

	while (dataYX.size() % pixelDiv != 0)
	{
		pixelDiv++;
	}

	//Pixelate
	
	for (int l = 0; l < dataYX.size(); l += pixelDiv)
	{
		for (int m = 0; m < dataYX[l].size(); m += pixelDiv)
		{
			for (int z = 0; z < pixelDiv; z++)
			{
				for (int x = 0; x < pixelDiv; x++)
				{
					if ((l + z) > dataYX.size() || (m + x) > dataYX[l].size())
					{
						break;
					}
					else {
						dataYX[l + z][m + x].setRGB(dataYX[l][m].getRed(), dataYX[l][m].getGreen(), dataYX[l][m].getBlue());
					}
				}
			}
		}
	}
	
	for (int n = 0; n < dataYX.size(); n++)
	{
		for (int o = 0; o < dataYX[n].size(); o++)
		{
			dataRaw[newTicker] = dataYX[n][o];
			newTicker++;
		}
	}

	project.setPixelData(dataRaw);
	return project;
}