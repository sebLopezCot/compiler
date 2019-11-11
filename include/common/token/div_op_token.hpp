#ifndef __DIV_OP_TOKEN_HPP
#define __DIV_OP_TOKEN_HPP

#include <string>

#include "token.hpp"

namespace token {

    class DivOpToken : public Token {
    public:
        DivOpToken(int row, int col);
        ~DivOpToken();

        std::string Description() const;
    private:
        int row;
        int col;
    };

}

#endif

