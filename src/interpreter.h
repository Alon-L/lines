#ifndef LINES_INTERPRETER_H
#define LINES_INTERPRETER_H

#include "lexer.h"
#include "operators/all/operator_repeat.h"

class Interpreter {
private:
    Lexer* lexer;
    Line* line;
    LabelRange* label;
public:
    explicit Interpreter(Lexer* lexer);

    void Interpret();
    void InterpretLabel(LabelToken *token);
    void InterpretOperator(OperatorToken *token);
    void InterpretRepeat(uint64_t num);

    void Error(const string &err) noexcept(false);

    ~Interpreter();
};

#endif
