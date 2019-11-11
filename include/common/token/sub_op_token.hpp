#ifndef __SUB_OP_TOKEN_HPP
#define __SUB_OP_TOKEN_HPP

#include <string>

#include "token.hpp"

namespace token {

    class SubOpToken : public Token {
    public:
        SubOpToken(int row, int col);
        ~SubOpToken();

        std::string Description() const;

    private:
        int row;
        int col;
    };

}

#endif

