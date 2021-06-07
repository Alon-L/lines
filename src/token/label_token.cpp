#include "label_token.h"

LabelToken::LabelToken(LabelRange *range) {
    this->type = TOKEN_LABEL;
    this->value = range;
}

LabelToken::~LabelToken() {
    delete this->value;
}

LabelRange *LabelToken::GetValue() const {
    return value;
}
