#ifndef LINES_OPERATOR_TOKEN_H
#define LINES_OPERATOR_TOKEN_H

#include <optional>
#include "token.h"
#include "../operators/operators.h"

class OperatorToken : public Token {
public:
    OpChar op;
    OpValue value;

public:
    explicit OperatorToken(OpChar op);
    OperatorToken(OpChar op, OpValue value);
};

#endif
