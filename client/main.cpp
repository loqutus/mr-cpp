#include "main.h"

int send_to_server(std::string name, std::string type, std::string filename, std::string host, std::string port){
	tcpclient client(host, port);
	int status = client.write_file(type, name, filename);
    if(status == 1){
        std::cout << type << " " << filename << "upload error";
        return 1;
    }
    std::cout << type << " " << filename << "upload success";
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
	json_tcpclient.write_string("json", json_file_str);
	std::cout << "OK" << std::endl;
	json_tcpclient.close();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	json json_obj(json_file_str);
	auto json_map = json_obj.get_map();
	if(json_map["action"] == std::string("add_slave")){
		return 0;
	}
    std::string name = json_map["name"];
	if(send_to_server(name, "map", json_map["map"], host, port))
        return 1;
	if(send_to_server(name, "pre_map", json_map["pre_map"], host, port))
        return 1;
	if(send_to_server(name, "reduce", json_map["reduce"], host, port))
        return 1;
	if(send_to_server(name, "union", json_map["union"], host, port))
        return 1;
	if(send_to_server(name, "data", json_map["data"], host, port))
        return 1;
	return 0;
}
