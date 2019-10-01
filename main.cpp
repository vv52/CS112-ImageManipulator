#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "PpmDocument.hpp"
#include "Pixel.hpp"
#include "ReadFile.h"
#include "WriteFile.h"
#include "ImageEffects.h"
using namespace std;


int main(int argc, char* argv[])
{
	string fileName;
	string outputName;
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

	switch (effect) {
		case 1 :
			removeRed(sourceImage);
			break;
		case 2 :
			removeBlue(sourceImage);
			break;
		case 3 :
			removeGreen(sourceImage);
			break;
		case 4 :
			negateRed(sourceImage);
			break;
		case 5 :
			negateBlue(sourceImage);
			break;
		case 6 :
			negateGreen(sourceImage);
			break;
		case 7 :
			toGreyscale(sourceImage);
			break;
		default:
			cout << "Invalid selection!";
	}

	writeFile(sourceImage, outputName);

	cout << "Done." << endl << endl << "Program complete";

	return 0;
}