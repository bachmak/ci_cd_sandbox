#include <iostream>

#include "include/ping.hpp"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        std::cout << "Usage: <url> <port> <target>\nExample: google.com 80 /" << std::endl;
        return EXIT_FAILURE;
    }

    const auto url = argv[1];
    const auto port = argv[2];
    const auto target = argv[3];

    try {
        std::cout << Ping(url, port, target);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
