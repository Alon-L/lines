#include "operators.h"
#include "all/all.h"

namespace Operators {
    std::optional<OpChar> find_op_name(char op_name) {
        auto op = OpChars.find(op_name);

        if (op == OpChars.end()) {
            return std::nullopt;
        } else {
            return op->second;
        }
    }

    Operator *create_op_obj(OpChar op, LabelRange* label, OpValue value) {
        switch (op) {
            case OP_ADD:
                return new OperatorAdd(label, value);
            case OP_SUBTRACT:
                return new OperatorSub(label, value);
            case OP_REPEAT:
                return new OperatorRepeat(label, value);
            case OP_PRINT:
                return new OperatorPrint(label, value);
            case OP_INPUT:
                return new OperatorInput(label, value);
            default:
                return nullptr;
        }
    }
}