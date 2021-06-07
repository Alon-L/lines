#ifndef LINES_OPERATOR_INPUT_H
#define LINES_OPERATOR_INPUT_H

#include "../operator.h"

class OperatorInput : public Operator {
public:
    OperatorInput(LabelRange *label, OpValue value);

    uint64_t Execute() override;
};

#endif
