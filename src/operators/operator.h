#ifndef LINES_OPERATOR_H
#define LINES_OPERATOR_H

#include <optional>
#include "../label_range.h"
#include "../array/array.h"
#include "../array/utils.h"

typedef std::optional<Value> OpValue;

class Operator {
protected:
    LabelRange *label;
public:
    explicit Operator(LabelRange *label);

    virtual bool ValidateArgs();

    virtual uint64_t Execute() = 0;

    virtual ~Operator() = default;
};

#endif
