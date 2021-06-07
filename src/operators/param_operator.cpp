#include "param_operator.h"

bool ParamOperator::ValidateArgs() {
    return _value.has_value();
}

ParamOperator::ParamOperator(LabelRange *label, OpValue value) : Operator(label, value) {
    if (_value.has_value()) {
        this->value = _value.value();
    }
}
