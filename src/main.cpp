#include <iostream>
#include <fstream>
#include "lexer.h"
#include "interpreter.h"

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [FILENAME]" << std::endl;
        return EXIT_FAILURE;
    }

    // Initialize the array
    create_array();

    string filename = argv[1];
    int line_num = 1;
    string line;

    // Open the file received from the command line params
    ifstream file(filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            Lexer lexer(line_num, line);
            Interpreter interpreter(&lexer);

            try {
                interpreter.Interpret();
            } catch (const std::exception&) {
                return EXIT_FAILURE;
            }

            line_num++;
        }

        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
