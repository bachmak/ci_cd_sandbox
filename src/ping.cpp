#include "include/ping.hpp"

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/lexical_cast.hpp>

namespace http = boost::beast::http;
using boost::asio::ip::tcp;

std::string
Ping(const std::string &host, const std::string &port, const std::string &target) {
    auto ctx = boost::asio::io_context();

    auto query = tcp::resolver::query(host, port);
    auto resolver = tcp::resolver(ctx);
    auto stream = boost::beast::tcp_stream(ctx);

    auto resolve_result = resolver.resolve(query);
    stream.connect(resolve_result);

    auto request = http::request<http::string_body>();
    request.method(http::verb::get);
    request.target(target);
    request.prepare_payload();

    http::write(stream, request);

    auto buffer = boost::beast::flat_buffer();

    auto response = http::response<http::dynamic_body>();
    http::read(stream, buffer, response);

    return boost::lexical_cast<std::string>(response.base());
}
