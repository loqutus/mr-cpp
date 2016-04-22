#include "read_file.h"

read_file::read_file(std::string filename) {
    std::ifstream t(filename.c_str());
    file_str = std::string((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
}

std::string read_file::read() {
	return file_str;
}
