#include "tcpclient.h"

tcpclient::tcpclient(std::string host, std::string port) : socket(boost::asio::ip::tcp::socket(aios)) {
    boost::asio::ip::tcp::resolver resolver(aios);
    boost::asio::ip::tcp::resolver::iterator endpoint = resolver.resolve(
            boost::asio::ip::tcp::resolver::query(host.c_str(), port.c_str()));
    boost::asio::connect(socket, endpoint);
}

int tcpclient::write(std::string message) {
    boost::asio::write(socket, boost::asio::buffer(message));
    return 0;
}

std::string tcpclient::read() {
    std::array<char, 1048576> buf;
    size_t len = socket.read_some(boost::asio::buffer(buf), error_code);
    if (error_code == boost::asio::error::eof)
        return std::string(buf.data());
    else if (error_code)
        throw boost::system::system_error(error_code);
	return std::string(buf.data());
}

void tcpclient::close() {
	socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, error_code);
	socket.close(error_code);
}
