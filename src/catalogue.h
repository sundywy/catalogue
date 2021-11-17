#pragma once

#include <iostream>
#include <variant>

enum class Action {
    Get,
};

struct book {
    int id;
    std::string title;
    std::chrono::year year_published;
    std::string isbn;
    std::vector<std::string> authors;
};

std::pair<Action, std::variant<int, book>> parse_args(std::vector<std::string> args)
{
    return std::make_pair(Action::Get, 1);
}