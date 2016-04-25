#include "main.h"

storage store;
confreader conf("../master/master.conf");
logging log_obj(conf.get("log"));

void run_master(){
	master Master;
	Master.listen();
}

void run_watcher(){
	watcher Watcher;
	Watcher.watch();
}

int main(int argc, char **argv) {
	std::thread thread1(run_master);
	std::thread thread2(run_watcher);
	thread1.join();
	thread2.join();
    return 0;
}
