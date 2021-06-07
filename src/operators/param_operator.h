#ifndef LINES_PARAM_OPERATOR_H
#define LINES_PARAM_OPERATOR_H

#include "operator.h"

class ParamOperator : public Operator {
protected:
    Value value;
public:
    ParamOperator(LabelRange* label, OpValue value);

    bool ValidateArgs() override;
};

#endif
