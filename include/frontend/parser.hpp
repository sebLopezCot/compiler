#ifndef __PARSER_HPP
#define __PARSER_HPP

#include <vector>
#include <string>
#include <memory>

#include "common/token/token.hpp"
#include "common/ast.hpp"

#include "common/production/program.hpp"
#include "common/production/stmt.hpp"
#include "common/production/expr.hpp"
#include "common/production/expr_prime.hpp"
#include "common/production/term.hpp"
#include "common/production/term_prime.hpp"
#include "common/production/factor.hpp"
#include "common/production/add_op.hpp"
#include "common/production/sub_op.hpp"
#include "common/production/mult_op.hpp"
#include "common/production/div_op.hpp"

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
        Parser(vector<token::Token*> tokens, bool debug);
        ~Parser();

        parse_result Parse();

    private:
        bool NextToken();
        void ExpandProgram();
        std::shared_ptr<production::Stmt> ExpandStmt();
        std::shared_ptr<production::Expr> ExpandExpr();
        std::shared_ptr<production::ExprPrime> ExpandExprPrime();
        std::shared_ptr<production::Term> ExpandTerm();
        std::shared_ptr<production::TermPrime> ExpandTermPrime();

        vector<token::Token*> tokens;
        int cursor;
        bool debug;
        std::shared_ptr<production::Program> program;
        parse_result result;
    };

}

#endif
