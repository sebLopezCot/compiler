#ifndef __MULT_OP_TOKEN_HPP
#define __MULT_OP_TOKEN_HPP

#include <string>

#include "token.hpp"

namespace token {

    class MultOpToken : public Token {
    public:
        MultOpToken(int row, int col);
        ~MultOpToken();

        std::string Description() const;

    private:
        int row;
        int col;
    };

}

#endif

