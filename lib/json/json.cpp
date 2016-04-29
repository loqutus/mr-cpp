#include "json.h"

json::json(std::string input){
	this->input_string = input;
}

json::json(std::unordered_map<std::string, std::string> input){
	this->input_map = input;
}

json::~json(){
	input_string.clear();
}

bool json::has_suffix(std::string &str, std::string &suffix)
{
	    return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

std::string json::get_string(){
	std::string suffix("\n");
	std::string str("{");
	for(auto kv:this->input_map){
		std::string first = kv.first;
		std::string second = kv.second;
		if(has_suffix(first, suffix))
			first.pop_back();
		if(has_suffix(second, suffix))
		   second.pop_back();	
		str += " \"";
		str += first;
		str += "\" : \"";
	    str += second;
		str += "\" ,";
	}
	str.pop_back();
	str += "}";
	return str;
}

std::unordered_map<std::string, std::string> json::get_map(){
	std::unordered_map<std::string, std::string> map;
	boost::property_tree::ptree ptree;
	std::stringstream ss;
	ss << input_string;
	boost::property_tree::read_json(ss, ptree);
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, ptree){
		map[v.first] = v.second.data();
	}
	return map;
}

std::list<std::unordered_map<std::string, std::string>> json::get_list_of_maps(){
	std::list<std::unordered_map<std::string, std::string>> result_list;
	boost::property_tree::ptree ptree;
	std::stringstream ss;
	ss << input_string;
	boost::property_tree::read_json(ss, ptree);
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, ptree){
		std::string input_string2 = v.second.data();
		boost::property_tree::ptree ptree2;
		std::stringstream ss2;
		ss2 << input_string2;
		boost::property_tree::read_json(ss2, ptree2);
		std::unordered_map<std::string, std::string> temp_map;
		BOOST_FOREACH(boost::property_tree::ptree::value_type &v2, ptree2){
			temp_map[v2.first] = v2.second.data();
		}
		result_list.push_back(temp_map);
	}
	return result_list;
}
