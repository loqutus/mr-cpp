#include "read_file.h"

read_file::read_file(std::string file_name) {
	this->file_name = file_name;
}

std::string read_file::read() {
    std::ifstream t(file_name.c_str());
    auto file_str = std::string((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	return file_str;
}
