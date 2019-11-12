#ifndef __TERM_PRIME_HPP
#define __TERM_PRIME_HPP

#include <memory>

#include "common/production/production.hpp"
#include "common/production/factor.hpp"
#include "common/production/mult_op.hpp"
#include "common/production/div_op.hpp"

namespace production {

    class TermPrime : public Production {
    public:
        TermPrime();

        TermPrime(const std::shared_ptr<MultOp> op,
                  const std::shared_ptr<Factor> factor,
                  const std::shared_ptr<TermPrime> term_prime);
        
        TermPrime(const std::shared_ptr<DivOp> op, 
                  const std::shared_ptr<Factor> factor,
                  const std::shared_ptr<TermPrime> term_prime);

        ~TermPrime();
    };

}

#endif

