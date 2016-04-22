//
// Created by Ruslan Gustomyasov on 21/11/15.
//

#include "confreader.h"

confreader::confreader(std::string confname) {
    conffile.open(confname, std::ios::in);
    std::string a, b, line;

    while (std::getline(conffile, line)) {
        std::istringstream iss(line);
        if (!(iss >> a >> b)) {
            break;
        }
        conf_map[a] = b;

    }
    conffile.close();
}

confreader::~confreader() {
    conf_map.clear();
}

std::string confreader::get(std::string key) {
    if (conf_map.find(std::string(key)) == conf_map.end()) {
        return std::string("");
    }
    else {
        return conf_map[std::string(key)];
    }
}
