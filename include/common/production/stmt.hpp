#ifndef __STMT_HPP
#define __STMT_HPP

#include <memory>

#include "common/production/production.hpp"
#include "common/production/expr.hpp"

namespace production {

    class Stmt : public Production {
    public:
        Stmt(const std::shared_ptr<Expr> expr);
        ~Stmt();
    };

}

#endif

