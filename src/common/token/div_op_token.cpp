#include "common/token/div_op_token.hpp"

using namespace token;

DivOpToken::DivOpToken(int row, int col) :
    row (row), 
    col (col) {

}

DivOpToken::~DivOpToken() {

}

std::string DivOpToken::Description() const {
    return "DivOpToken";
}

