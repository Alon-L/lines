#include "interpreter.h"

Interpreter::Interpreter(Lexer *lexer) {
    this->lexer = lexer;
    this->line = lexer->GetLine();
    this->label = nullptr;
}

void Interpreter::Error(const string &err) noexcept(false) {
    lexer->error(err);
}

void Interpreter::Interpret() {
    while (!line->GetEnded()) {
        Token *token = lexer->NextToken();

        if (token->GetType() == TOKEN_LABEL) {
            // Label token
            auto t = dynamic_cast<LabelToken *>(token);

            this->InterpretLabel(t);
        } else if (token->GetType() == TOKEN_OPERATOR) {
            // Operator token
            auto t = dynamic_cast<OperatorToken *>(token);

            this->InterpretOperator(t);
        }

        delete token;
    }
}

void Interpreter::InterpretLabel(LabelToken *token) {
    if (label != nullptr) {
        this->Error("Two labels were supplied");
    }

    // Copy the label from the token
    label = new LabelRange(token->GetValue());
}

void Interpreter::InterpretOperator(OperatorToken *token) {
    // Checks for a remark operator
    if (token->op == OP_REMARK) return;

    // Verify a label was in place
    if (label == nullptr) {
        this->Error("A label was not supplied");
    }

    // Create an operator object based on the
    Operator *op = Operators::create_op_obj(token->op, label, token->value);

    // Validate that the argument is present (if required)
    if (!op->ValidateArgs()) {
        this->Error("An incorrect number of arguments were presented");
    }

    uint64_t ret = op->Execute();

    // Check if the operator is a 'repeat' operator. If so, repeat the next tokens.
    if (token->op == OP_REPEAT) {
        this->InterpretRepeat(ret);
    }

    delete op;
}

/* Repeats the next tokens 'num' times */
void Interpreter::InterpretRepeat(uint64_t num) {
    if (line->GetEnded()) {
        this->Error("No operators were present after the repeat operator");
    }

    int pos_ws = line->GetWSPos();
    int pos = line->GetPos();

    for (uint64_t i = 0; i < num - 1; ++i) {
        this->Interpret();

        line->SetEnded(false);
        line->SetWSPos(pos_ws);
        line->SetPos(pos);
    }
}

Interpreter::~Interpreter() {
    delete this->label;
}
