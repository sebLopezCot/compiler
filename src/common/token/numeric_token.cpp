#include "common/token/numeric_token.hpp"

using namespace token;

NumericToken::NumericToken(int value, int row, int col) : 
    row (row),
    col (col),
    value (value) {

}

NumericToken::~NumericToken() {

}

std::string NumericToken::Description() const {
    return "NumericToken <" + std::to_string(this->value) + ">";
}

