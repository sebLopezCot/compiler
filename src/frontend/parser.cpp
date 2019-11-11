
#include "frontend/parser.hpp"

using namespace parser;

Parser::Parser() {

}

Parser::~Parser() {

}

parse_result Parser::Parse(const std::vector<token::Token>& tokens) const {
    parse_result result;
    if (tokens.size() > 0) {
        return result;
    }
    return result;
}

