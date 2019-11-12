#ifndef __FACTOR_HPP
#define __FACTOR_HPP

#include "common/production/production.hpp"

namespace production {
    
    class Factor : public Production {
    public:
        Factor(int integral_value);
        ~Factor();
    private:
        int integral_value;
    };

}

#endif

