#include "common/token/mult_op_token.hpp"

using namespace token;

MultOpToken::MultOpToken(int row, int col) : 
    row (row), 
    col (col) {

}

MultOpToken::~MultOpToken() {

}

std::string MultOpToken::Description() const {
    return "MultOpToken";
}
