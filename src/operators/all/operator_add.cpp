#include "operator_add.h"

OperatorAdd::OperatorAdd(LabelRange *label, OpValue value) : ParamOperator(label, value) {}

uint64_t OperatorAdd::Execute() {
    uint64_t num = Utils::get_value(this->value);

    Utils::add_cell(this->label, num);

    return 0;
}
