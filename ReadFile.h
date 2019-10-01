#pragma once
#ifndef READ_FILE_H
#define READ_FILE_H

#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> readFile(ifstream& some_file);
vector<string> readFile(const string& file_name);

#endif