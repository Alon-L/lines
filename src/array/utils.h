#ifndef LINES_UTILS_H
#define LINES_UTILS_H

#include <cstdint>
#include "array.h"
#include "../label_range.h"

namespace Utils {
    void modify_cells(LabelRange *range, Value value);

    void modify_cells(LabelRange *range, uint64_t value);

    void add_cell(LabelRange *range, uint64_t value);

    void sub_cell(LabelRange *range, uint64_t value);

    void print_cell(LabelRange *range);

    void input_cell(LabelRange *range);

    uint64_t get_value(Value value);

    uint64_t get_cells_value(LabelRange *range);
}

#endif
