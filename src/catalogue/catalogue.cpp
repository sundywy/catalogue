#include "catalogue.h"

#include <optional>
#include <string>
#include <vector>
#include <variant>

parse_result<int> parse_get_args(const std::vector<std::string>& args)
{
    return parse_result<int>{
            .action = Action::Get,
            .result = std::stoi(args[2]),
    };
}

parse_result<int> parse_delete_args(const std::vector<std::string>& args)
{
    return parse_result<int>{
            .action = Action::Delete,
            .result = std::stoi(args[2]),
    };
}

parse_result<book> parse_list_args()
{
    return parse_result<book>{.action = Action::List};
}

parse_result<book> parse_create_args(const std::vector<std::string>& args)
{
    return parse_result<book>{
            .action = Action::Create,
            .result = book{
                    .title = args[2],
                    .year_published = std::chrono::year(std::stoi(args[3])),
                    .isbn = args[4],
                    .authors = {args[5]}
            },
    };
}

parse_result<book> parse_update_args(const std::vector<std::string>& args)
{
    return parse_result<book>{
            .action = Action::Update,
            .result = book{
                    .title =     args[2]!="_" ? args[2] : std::string{},
                    .year_published = args[3]!="_" ? std::chrono::year(std::stoi(args[3])) : std::chrono::year{},
                    .isbn = args[4]!="_" ? args[4] : std::string{},
                    .authors = args[5]!="_" ? std::set{args[5]} : std::set<std::string>{}
            }
    };
}

std::variant<parse_result<int>, parse_result<book>> parse_args(const std::vector<std::string>& args)
{
    if (args.size()<2) {
        throw std::runtime_error("no command given");
    }

    if (args[1]=="get") {
        return parse_get_args(args);
    }
    else if (args[1]=="delete") {
        return parse_delete_args(args);
    }
    else if (args[1]=="list") {
        return parse_list_args();
    }
    else if (args[1]=="create") {
        return parse_create_args(args);
    }
    else if (args[1]=="update") {
        return parse_update_args(args);
    }
    throw std::runtime_error("invalid command");
}
