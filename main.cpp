#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "PpmDocument.hpp"
#include "FileHelpers.h"
#include "Pixel.hpp"
using namespace std;


int main(int argc, char* argv[])
{
	string fileName;
	string outputName;
	ofstream imgEdit;
	int effect;

	cout << "Enter source file: ";
	cin >> fileName;

	PpmDocument sourceImage(fileName);

	cout << "Enter destination file: ";
	cin >> outputName;

	cout << "*** Image Effects ***" << "/n"
		<< "1. Remove Red" << "/n" << "2. Remove Blue" << "/n"
		<< "3. Remove Green" << "/n" << "4. Negate Red" << "/n"
		<< "5. Negate Blue" << "/n" << "6. Negate Green" << "/n"
		<< "7. Grayscale" << "/n" << "/n" << "Selection: ";
	cin >> effect;

	//OUTPUT FILE, currently sort of broken

	imgEdit.open(outputName);
	imgEdit << sourceImage.getImageFormat() << "\n";
	imgEdit << sourceImage.getWidth() << " ";
	imgEdit << sourceImage.getHeight() << "\n";
	imgEdit << sourceImage.getColorDepth() << "\n";

	vector<Pixel> imagePixelData = sourceImage.getPixelData();

	for (int i = 0; i < sourceImage.getPixelCount(); i++)
	{
		imgEdit << imagePixelData[i].getRed() << " "
			<< imagePixelData[i].getGreen() << " "
			<< imagePixelData[i].getBlue() << " ";
		if (i > 0 && i % sourceImage.getWidth() == 0)
		{
			imgEdit << "\n";
		}
	}

	imgEdit.close();

	// !OUTPUT FILE, nothing after this point is "sort of broken"

	cout << "Program complete";

	return 0;
}