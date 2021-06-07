#ifndef LINES_LABEL_RANGE_H
#define LINES_LABEL_RANGE_H

#include <variant>
#include <cstdint>

class LabelRange {
private:
    uint32_t start;
    uint32_t steps;
public:
    explicit LabelRange(uint32_t start);
    LabelRange(uint32_t start, uint32_t steps);
    explicit LabelRange(LabelRange* range);

    [[nodiscard]] uint32_t GetStart() const;
    [[nodiscard]] uint32_t GetSteps() const;
};

typedef std::variant<uint64_t, LabelRange*> Value;

#endif
