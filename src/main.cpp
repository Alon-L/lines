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

    create_array();

    /*LabelRange range(0, 1);
    Utils::modify_cells(&range, -10);

    for (int i = 0; i < 8; ++i) {
        std::bitset<8> x(g_arr[i]);
        std::cout << x << std::endl;
    }

    std::cout << Utils::get_cells_value(&range) << std::endl;

    Value range2 = new LabelRange(0, 5);
    LabelRange range3(6, 5);
    Utils::modify_cells(&range3, range2);

    std::cout << Utils::get_cells_value(&range3) << std::endl;*/

    string filename = argv[1];
    int line_num = 1;
    string line;

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

    /*while (!line->GetEnded()) {
        Token* token = lexer.NextToken();

        if (token->GetType() == TOKEN_LABEL) {
            auto t = dynamic_cast<LabelToken *>(token);
        } else if (token->GetType() == TOKEN_OPERATOR) {
            auto t = dynamic_cast<OperatorToken *>(token);

            if (t->value.has_value()) {
                auto v = t->value.value();
                cout << t->op << endl;
            } else {
                cout << "no value" << endl;
            }
        }

        delete token;
    }*/

    return 0;
}
