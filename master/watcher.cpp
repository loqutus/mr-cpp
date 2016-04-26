#include "watcher.h"

void watcher::watch(){
	log_obj.write("Watcher: starting watcher");
	while(true){
			log_obj.write("Watcher: sleeping 60 seconds");
			std::this_thread::sleep_for(std::chrono::milliseconds(60000));
	}
}

