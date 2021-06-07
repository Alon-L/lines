#ifndef LINES_OPERATOR_REPEAT_H
#define LINES_OPERATOR_REPEAT_H

#include "../param_operator.h"

class OperatorRepeat : public ParamOperator {
public:
    OperatorRepeat(LabelRange *label, OpValue value);

    uint64_t Execute() override;
};

#endif
