#include "tcpserver.h"

tcpserver::tcpserver(std::string port, std::string host) : 
endpoint(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(host.c_str()), 
boost::lexical_cast<unsigned short>(port))), 
acceptor(boost::asio::ip::tcp::acceptor(io_service, endpoint)){
}

std::string tcpserver::read_string(){
    boost::asio::ip::tcp::iostream stream;
    boost::system::error_code ec;
    this->acceptor.accept(*stream.rdbuf(), ec);
    std::string s;
    stream >> s;
    return s;
}
