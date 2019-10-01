#include "WriteFile.h"

void writeFile(PpmDocument& write_to_file, const string& file_name) {
	ofstream imgEdit;

	imgEdit.open(file_name);
	imgEdit << write_to_file.getImageFormat() << endl;
	imgEdit << write_to_file.getWidth() << " ";
	imgEdit << write_to_file.getHeight() << endl;
	imgEdit << write_to_file.getColorDepth() << endl;

	vector<Pixel> imagePixelData = write_to_file.getPixelData();

	for (int i = 0; i < write_to_file.getPixelCount(); i++)
	{
		imgEdit << imagePixelData[i].getRed() << " "
			<< imagePixelData[i].getGreen() << " "
			<< imagePixelData[i].getBlue() << " ";
		if ((i + 1) % write_to_file.getWidth() == 0)
		{
			imgEdit << endl;
		}
	}

	imgEdit.close();
}
