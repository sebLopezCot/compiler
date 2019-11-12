
#include "frontend/parser.hpp"

using namespace parser;
using namespace production;

Parser::Parser(std::vector<token::Token*> tokens, bool debug) :
    tokens (tokens),
    cursor (-1),
    debug (debug) {

}

Parser::~Parser() {

}

bool Parser::NextToken() {
    if (this->cursor + 1 < (int) this->tokens.size()) {
        cursor++;
        return true;
    }

    return false;
}

void Parser::ExpandProgram() {
    this->program = std::make_shared<Program>(Program(this->ExpandStmt())); 
}

std::shared_ptr<Stmt> Parser::ExpandStmt() {
    return std::make_shared<Stmt>(Stmt(this->ExpandExpr()));
}

std::shared_ptr<Expr> Parser::ExpandExpr() {
    auto term = this->ExpandTerm();

    if (this->result.error.size() > 0) return std::make_shared<Expr>();

    auto expr_prime = this->ExpandExprPrime();

    if (this->result.error.size() > 0) return std::make_shared<Expr>();

    return std::make_shared<Expr>(Expr(term, expr_prime));
}

std::shared_ptr<ExprPrime> Parser::ExpandExprPrime() {
    if (!this->NextToken()) return std::make_shared<ExprPrime>();

    // TODO: Implement visitor pattern for traversing this branch...
    // also is recursion the best way or should you use a stack like predictive...
}

void Parser::ExpandTerm() {

}

void Parser::ExpandTermPrime() {

}

parse_result Parser::Parse() {
    // Ensure tokens were given
    if (this->tokens.size() == 0) {
        this->result.error = "Parse error: no tokens were passed to parser.";
        return this->result;
    }

    // Run the recursive descent parser, which will modify internal
    // class structures resulting in the final parsed tree or an error.
    this->ExpandProgram();

    return this->result;
}

