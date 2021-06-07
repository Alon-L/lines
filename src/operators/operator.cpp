#include "operator.h"

bool Operator::ValidateArgs() {
    return true;
}

Operator::Operator(LabelRange* label) {
    this->label = label;
}
