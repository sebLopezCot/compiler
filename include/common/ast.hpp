#ifndef __AST_HPP
#define __AST_HPP

#include <memory>

#include "common/token/token.hpp"

/* Abstract Syntax Tree (AST) - Data structure encoding program syntax and parse order */

namespace parser {

    struct ASTNode {
        std::shared_ptr<token::Token> token;
        std::shared_ptr<ASTNode> parent;
    };

    class AST {
    public:
        AST();
        ~AST();
    private:
        std::shared_ptr<ASTNode> root;
    };

}

#endif

