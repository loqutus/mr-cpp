#include "storage.h"

storage::~storage() {
	slaves_map.clear();
	tasks_map.clear();
}

bool storage::is_slaves_empty(){
	return slaves_map.empty();
}

bool storage::is_tasks_empty(){
	return tasks_map.empty();
}

int storage::set_slave(std::string key, std::unordered_map<std::string, std::string> value){
	this->slaves_map[key] = value;
    return 0;
}

int storage::set_task(std::string key, std::unordered_map<std::string, std::string> value){
	this->tasks_map[key] = value;
    return 0;
}

std::unordered_map<std::string, std::string> storage::get_slave(std::string key){
	return this->slaves_map[key];
}

std::unordered_map<std::string, std::string> storage::get_task(std::string key) {
	return this->tasks_map[key];
}

std::vector<std::string> storage::get_slaves_list(){
	std::vector<std::string> slaves_list;
	for(auto const &iterator: this->slaves_map){
		slaves_list.push_back(iterator.first);
	}
	return slaves_list;
}

std::vector<std::string> storage::get_tasks_list(){
	std::vector<std::string> tasks_list;
	for(auto const &iterator: this->tasks_map){
		tasks_list.push_back(iterator.first);
	}
	return tasks_list;
}

