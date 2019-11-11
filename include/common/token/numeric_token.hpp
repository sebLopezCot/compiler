#ifndef __NUMERIC_TOKEN_HPP
#define __NUMERIC_TOKEN_HPP

#include <string>

#include "token.hpp"

namespace token {

    class NumericToken : public Token {
    public:
        NumericToken(int value, int row, int col);
        ~NumericToken();

        std::string Description() const;

    private:
        int row;
        int col;
        int value;  // integer value of the numeric token
    };

}

#endif

