#ifndef PROJECT_TCPSERVER_H
#define PROJECT_TCPSERVER_H

#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <string>
#include <vector>

class tcpserver {
public:
    tcpserver(std::string port = std::string("9999"), std::string host = std::string("::1"));
    std::string read_string();
    int read_file();
private:
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint endpoint;
    boost::asio::ip::tcp::acceptor acceptor;
};

#endif //PROJECT_SERVER_H
