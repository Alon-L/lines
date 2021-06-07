#include "operator_sub.h"

OperatorSub::OperatorSub(LabelRange *label, OpValue value) : ParamOperator(label, value) {}

uint64_t OperatorSub::Execute() {
    uint64_t num = Utils::get_value(this->value);

    Utils::sub_cell(this->label, num);

    return 0;
}
