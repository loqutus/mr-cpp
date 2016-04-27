#include "main.h"

std::string add_action(std::string action, std::string name, std::string data){
	std::unordered_map<std::string, std::string> json_map;
	json_map["action"] = action;
	json_map["name"] = name;
	json_map["data"] = data;
	json json_obj(json_map);
	return json_obj.get_string();
	
}

int send_to_server(std::unordered_map<std::string, std::string> json_map, std::string kind, std::string host, std::string port){
	auto name = json_map[kind];
	read_file file(name);
	auto str = file.read();
	tcpclient client(host, port);
	std::cout << add_action(std::string("add_")+kind, name, str);
	client.write(add_action(std::string("add_")+kind, name, str));
	std::cout << client.read() << std::endl;
	client.close();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	return 0;

}
int main(int argc, char** argv){
    optparse options(argc, argv);
	std::string host = options.get(std::string("host"));
	std::string port = options.get(std::string("port"));
    tcpclient json_tcpclient(host, port);
	auto json_name = options.get(std::string("json"));
	read_file json_file(json_name);
	std::string json_file_str = json_file.read();
	json_tcpclient.write(json_file_str);
	std::cout << json_tcpclient.read() << std::endl;
	json_tcpclient.close();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	json json_obj(json_file_str);
	auto json_map = json_obj.get_map();
	if(json_map["action"] == std::string("add_slave")){
		return 0;
	}
	send_to_server(json_map, "map", host, port);
	send_to_server(json_map, "pre_map", host, port);
	send_to_server(json_map, "reduce", host, port);
	send_to_server(json_map, "union", host, port);
	send_to_server(json_map, "data", host, port);
	return 0;
}
