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
	string userIn;
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
		<< "7. Greyscale" << endl << "8. Add Random Noise" << endl
		<< "9. High Contrast" << endl << "10. Flip Horizontal" << endl
		<< "Q. Quit Program" << endl
		<< endl << "Selection (please input as # or \"Q\" only): ";
	cin >> userIn;

	PpmDocument editedImage;

	while (userIn != "Q")
	{
		effect = stoi(userIn);

		switch (effect) {
		case 1:
			editedImage = removeRed(sourceImage);
			cout << "Applying Remove Red...";
			break;
		case 2:
			editedImage = removeBlue(sourceImage);
			cout << "Applying Remove Blue...";
			break;
		case 3:
			editedImage = removeGreen(sourceImage);
			cout << "Applying Remove Green...";
			break;
		case 4:
			editedImage = negateRed(sourceImage);
			cout << "Applying Negate Red...";
			break;
		case 5:
			editedImage = negateBlue(sourceImage);
			cout << "Applying Negate Blue...";
			break;
		case 6:
			editedImage = negateGreen(sourceImage);
			cout << "Applying Negate Green...";
			break;
		case 7:
			editedImage = toGreyscale(sourceImage);
			cout << "Applying Greyscale...";
			break;
		case 8:
			editedImage = addNoise(sourceImage);
			cout << "Applying Add Random Noise...";
			break;
		case 9:
			editedImage = highContrast(sourceImage);
			cout << "Applying High Contrast...";
			break;
		case 10:
			editedImage = flipHorizontal(sourceImage);
			cout << "Applying Horizontal Flip...";
			break;
		default:
			cout << "Invalid selection!";
		}

		sourceImage = editedImage;

		cout << endl << endl << "Selection(please input as # or \"Q\" only): ";
		cin >> userIn;
	}
		
	writeFile(editedImage, outputName);

	cout << "Program exiting..." << endl;

	return 0;
}