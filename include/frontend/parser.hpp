#ifndef __PARSER_HPP
#define __PARSER_HPP

#include <vector>
#include <string>
#include <memory>

#include "common/token/token.hpp"
#include "common/ast.hpp"

using namespace std;

/* Parser - recursive descent parser used for parsing tokens */

namespace parser {
    
    // Upon parsing, we may run into errors. Return a parse_result with
    // a message and the corresponding line row and column in the original text.
    // Otherwise, returns a valid abstract syntax tree representing the parse.
    struct parse_result {
        const std::shared_ptr<AST> syntax_tree;
        string error = "";
        int row = 0;
        int col = 0;
    };

    class Parser {
    public:
        Parser();
        ~Parser();
        parse_result Parse(const vector<token::Token>& tokens) const;
    };

}

#endif
