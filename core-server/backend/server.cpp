#include <asio/buffer.hpp>
#include <asio/io_context.hpp>
#include <asio/write.hpp>
#include <exception>
#include <iostream>
#include <asio.hpp>
#include <string>
#include <system_error>

constexpr int port = 8080;

asio::io_context context;
asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), port);
asio::ip::tcp::acceptor acceptor(context, endpoint);

int main()
{
    try 
    {
        for(;;)
        {
            asio::ip::tcp::socket client_socket(context);
            acceptor.accept(client_socket);

            std::string message = "Hello World!";
            std::error_code ignored_error;
            asio::write(client_socket,asio::buffer(message),ignored_error);

        }
    } catch(std::exception e) 
    {
        std::cerr << e.what() << std::endl;
    } 
    return 0;
    
}
 
