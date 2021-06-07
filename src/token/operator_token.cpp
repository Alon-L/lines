#include "operator_token.h"

OperatorToken::OperatorToken(OpChar op) {
    this->type = TOKEN_OPERATOR;
    this->op = op;
}

OperatorToken::OperatorToken(OpChar op, OpValue value) : OperatorToken(op) {
    this->value = value;
}
