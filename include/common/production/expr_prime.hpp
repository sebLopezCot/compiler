#ifndef __EXPR_PRIME_HPP
#define __EXPR_PRIME_HPP

#include <memory>

#include "common/production/production.hpp"
#include "common/production/add_op.hpp"
#include "common/production/sub_op.hpp"

namespace production {

    class ExprPrime : public Production {
    public:
        ExprPrime();
        
        ExprPrime(const std::shared_ptr<AddOp> op, 
                  const std::shared_ptr<ExprPrime> expr_prime);
        
        ExprPrime(const std::shared_ptr<SubOp> op, 
                  const std::shared_ptr<ExprPrime> expr_prime);
        
        ~ExprPrime();
    };

}

#endif

