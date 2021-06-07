#include "operator_repeat.h"

OperatorRepeat::OperatorRepeat(LabelRange *label, OpValue value) : ParamOperator(label, value) {}

uint64_t OperatorRepeat::Execute() {
    return Utils::get_value(this->value);
}
