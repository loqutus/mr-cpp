#ifndef PROJECT_FILE_WRITE_H
#define PROJECT_FILE_WRITE_H
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

class file_write {
	std::string file_name;
public:
    file_write(std::string file_name);
	int write(std::string data);
};


#endif //PROJECT_FILE_WRITE_H
