
/* Compiler Main */

#include <iostream>
#include <string>

#include "compiler.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "No program specified" << endl;
        cout << "Valid use: ./compiler [PROGRAM FILE] [--debug (optional)]" << endl;
        return 1;
    }

    // Check if file exists and should be parsed
    string program_filename(argv[1]);
    if (!compiler::is_valid_file(program_filename)) {
        cout << "Invalid file \"" << argv[1] << "\" was specified." << endl <<
                "Make file exists and to use .zsl file extensions." << endl;
        return 1;
    }

    // Debug mode if requested
    bool debug = (argc > 2 && std::string(argv[2]) == "--debug") ? true : false;
    if (debug) {
        cout << "==================== Running in DEBUG mode =======================" << endl;
    }

    // Begin compilation
    cout << "Attempting to compile " << argv[1] << endl;

    compiler::Compiler comp(program_filename, debug);
    comp.Run();

    return 0;
}

