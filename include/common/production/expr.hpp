#ifndef __EXPR_HPP
#define __EXPR_HPP

#include <memory>

#include "common/production/production.hpp"
#include "common/production/term.hpp"
#include "common/production/expr_prime.hpp"

namespace production {

    class Expr : public Production {
    public:
        Expr(const std::shared_ptr<Term> term, 
             const std::shared_ptr<ExprPrime> expr_prime);
        ~Expr();
    };

}

#endif

