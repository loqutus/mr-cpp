#include "main.h"

int main(int argc, char **argv) {
    const std::string conf_file("../slave/slave.conf");
    confreader conf(conf_file);
    logging log(conf.get(std::string("log")));
    log.write("starting slave");
    log.write("read config file", conf_file);
    const std::string server_port = conf.get(std::string("port"));
	log.write("port", server_port);
	while(true){
    	tcpserver server(server_port);
    	log.write("listening");
    	server.accept();
    	log.write("master connected");
    	std::string s = server.read();
		json json_object(s);
		std::unordered_map<std::string, std::string> json_map = json_object.get_map();
		std::string action = json_map[std::string("action")];
		log.write("received: ", s);
		server.write(std::string("boom"));
	}
    log.write("exiting");
    return 0;
}
