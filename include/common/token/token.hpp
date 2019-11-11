#ifndef __TOKEN_HPP
#define __TOKEN_HPP

#include <string>

/* Objects representing program syntax in lexing and parsing */

namespace token {

    class Token {
    public:
        virtual std::string Description() const = 0;
    };
}

#endif

