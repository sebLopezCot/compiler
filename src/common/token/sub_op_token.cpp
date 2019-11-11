#include "common/token/sub_op_token.hpp"

using namespace token;

SubOpToken::SubOpToken(int row, int col) : 
    row (row), 
    col (col) {

}

SubOpToken::~SubOpToken() {

}

std::string SubOpToken::Description() const {
    return "SubOpToken";
}
