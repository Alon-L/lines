#ifndef LINES_OPERATOR_PRINT_H
#define LINES_OPERATOR_PRINT_H

#include "../operator.h"

class OperatorPrint : public Operator {
public:
    explicit OperatorPrint(LabelRange *label);

    uint64_t Execute() override;
};

#endif
