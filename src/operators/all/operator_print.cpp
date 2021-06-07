#include "operator_print.h"

OperatorPrint::OperatorPrint(LabelRange *label) : Operator(label) {}

uint64_t OperatorPrint::Execute() {
    Utils::print_cell(this->label);

    return 0;
}
