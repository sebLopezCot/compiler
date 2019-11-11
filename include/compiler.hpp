#ifndef __COMPILER_HPP
#define __COMPILER_HPP

#include <fstream>
#include <string>

#include "common/string_utils.hpp"

namespace compiler {

    // checks to see if the input program file can be considered for compilation
    bool is_valid_file(const std::string& program_filename);

    // Main dispatcher for the compiler, given a validated program filename
    class Compiler {
    public:
        Compiler(const std::string& program_filename, bool debug);
        ~Compiler();
        void Run();
    private:
        std::string _program_filename;
        bool _debug;
    };

}

#endif

