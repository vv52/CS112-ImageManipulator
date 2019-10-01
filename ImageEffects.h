#pragma once
#ifndef IMAGE_EFFECTS_H
#define IMAGE_EFFECTS_H

#include <string>
#include <fstream>
#include "PpmDocument.hpp"
using namespace std;

void removeRed(PpmDocument project);
void removeBlue(PpmDocument project);
void removeGreen(PpmDocument project);
void negateRed(PpmDocument project);
void negateBlue(PpmDocument project);
void negateGreen(PpmDocument project);
void toGreyscale(PpmDocument project);

#endif