#include "operator.h"

bool Operator::ValidateArgs() {
    return !_value.has_value();
}

Operator::Operator(LabelRange* label, OpValue value) {
    this->label = label;
    this->_value = value;
}
