#include "storage.h"

storage::~storage(){
	slaves_map.clear();
	tasks_map.clear();
}

bool storage::is_slaves_empty(){
    while(true){
        if(!this->slaves_lock)
	        return slaves_map.empty();
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

bool storage::is_tasks_empty(){
    while(true){
	    if(!this->tasks_lock)
            return tasks_map.empty();
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int storage::set_slave(std::string key, std::unordered_map<std::string, std::string> value){
    while(true){
        if(!this->slaves_lock){
            this->slaves_lock = true;
	        this->slaves_map[key] = value;
            this->slaves_lock = false;
            break;
        }
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    return 0;
}

int storage::set_task(std::string key, std::unordered_map<std::string, std::string> value){
    while(true){
        if(!this->tasks_lock){
            this->tasks_lock = true;
	        this->tasks_map[key] = value;
            this->tasks_lock = false;
            break;
        }
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    return 0;
}

std::unordered_map<std::string, std::string> storage::get_slave(std::string key){
    while(true){
        if(!this->slaves_lock)
	        return this->slaves_map[key];
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            
    }
}

std::unordered_map<std::string, std::string> storage::get_task(std::string key) {
    while(true){
        if(!this->tasks_lock)
	        return this->tasks_map[key];
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

std::vector<std::string> storage::get_slaves_list(){
	std::vector<std::string> slaves_list;
    while(true){
        if(!this->slaves_lock){
	        for(auto const &iterator: this->slaves_map){
		        slaves_list.push_back(iterator.first);
	        }
            break;
        }
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
	return slaves_list;
}

std::vector<std::string> storage::get_tasks_list(){
	std::vector<std::string> tasks_list;
    while(true){
        if(!this->tasks_lock){
	        for(auto const &iterator: this->tasks_map){
		        tasks_list.push_back(iterator.first);
            }
            break;
	    }
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
	return tasks_list;
}
