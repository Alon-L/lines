#ifndef LINES_LABEL_TOKEN_H
#define LINES_LABEL_TOKEN_H

#include "token.h"
#include "../label_range.h"

class LabelToken : public Token {
private:
    LabelRange* value;
public:
    explicit LabelToken(LabelRange* range);

    [[nodiscard]] LabelRange* GetValue() const;

    ~LabelToken() override;
};

#endif
