#ifndef LINES_OPERATORS_H
#define LINES_OPERATORS_H

#include <map>
#include <optional>
#include "operator.h"
#include "../label_range.h"

typedef std::optional<Value> OpValue;

enum OpChar {
    OP_REMARK,
    OP_ADD,
    OP_SUBTRACT,
    OP_REPEAT,
    OP_PRINT,
    OP_INPUT,
};

namespace Operators {
    const std::map<char, OpChar> OpChars = {
            {';', OP_REMARK},
            {'a', OP_ADD},
            {'s', OP_SUBTRACT},
            {'r', OP_REPEAT},
            {'p', OP_PRINT},
            {'i', OP_INPUT},
    };

    std::optional<OpChar> find_op_name(char op_name);

    Operator *create_op_obj(OpChar op, LabelRange *label, OpValue value);
}

#endif
