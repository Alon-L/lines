#include "operator_input.h"

OperatorInput::OperatorInput(LabelRange *label) : Operator(label) {}

uint64_t OperatorInput::Execute() {
    Utils::input_cell(this->label);

    return 0;
}
