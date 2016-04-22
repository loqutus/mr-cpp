#ifndef PROJECT_READ_FILE_H
#define PROJECT_READ_FILE_H
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

class read_file {
	std::string file_str;
public:
    read_file(std::string filename);
	std::string read();
};


#endif //PROJECT_READ_FILE_H
