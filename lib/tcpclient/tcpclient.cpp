#include "tcpclient.h"

tcpclient::tcpclient(std::string host, std::string port):
host(host), port(port){
}

int tcpclient::write_string(std::string type, std::string message) {
    this->network_stream.expires_from_now(boost::posix_time::seconds(60));
    this->network_stream.connect(host, port);
    std::string answer;
	if(!this->network_stream)
		return 1;
    this->network_stream << type;
    this->network_stream.flush();
    this->network_stream >> answer;
    if(answer!= std::string("OK"))
        return 1;
	this->network_stream << message;
	this->network_stream.flush();
    this->network_stream >> answer;
    if(answer!=std::string("OK"))
        return 1;
    return 0;
}

int tcpclient::write_file(std::string type, std::string name, std::string filename) {
    std::string answer;
    read_buf = new char[this->buffer_size];
    this->network_stream.expires_from_now(boost::posix_time::seconds(60));
    this->network_stream.connect(host, port);
    if(!this->network_stream)
        return 1;
    std::ifstream is(filename.c_str(), std::ios::in|std::ios::binary);
    if(!is)
        return 1;
    this->network_stream << type;
    this->network_stream.flush();
    this->network_stream >> answer;
    if(answer!=std::string("OK"))
        return 1;
    this->network_stream << name;
    this->network_stream.flush();
    this->network_stream >> answer;
    if (answer!=std::string("OK"))
        return 1;
    while(!is.eof()){
        is.read(this->read_buf, this->buffer_size);
        network_stream << read_buf;
    }
    this->network_stream.flush();
    this->network_stream >> answer;
    if(answer!=std::string("OK"))
        return 1;
	return 0;
}

std::string tcpclient::read_string() {
	std::string read_data;
	this->network_stream >> read_data;
	return read_data;
}

int tcpserver::read_file() {
    std::string 
}

void tcpclient::close() {
	this->network_stream.close();
}
