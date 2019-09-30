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

	cout << "Enter source file: ";
	cin >> fileName;

	PpmDocument sourceImage(fileName);

	cout << "Enter destination file: ";
	cin >> outputName;

	int tempTest = sourceImage.getColorDepth();

	cout << tempTest;

	cout << "Program complete";

	return 0;
}