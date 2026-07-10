#include <array>
#include <asio/buffer.hpp>
#include <asio/connect.hpp>
#include <asio/io_context.hpp>
#include <asio/ip/address.hpp>
#include <asio/ip/tcp.hpp>
#include <cstddef>
#include <exception>
#include <iostream>
#include <asio.hpp>
#include <system_error>

using asio::ip::tcp;

asio::io_context io_context;
asio::ip::address address = asio::ip::make_address("127.0.0.1");
asio::ip::tcp::endpoint endpoint(address,8080);

int main() {
    try {
        tcp::socket socket(io_context);
        socket.connect(endpoint);
        for(;;) {
            std::array<char,128> buf;
            std::error_code error;
            size_t len = socket.read_some(asio::buffer(buf),error);

            if (error == asio::error::eof)
                break; 
            else if (error)
                throw std::system_error(error); 

            std::cout.write(buf.data(), len);
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}