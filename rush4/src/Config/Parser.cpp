
#include "Parser.hpp"
#include "Config/Scanner.hpp"
#include <cctype>
#include <cstdio>
#include <optional>
#include <string>

std::optional<int> take_arg(Scanner& scanner) {
    std::optional<int> arg = scanner.take_value<int>();
    if (!arg.has_value()) {
        return {};
    }
    scanner.skip_whitespace();
    if (!scanner.expect(',')) {
        return {};
    }
    scanner.advance();
    scanner.skip_whitespace();
    return arg;
}

std::optional<DashboardConfig> parse_dashboard(std::string content) {
    Scanner scanner(content.c_str());
    std::vector<ModuleConfig> modules = {};

    scanner.skip_whitespace();
    if (!scanner.expect("COLS=")) {
        return {};
    }
    std::optional<int> cols = scanner.take_value<int>();
    if (!cols.has_value()) {
        return {};
    }
    scanner.skip_whitespace();
    if (!scanner.expect("ROWS=")) {
        return {};
    }
    std::optional<int> rows = scanner.take_value<int>();
    if (!cols.has_value()) {
        return {};
    }
    scanner.skip_whitespace();

    while (!scanner.isDone()) {
        scanner.skip_whitespace();
        if (isdigit(scanner.peek())) {
            return {};
        }
        if (isalpha(scanner.peek())) {
            std::string identifier =
                scanner.take_while([](char c) { return std::isalnum(c) && c != '('; });
            scanner.skip_whitespace();
            if (!scanner.expect('(')) {
                return {};
            }
            scanner.advance();
            std::optional<int> posx = take_arg(scanner);
            if (!posx.has_value()) {
                return {};
            }
            std::optional<int> posy = take_arg(scanner);
            if (!posy.has_value()) {
                return {};
            }
            std::optional<int> sizex = take_arg(scanner);
            if (!sizex.has_value()) {
                return {};
            }
            std::optional<int> sizey = scanner.take_value<int>();
            if (!sizey.has_value()) {
                return {};
            }
            scanner.skip_whitespace();
            if (!scanner.expect(")")) {
                return {};
            }
            modules.push_back(ModuleConfig{
                .module_name = identifier,
                .cols = sizex.value(),
                .rows = sizey.value(),
                .posx = posx.value(),
                .posy = posy.value(),
            });
        } else {
            break;
        }
        scanner.advance();
    }

    return std::make_optional<DashboardConfig>(DashboardConfig{
        .modules = modules,
        .rows = rows.value(),
        .cols = cols.value(),
    });
}
