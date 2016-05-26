#ifndef PROJECT_TCPCLIENT_H
#define PROJECT_TCPCLIENT_H
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <fstream>
#include <string>

class tcpclient {
public:
    tcpclient(std::string host, std::string port);
    int write_string(std::string type, std::string message);
    int write_file(std::string type, std::string name, std::string filename);
    std::string read_string();
    std::string read_file();
	void close();
private:
	boost::asio::ip::tcp::iostream network_stream;
	std::string host;
	std::string port;
    int buffer_size = 1048576;
};

#endif //PROJECT_TCPCLIENT_H
