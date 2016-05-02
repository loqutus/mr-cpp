#ifndef PROJECT_STORAGE_H
#define PROJECT_STORAGE_H

#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <thread>

class storage {
	std::unordered_map<std::string, std::unordered_map<std::string, std::string> > slaves_map;
	std::unordered_map<std::string, std::unordered_map<std::string, std::string> > tasks_map;
    bool slaves_lock = false;
    bool tasks_lock = false;
public:
    ~storage();
    int set_slave(std::string key, std::unordered_map<std::string, std::string> value);
    int set_task(std::string key, std::unordered_map<std::string, std::string> value);
	bool is_slaves_empty();
	bool is_tasks_empty();
	std::unordered_map<std::string, std::string> get_slave(std::string key);
	std::unordered_map<std::string, std::string> get_task(std::string key);
	std::vector<std::string> get_slaves_list();
	std::vector<std::string> get_tasks_list();
	
};
extern storage store;

#endif //PROJECT_STORAGE_H
