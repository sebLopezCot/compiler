#ifndef __LEXER_HPP
#define __LEXER_HPP

#include <string>
#include <vector>

#include "common/token/token.hpp"

using namespace std;

/* Lexer - used for scanning input program stream into tokens */

namespace lexer {

    // Upon lexing, we may run into errors, Return a lex_result with
    // a potential error message and the corresponding line row and 
    // column in the orignal text. Otherwise, just return lexemes.
    struct lex_result {
        vector<token::Token*> tokens;
        string error = "";
        int row = 0;
        int col = 0;
    };

    const char PLUS_SIGN = '+';
    const char MINUS_SIGN = '-';
    const char MULTIPLY_SIGN = '*';
    const char DIVIDE_SIGN = '/';

    inline bool is_digit(const char& c) {
        return '0' <= c && c <= '9';
    }

    class Lexer {
    public:
        Lexer();
        ~Lexer();
        lex_result Lex(const string& raw_program_text) const;
    };

}

#endif

