//
// Created by Ruslan Gustomyasov on 31/12/15.
//

#ifndef PROJECT_TCPCLIENT_H
#define PROJECT_TCPCLIENT_H
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <string>
class tcpclient {
public:
    tcpclient(std::string host, std::string port);
    int write(std::string message);
    std::string read();
	void close();
private:
    boost::asio::io_service aios;
    boost::asio::ip::tcp::socket socket;
	boost::system::error_code error_code;
};


#endif //PROJECT_TCPCLIENT_H
