#include "logging.h"

logging::logging(std::string logfilename) {
    logfile.open(logfilename, std::ios::out);
}

logging::~logging() {
    logfile.close();
}

int logging::write(const char *left, std::string right) {
    while(true){
        if(!this->lock){
            this->lock = true;
	        right.erase(std::remove(right.begin(), right.end(), '\n'), right.end());
            time_t rawtime;
            time(&rawtime);
            std::string time_str(ctime(&rawtime));
            logfile << time_str.substr(0, time_str.size()-1) << " " << left << " " << right << std::endl;
            this->lock = false;
            break;
        }
        else
            std::this_thread::slee;_for(std::chrono::milliseconds(1));
    }
    return 0;
}
