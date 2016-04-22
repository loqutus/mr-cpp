#include "logging.h"

logging::logging(std::string logfilename) {
    logfile.open(logfilename, std::ios::out);
}

logging::~logging() {
    logfile.close();
}

int logging::write(const char *left, std::string right) {
	right.erase(std::remove(right.begin(), right.end(), '\n'), right.end());
    time_t rawtime;
    time(&rawtime);
    std::string time_str(ctime(&rawtime));
    logfile << time_str.substr(0, time_str.size()-1) << " " << left << " " << right << std::endl;
    return 0;
}
