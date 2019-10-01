#pragma once
#ifndef WRITE_FILE_H
#define WRITE_FILE_H

#include <string>
#include <fstream>
#include "PpmDocument.hpp"
using namespace std;

void writeFile(PpmDocument& write_to_file, const string& file_name);

#endif