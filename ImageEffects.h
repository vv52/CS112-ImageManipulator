#pragma once
#ifndef IMAGE_EFFECTS_H
#define IMAGE_EFFECTS_H

#include <string>
#include <fstream>
#include <cstdlib>
#include "PpmDocument.hpp"
using namespace std;

PpmDocument removeRed(PpmDocument& project);
PpmDocument removeBlue(PpmDocument& project);
PpmDocument removeGreen(PpmDocument& project);
PpmDocument negateRed(PpmDocument& project);
PpmDocument negateBlue(PpmDocument& project);
PpmDocument negateGreen(PpmDocument& project);
PpmDocument toGreyscale(PpmDocument& project);
PpmDocument addNoise(PpmDocument& project);
PpmDocument highContrast(PpmDocument& project);
PpmDocument flipHorizontal(PpmDocument& project);
PpmDocument flipVertical(PpmDocument& project);
PpmDocument rotateNinety(PpmDocument& project);
//PpmDocument blurImage(PpmDocument& project);
//PpmDocument pixelateImage(PpmDocument& project);

#endif