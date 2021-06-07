#include "label_range.h"

LabelRange::LabelRange(uint32_t start) {
    this->start = start;
    this->steps = 1;
}

LabelRange::LabelRange(uint32_t start, uint32_t steps) {
    this->start = start;
    this->steps = steps;
}

LabelRange::LabelRange(LabelRange *range) {
    this->start = range->GetStart();
    this->steps = range->GetSteps();
}

uint32_t LabelRange::GetStart() const {
    return this->start;
}

uint32_t LabelRange::GetSteps() const {
    return this->steps;
}
