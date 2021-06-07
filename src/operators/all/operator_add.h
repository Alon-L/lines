#ifndef LINES_OPERATOR_ADD_H
#define LINES_OPERATOR_ADD_H

#include "../param_operator.h"

class OperatorAdd : public ParamOperator {
public:
    OperatorAdd(LabelRange *label, OpValue value);

    uint64_t Execute() override;
};

#endif
