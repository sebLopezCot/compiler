#ifndef __PROGRAM_HPP
#define __PROGRAM_HPP

#include <memory>

#include "common/production/production.hpp"
#include "common/production/stmt.hpp"

namespace production {

    class Program : public Production {
    public:
        Program(const std::shared_ptr<Stmt> stmt);
        ~Program();
    };

}

#endif

