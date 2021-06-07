#ifndef LINES_OPERATOR_SUB_H
#define LINES_OPERATOR_SUB_H

#include "../param_operator.h"

class OperatorSub : public ParamOperator {
public:
    OperatorSub(LabelRange *label, OpValue value);

    uint64_t Execute() override;
};

#endif
