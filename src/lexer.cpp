#include <iostream>
#include "lexer.h"

Lexer::Lexer(int num, const string &line) {
    this->line = new Line(num, line);
}

/* Returns the next token. Either label or operator */
Token *Lexer::NextToken() {
    if (isdigit(line->CurrentChar())) {
        // The token is a label
        return this->FindLabelToken();
    } else {
        // The token is an operator
        return this->FindOperatorToken();
    }
}

/* Finds the value behind a word */
Value Lexer::FindValue(const string &word) {
    if (word.find(',') < word.length()) {
        /* The value is a label */
        return this->FindLabelRange(word);
    } else {
        /* The value is a number */
        return string_to_ull(word);
    }
}

/* Finds the label range for a given label string. */
LabelRange *Lexer::FindLabelRange(const string &label) {
    auto comma = label.find(',');

    if (comma == std::string::npos) {
        // A comma is present in the label
        uint32_t start_i = string_to_ul(label);
        return new LabelRange(start_i);
    } else {
        // A comma is not present in the label
        string start = label.substr(0, comma);
        string end = label.substr(comma + 1);

        uint32_t start_i = string_to_ul(start);
        line->IncPos();
        uint32_t end_i = string_to_ul(end);

        return new LabelRange(start_i, end_i);
    }
}

/* Returns the label token for the next word. */
LabelToken *Lexer::FindLabelToken() {
    string word = line->NextWord();
    LabelRange *range = this->FindLabelRange(word);

    return new class LabelToken(range);
}

/* Returns the operator token for the next word. */
OperatorToken *Lexer::FindOperatorToken() {
    string word = line->NextWord();
    char op_name = word[0];
    string op_value = word.substr(1);

    std::optional<OpChar> op_opt = Operators::find_op_name(op_name);
    if (!op_opt.has_value()) {
        error("'" + std::string(1, op_name) + "' is not a valid operator!");
    }
    auto op = op_opt.value();

    // The remark operator should stop further line interpretation
    if (op == OP_REMARK) {
        line->SetEnded(true);
        return new class OperatorToken(op);
    }

    line->IncPos();

    if (op_value.length()) {
        // An operator value is found
        return new class OperatorToken(op, this->FindValue(op_value));
    } else {
        return new class OperatorToken(op);
    }
}

void Lexer::error(const string &err) noexcept(false) {
    string full_err = "(" + to_string(line->GetNum()) + ":" + to_string(line->GetWSPos() + 1) + ") " + err;
    cout << full_err << endl;
    throw full_err;
}

uint64_t Lexer::string_to_ull(const string &str) {
    try {
        uint64_t num = stoull(str);
        // Increment the current position of the line
        line->IncPos(str.length());
        return num;
    } catch (std::invalid_argument &err) {
        error("'" + str + "' is not a number!");
    } catch (std::out_of_range &err) {
        error("'" + str + "' is out of bounds! It must be an unsigned long long!");
    }
    return 0;
}

uint32_t Lexer::string_to_ul(const string &str) {
    try {
        uint32_t num = stoul(str);
        // Increment the current position of the line
        line->IncPos(str.length());
        return num;
    } catch (std::invalid_argument &err) {
        error("'" + str + "' is not a number!");
    } catch (std::out_of_range &err) {
        error("'" + str + "' is out of bounds! It must be an unsigned long!");
    }
    return 0;
}

Lexer::~Lexer() {
    delete line;
}

Line *Lexer::GetLine() {
    return line;
}

