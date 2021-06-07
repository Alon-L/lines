#ifndef LINES_TOKEN_H
#define LINES_TOKEN_H

#include "../label_range.h"

enum TokenType {
    TOKEN_LABEL,
    TOKEN_OPERATOR,
};

/* TODO: Make this abstract */
class Token {
protected:
    TokenType type;
public:
    virtual TokenType GetType();

    virtual ~Token() = default;
};

#endif
