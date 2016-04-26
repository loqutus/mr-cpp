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
		log_obj.write("1");
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
		std::string task_name = json_map[std::string("name")];
		store.set_task(task_name, json_map);
		log_obj.write("add_task", task_name);
		return_string = std::string("task added");
	}
	else if(action == std::string("add_map")){
		std::string map_name = json_map[std::string("name")];
		write_to_file("map", map_name, json_map["map"]);
		log_obj.write("add_map", map_name);
		return_string = std::string("map added");
	}
	else if(action == std::string("add_reduce")){
		std::string reduce_name = json_map[std::string("name")];
		write_to_file("reduce", reduce_name, json_map["reduce"]);
		log_obj.write("add_reduce", reduce_name);
		return_string = std::string("reduce added");
	}
	else if(action == std::string("add_data")){
		std::string data_name = json_map[std::string("name")];
		write_to_file("data", data_name, json_map["data"]);
		log_obj.write("add_data", data_name);
		return_string = std::string("data added");
	}
	else if(action == std::string("add_union")){
		std::string union_name = json_map[std::string("name")];
		write_to_file("union", union_name, json_map["data"]);
		log_obj.write("union_data", union_name);
		return_string = std::string("union added");
	}
	return return_string;
}

int master::write_to_file(std::string kind, std::string name, std::string data){
	std::string filename = kind + std::string("/") + name;
	file_write wf(filename);	
	return 0;
}

master::~master(){
	log_obj.write("stopping master");
}
