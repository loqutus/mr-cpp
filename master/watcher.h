#ifndef PROJECT_WATCHER_H
#define PROJECT_WATCHER_H

#include "../lib/confreader/confreader.h"
#include "../lib/logging/logging.h"
#include "../lib/tcpserver/tcpserver.h"
#include "../lib/json/json.h"
#include "../lib/storage/storage.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <chrono>
#include <thread>

class watcher{
public:
	void watch();
};

#endif //PROJECT_WATCHER_H
