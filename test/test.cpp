#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "catalogue.h"

TEST_CASE("parse_args with GET will return enum and book id")
{
    auto result = parse_args((std::vector<std::string>) {"get", "1"});
    REQUIRE(result.first==Action::Get);
    REQUIRE(std::get<int>(result.second)==1);
}