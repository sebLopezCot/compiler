#ifndef __STRING_UTILS_HPP
#define __STRING_UTILS_HPP

#include <string>
#include <algorithm>

namespace utils {
    
    inline bool ends_with(std::string const & value, std::string const & ending)
    {
        if (ending.size() > value.size()) return false;
        return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
    }

}

#endif
