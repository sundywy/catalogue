#pragma once

#include <iostream>
#include <variant>
#include <optional>
#include <set>

enum class Action {
    Get,
    Delete,
    List,
    Update,
    Create,
};

struct book {
    int id;
    std::string title;
    std::chrono::year year_published;
    std::string isbn;
    std::set<std::string> authors;

    bool operator==(const book&) const = default;
};

template<typename T>
struct parse_result {
    Action action;
    std::optional<T> result;
};

std::variant<parse_result<int>, parse_result<book>> parse_args(const std::vector<std::string>&);