#ifndef __ADD_OP_TOKEN_HPP
#define __ADD_OP_TOKEN_HPP

#include <string>

#include "token.hpp"

namespace token {

    class AddOpToken : public Token {
    public:
        AddOpToken(int row, int col);
        ~AddOpToken();

        std::string Description() const;

    private:
        int row;
        int col;
    };

}

#endif

