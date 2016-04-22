#ifndef PROJECT_CONFREADER_H
#define PROJECT_CONFREADER_H

#include <string>
#include <fstream>
#include <map>
#include <sstream>

class confreader {
public:
    confreader(std::string confname);

    ~confreader();

    std::string get(std::string key);

private:
    std::ifstream conffile;
    std::map<std::string, std::string> conf_map;
};
extern confreader conf;
#endif
