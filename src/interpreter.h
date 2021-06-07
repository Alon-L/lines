#ifndef LINES_INTERPRETER_H
#define LINES_INTERPRETER_H

#include <stack>
#include "lexer.h"
#include "operators/all/operator_repeat.h"

class Interpreter {
private:
    Lexer* lexer;
    Line* line;
    LabelRange* label;
public:
    /*
     * TODO: Repeat operator: push repeat value into stack
     * TODO: When reading tokens and finding a 'repeat' operator, pop the repeat value from the stack, and iterate the next tokens for that value
     */
    stack<int> repeats;

    explicit Interpreter(Lexer* lexer);

    void Interpret();
    void InterpretLabel(LabelToken *token);
    void InterpretOperator(OperatorToken *token);
    void InterpretRepeat(uint64_t num);

    void Error(const string &err) noexcept(false);

    ~Interpreter();
};

#endif
