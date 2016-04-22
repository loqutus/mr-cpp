#include "main.h"

int main(int argc, char** argv){
    optparse options(argc, argv);
	std::string host = options.get(std::string("host"));
	std::string port = options.get(std::string("port"));
    tcpclient client(host, port);
	json = options.get(std::string("json"));
	read_file file(json);
	std::string file_str = file.read();
	client.write(file_str);
	std::cout << client.read() << std::endl;
	return 0;
}
