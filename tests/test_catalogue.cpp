#define CATCH_CONFIG_MAIN
#include "catalogue/catalogue.h"

#include <catch2/catch.hpp>

TEST_CASE("parse_args")
{
    SECTION("parse_args with GET will return enum and book id")
    {
        auto parsed = parse_args({"./catalogue", "get", "1"});
        REQUIRE(std::holds_alternative<parse_result<int>>(parsed));
        auto result = std::get<parse_result<int>>(parsed);
        CHECK(result.action==Action::Get);
        CHECK(result.result==1);
    }

    SECTION("parse_args throw exception when args is less than 2")
    {
        REQUIRE_THROWS(parse_args({"./catalogue"}));
    }

    SECTION("parse_args with DELETE will return enum and book id")
    {
        const auto parsed = parse_args({"./catalogue", "delete", "2"});
        REQUIRE(std::holds_alternative<parse_result<int>>(parsed));
        const auto result = std::get<parse_result<int>>(parsed);
        CHECK(result.action==Action::Delete);
        CHECK(result.result==2);
    }

    SECTION("parse_args with LIST will return enum")
    {
        auto parsed = parse_args({"./catalogue", "list"});
        REQUIRE(std::holds_alternative<parse_result<book>>(parsed));
        auto result = std::get<parse_result<book>>(parsed);
        CHECK(result.action==Action::List);
        CHECK(!result.result);
    }

    SECTION("parse_args with CREATE")
    {
        auto parsed = parse_args(
                {"./catalogue", "create", "Introduction to GNU Octave", "2018", "0359329640", "Jason Lachniet"});
        REQUIRE(std::holds_alternative<parse_result<book>>(parsed));
        auto result = std::get<parse_result<book>>(parsed);
        CHECK(result.action==Action::Create);
        CHECK(result.result==book{
                .title = "Introduction to GNU Octave",
                .year_published = std::chrono::year(2018),
                .isbn = "0359329640",
                .authors = {"Jason Lachniet"},
        });
    }

    SECTION("parse_args with update")
    {
        auto parsed = parse_args(
                {"./catalogue", "update", "Introduction to GNU Octave", "_", "_", "Jason Lachniet"});
        REQUIRE(std::holds_alternative<parse_result<book>>(parsed));
        auto result = std::get<parse_result<book>>(parsed);
        CHECK(result.action==Action::Update);
        CHECK(result.result==book{
                .title = "Introduction to GNU Octave",
                .authors = {"Jason Lachniet"},
        });
    }

}
