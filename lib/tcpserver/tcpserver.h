#ifndef PROJECT_HTTPSERVER_H
#define PROJECT_HTTPSERVER_H

#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <string>

class tcpserver {
public:
    tcpserver(std::string port = std::string("9999"), std::string host = std::string("::1"));
    ~tcpserver();
    int accept();
    std::string read();
    int write(std::string message);
private:
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint endpoint;
    boost::asio::ip::tcp::acceptor acceptor;
    boost::asio::ip::tcp::socket socket;
};

#endif //PROJECT_HTTPSERVER_H
