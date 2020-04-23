#include <iostream>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/address_v4.hpp>
#include <boost/asio/ip/udp.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/lexical_cast.hpp>

#define PORT 2020

using namespace std;
using namespace boost::asio;

bool send_udp_broadcast(const string &message, const boost::asio::ip::address_v4 &endpoint, const uint16_t port) {
    io_service service;
    ip::udp::socket socket(service);

    auto remote = ip::udp::endpoint(endpoint, port);
    try {
        socket.open(ip::udp::v4());
        socket.set_option(ip::udp::socket::reuse_address(true));
        socket.set_option(socket_base::broadcast(true));
        socket.send_to(buffer(message), remote);
    } catch (boost::system::system_error &exception) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    string broadcast_message;
    if (argc == 2) {
        broadcast_message = boost::lexical_cast<string>(argv[1]);
    } else {
        return 1;
    }

    bool res = send_udp_broadcast(broadcast_message, ip::address_v4::broadcast(), PORT);
    if (res) {
        cout << "Packet broadcasted with message:-" << broadcast_message << endl;
    } else {
        cout << "Exception occured while broadcasting the packet with message:-" << broadcast_message << endl;
    }
    return 0;
}