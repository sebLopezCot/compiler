#include "frontend/lexer.hpp"

#include "common/token/numeric_token.hpp"
#include "common/token/add_op_token.hpp"
#include "common/token/sub_op_token.hpp"
#include "common/token/mult_op_token.hpp"
#include "common/token/div_op_token.hpp"

using namespace lexer;

Lexer::Lexer() {

}

Lexer::~Lexer() {

}

lex_result Lexer::Lex(const std::string& raw_program_text) const {
    lex_result result;
    int cursor = 0;
    int line_row = 1;
    int line_col = 1;

    // Catch empty program error
    if (raw_program_text.size() == 0) {
        result.error = "Cannot compile empty program: no text detected.";
        return result;
    }

    // Run through program string
    while (cursor < (int) raw_program_text.size()) {
        // Count lines
        if (raw_program_text[cursor] == '\n') {
            line_row++;
            line_col = 1;
            cursor++;
            continue;
        }

        // Skip whitespace
        if (raw_program_text[cursor] == ' ' || raw_program_text[cursor] == '\t') {
            cursor++;
            line_col++;
            continue;
        }
        
        // Collecting numeric digits
        if (lexer::is_digit(raw_program_text[cursor])) {
            int accum = 0;
            do {
                int digit_val = raw_program_text[cursor] - '0';
                accum = 10 * accum + digit_val;
                cursor++;
                line_col++;
            } while (lexer::is_digit(raw_program_text[cursor]));

            result.tokens.push_back(new token::NumericToken(accum, line_row, line_col));
            continue;
        }

        // Collecting arthimetic operations
        if (raw_program_text[cursor] == PLUS_SIGN) {
            result.tokens.push_back(new token::AddOpToken(line_row, line_col));
            cursor++;
            line_col++;
            continue;
        }

        if (raw_program_text[cursor] == MINUS_SIGN) {
            result.tokens.push_back(new token::SubOpToken(line_row, line_col));
            cursor++;
            line_col++;
            continue;
        }

        if (raw_program_text[cursor] == MULTIPLY_SIGN) {
            result.tokens.push_back(new token::MultOpToken(line_row, line_col));
            cursor++;
            line_col++;
            continue;
        }

        if (raw_program_text[cursor] == DIVIDE_SIGN) {
            result.tokens.push_back(new token::DivOpToken(line_row, line_col));
            cursor++;
            line_col++;
            continue;
        }

        // If we get here, there is a syntax error
        result.error = "Syntax error on line " + std::to_string(line_row)
            + ", column " + std::to_string(line_col) + ": Could not resolve token.";
        result.col = line_col;
        result.row = line_row;
        break;
    }

    return result;
}


