#include "main.h"
std::string add_action(std::string action, std::string kind, std::string data){
	std::unordered_map<std::string, std::string> json_map;
	json_map["action"] = action;
	json_map[kind] = data;
	json json_obj(json_map);
	return json_obj.get_string();
	
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
	json json_obj(json_file_str);
	auto json_map = json_obj.get_map();
	if(json_map["action"] == std::string("add_slave")){
		return 0;
	}
	auto map_name = json_map[std::string("map")];
	auto reduce_name = json_map[std::string("reduce")];
	auto data_name = json_map[std::string("data")];
	auto union_name = json_map[std::string("union")];
	read_file map_file(map_name);
	read_file reduce_file(reduce_name);
	read_file data_file(data_name);
	read_file union_file(data_name);
	auto map_file_str = map_file.read();
	auto reduce_file_str = reduce_file.read();
	auto data_file_str = data_file.read();
	auto union_file_str = union_file.read();
	tcpclient map_tcpclient(host, port);
	map_tcpclient.write(add_action("add_map", "name", map_file_str));
	std::cout << map_tcpclient.read() << std::endl;
	map_tcpclient.close();
    tcpclient reduce_tcpclient(host, port);
	reduce_tcpclient.write(add_action("add_reduce", "name", reduce_file_str));
	std::cout << reduce_tcpclient.read() << std::endl;
	reduce_tcpclient.close();
	tcpclient data_tcpclient(host, port);
	data_tcpclient.write(add_action("add_data", "name", data_file_str));
	std::cout << data_tcpclient.read() << std::endl;
	data_tcpclient.close();
	tcpclient union_tcpclient(host, port);
	data_tcpclient.write(add_action("add_union", "union", union_file_str));
	std::cout << union_tcpclient.read() << std::endl;
	union_tcpclient.close();
	return 0;
}
