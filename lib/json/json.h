#ifndef PROJECT_JSON_H
#define PROJECT_JSON_H

#include <fstream>
#include <string>
#include <algorithm>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <unordered_map>
#include <list>

class json {
	std::string input_string;
	std::unordered_map<std::string, std::string> input_map;
	bool has_suffix(std::string &str, std::string &suffix);
public:
	json(std::string input);
	json(std::unordered_map<std::string, std::string> input);
	~json();
	std::unordered_map<std::string, std::string> get_map();
	std::list<std::unordered_map<std::string, std::string> > get_list_of_maps();
	std::string get_string();
};

#endif //PROJECT_JSON_H
