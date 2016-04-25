#include "file_write.h"

file_write::file_write(std::string file_name){
	this->file_name = file_name;
}

int file_write::write(std::string data){
	std::ofstream of(this->file_name);
	of << data;
	of.close();
	return 0;
}
