#include "master.h"

master::master() :
	server_port(conf.get(std::string("port")))
{
		log_obj.write("starting master");
		log_obj.write("config: ../master/master.conf");
		log_obj.write("port: ", server_port);
}

void master::listen(){
	while(true){
		tcpserver server(server_port);
		log_obj.write("listening");
		server.accept();
		log_obj.write("client connect");
		std::string s = server.read();
		json json_object(s);
		std::unordered_map<std::string, std::string> json_map = json_object.get_map();
		std::string action = json_map[std::string("action")];
		log_obj.write("client action:", action);
		std::string action_string = this->do_action(json_map);
		server.write(action_string);
	}
}

std::string master::do_action(std::unordered_map<std::string, std::string> json_map){
	std::string return_string;
	std::string action = json_map["action"];
	if (action == std::string("add_slave")){
		std::string slave_name = json_map[std::string("host")] + std::string(":") + json_map[std::string("port")];
		store.set_slave(slave_name, json_map);	
		log_obj.write("add_slave ", slave_name);
		return_string = std::string("slave added");
	}
	else if(action == std::string("add_task")){
		std::string task_name = json_map[std::string("map")];
		store.set_pod(pod_name, json_map);
		log_obj.write("add_task", task_name);
		return_string = std::string("map added");
	}
	return return_string;
}

master::~master(){
	log_obj.write("stopping master");
}
