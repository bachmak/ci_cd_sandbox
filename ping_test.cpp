#define BOOST_TEST_MODULE ping_test

#include <boost/test/unit_test.hpp>

#include "include/ping.hpp"

BOOST_AUTO_TEST_SUITE(pint_test_suite)

    BOOST_AUTO_TEST_CASE(ping_to_google) {
        auto response = Ping("google.com", "80", "/");
        BOOST_TEST(response.find("HTTP/1.1 200 OK") != std::string::npos);
    }

BOOST_AUTO_TEST_SUITE_END()