#include "common/ast.hpp"

using namespace parser;

AST::AST() : root (std::make_shared<ASTNode>()) {

}

AST::~AST() {

}

