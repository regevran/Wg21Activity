#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>


TEST_CASE("hello-world", "[HelloWorld]")
{
	std::cout << "hello world\n";
}