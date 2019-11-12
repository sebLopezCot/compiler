#ifndef __TERM_HPP
#define __TERM_HPP

#include <memory>

#include "common/production/production.hpp"
#include "common/production/factor.hpp"
#include "common/production/term_prime.hpp"

namespace production {
    
    class Term : public Production {
    public:
        Term(const std::shared_ptr<Factor> factor, 
             const std::shared_ptr<TermPrime> term_prime);
        ~Term();
    };

}

#endif

