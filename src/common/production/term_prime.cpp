#include "common/production/term_prime.hpp"

using namespace production;

TermPrime::TermPrime() {

}

TermPrime::TermPrime(const std::shared_ptr<MultOp> op,
                     const std::shared_ptr<Factor> factor,
                     const std::shared_ptr<TermPrime> term_prime) {

}

TermPrime::TermPrime(const std::shared_ptr<DivOp> op,
                     const std::shared_ptr<Factor> factor,
                     const std::shared_ptr<TermPrime> term_prime) {

}

TermPrime::~TermPrime() {

}

