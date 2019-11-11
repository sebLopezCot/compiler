#include "common/token/add_op_token.hpp"

using namespace token;

AddOpToken::AddOpToken(int row, int col) : 
    row (row), 
    col (col) {

}

AddOpToken::~AddOpToken() {

}

std::string AddOpToken::Description() const {
    return "AddOpToken";
}

