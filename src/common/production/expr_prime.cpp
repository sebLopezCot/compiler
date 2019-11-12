#include "common/production/expr_prime.hpp"

using namespace production;

ExprPrime::ExprPrime() {

}

ExprPrime::ExprPrime(const std::shared_ptr<AddOp> op,
        const std::shared_ptr<ExprPrime> expr_prime) {

}

ExprPrime::ExprPrime(const std::shared_ptr<SubOp> op,
        const std::shared_ptr<ExprPrime> expr_prime) {

}

ExprPrime::~ExprPrime() {

}

