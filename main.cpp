#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "PpmDocument.hpp"
#include "FileHelpers.h"
#include "Pixel.hpp"
#include "WriteFile.h"
using namespace std;


int main(int argc, char* argv[])
{
	string fileName;
	string outputName;
	//ofstream imgEdit;
	int effect;

	cout << "Enter source file: ";
	cin >> fileName;

	PpmDocument sourceImage(fileName);

	cout << "Enter destination file: ";
	cin >> outputName;

	cout << "*** Image Effects ***" << endl
		<< "1. Remove Red" << endl << "2. Remove Blue" << endl
		<< "3. Remove Green" << endl << "4. Negate Red" << endl
		<< "5. Negate Blue" << endl << "6. Negate Green" << endl
		<< "7. Grayscale" << endl << endl << "Selection (please input as # only): ";
	cin >> effect;

	writeFile(sourceImage, outputName);

	/*
	imgEdit.open(outputName);
	imgEdit << sourceImage.getImageFormat() << endl;
	imgEdit << sourceImage.getWidth() << " ";
	imgEdit << sourceImage.getHeight() << endl;
	imgEdit << sourceImage.getColorDepth() << endl;

	vector<Pixel> imagePixelData = sourceImage.getPixelData();

	for (int i = 0; i < sourceImage.getPixelCount(); i++)
	{
		imgEdit << imagePixelData[i].getRed() << " "
			<< imagePixelData[i].getGreen() << " "
			<< imagePixelData[i].getBlue() << " ";
		if ((i + 1) % sourceImage.getWidth() == 0)
		{
			imgEdit << endl;
		}
	}

	imgEdit.close();
	*/

	cout << "Program complete";

	return 0;
}