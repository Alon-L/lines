#ifndef LINES_OPERATOR_INPUT_H
#define LINES_OPERATOR_INPUT_H

#include "../operator.h"

class OperatorInput : public Operator {
public:
    explicit OperatorInput(LabelRange *label);

    uint64_t Execute() override;
};

#endif
