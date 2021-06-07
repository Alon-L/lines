#include "utils.h"
#include <variant>
#include <iostream>

namespace Utils {
    /* Modifies the cells at a given range to a given value */
    void modify_cells(LabelRange *range, Value value) {
        if (uint64_t *num = std::get_if<uint64_t>(&value)) {
            // The value is a number
            return modify_cells(range, *num);
        } else if (LabelRange **label = std::get_if<LabelRange *>(&value)) {
            // The value is a label range
            return modify_cells(range, get_cells_value(*label));
        } else {
            throw "Failed to retrieve the type of 'value'";
        }
    }

    /* Modifies the cells at a given range to a given number value */
    void modify_cells(LabelRange *range, uint64_t value) {
        for (int i = 0; i < range->GetSteps(); ++i) {
            unsigned cell = (range->GetSteps() - i - 1) + range->GetStart();
            ArrayItem item = value;

            value >>= CELL_SIZE;

            g_arr[cell] = item;
        }
    }

    /* Adds a numeric value to a cell */
    void add_cell(LabelRange *range, uint64_t value) {
        uint64_t sum = get_cells_value(range) + value;
        modify_cells(range, sum);
    }

    /* Subtracts a numeric value from a cell */
    void sub_cell(LabelRange *range, uint64_t value) {
        uint64_t sub = get_cells_value(range) - value;
        modify_cells(range, sub);
    }

    /* Prints the value of a given cell */
    void print_cell(LabelRange *range) {
        uint64_t value = get_cells_value(range);
        std::cout << value << std::endl;
    }

    /* Inputs a value and inserts it into a given cell */
    void input_cell(LabelRange *range) {
        uint64_t value;
        std::cin >> value;
        modify_cells(range, value);
    }

    /* Returns the numeric value behind a 'Value' type */
    uint64_t get_value(Value value) {
        if (uint64_t *num = std::get_if<uint64_t>(&value)) {
            // The value is a number
            return *num;
        } else if (LabelRange **range = std::get_if<LabelRange *>(&value)) {
            // The value is a label range
            return get_cells_value(*range);
        } else {
            throw "Failed to retrieve the type of 'value'";
        }
    }

    /* Retrieves the number behind the cells at a given range */
    uint64_t get_cells_value(LabelRange *range) {
        uint64_t val = 0;

        for (int i = 0; i < range->GetSteps(); ++i) {
            unsigned cell = (range->GetSteps() - i - 1) + range->GetStart();

            val |= g_arr[cell] << (i * CELL_SIZE);
        }

        return val;
    }
}