#include "operator_print.h"

OperatorPrint::OperatorPrint(LabelRange* label, OpValue value) : Operator(label, value) {}

uint64_t OperatorPrint::Execute() {
    Utils::print_cell(this->label);

    return 0;
}
