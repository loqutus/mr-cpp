#include "pre_map.h"

int main(int argc, char** argv){
	std::string input_file_name = argv[1];
	std::string output_file_name = argv[2];
	read_file  readfile(input_file_name);
	std::string text_str = readfile.read();
	std::string delimiters(" \n");	
	std::vector<std::string> splits;
	boost::split(splits, text_str, boost::is_any_of(delimiters));
	std::ofstream of(output_file_name);
	for(auto split:splits){
		if(split.find_first_not_of("\t\n ") != std::string::npos)
			of << split << std::endl;	
	}
	of.close();
	return 0;
}
