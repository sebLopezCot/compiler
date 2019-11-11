
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

#include "compiler.hpp"
#include "frontend/lexer.hpp"

using namespace compiler;

// checks to see if the input program file can be considered for compilation
bool compiler::is_valid_file(const std::string& program_filename) {
    // Does file exist?
    std::ifstream f(program_filename.c_str());
    if (!f.good()) {
        return false;
    }

    // Is it a ZSL file?
    if (!utils::ends_with(program_filename, ".zsl")) {
        return false;
    }

    return true;
}

Compiler::Compiler(const std::string& program_filename, bool debug) : 
    _program_filename (program_filename),
    _debug (debug) {

}

Compiler::~Compiler() {

}

void Compiler::Run() {
    // Load the program file into a string to parse
    std::ifstream stream(this->_program_filename);
    std::string raw_program_text((std::istreambuf_iterator<char>(stream)),
                                 std::istreambuf_iterator<char>());

    // Generate tokens
    lexer::Lexer lexer;
    lexer::lex_result lex = lexer.Lex(raw_program_text);
    if (lex.error.size() > 0) {
        std::cout << lex.error << std::endl;
        return;
    }

    // If in debug, print out lex results
    if (this->_debug) {
        std::cout << ">>>> Lex Results " << std::endl;
        for (const auto t : lex.tokens) {
            std::cout << t->Description() << ", ";
        }
    }

    std::cout << "Valid lex" << std::endl;
}

