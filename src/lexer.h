#ifndef LINES_LEXER_H
#define LINES_LEXER_H

#include <string>
#include <variant>
#include "line.h"
#include "label_range.h"
#include "token/token.h"
#include "token/label_token.h"
#include "token/operator_token.h"

using namespace std;

// TODO: Check if label is out of bounds of ARRAY_SIZE (in array.h)
// TODO: Check if label range is larger than 64 bytes
class Lexer {
private:
    Line* line;

    Value FindValue(const string& word);

    LabelRange* FindLabel(const string& label);
    LabelToken* LabelToken();

    OperatorToken* OperatorToken();

    uint64_t string_to_ull(const string &str);
    uint32_t string_to_ul(const string &str);
public:
    Lexer(int num, const string& line);

    Token* NextToken();

    Line* GetLine();

    void error(const string &err) noexcept(false);

    ~Lexer();
};

#endif
