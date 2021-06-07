#include <algorithm>
#include <cctype>
#include "line.h"

Line *g_line;

Line::Line(int num, const string &content) {
    this->num = num;
    this->pos = 0;
    this->content = content;
    this->content_ws = content;
    this->ended = false;

    this->pos_ws = 0;
    this->RemoveWhitespaces();
}

void Line::RemoveWhitespaces() {
    content_ws.erase(
            remove_if(
                    content_ws.begin(),
                    content_ws.end(),
                    [](char c) { return isspace(static_cast<unsigned char>(c)); }
            ), content_ws.end()
    );
}

string Line::GetContent() {
    return this->content_ws;
}

int Line::IncPos() {
    pos++;
    pos_ws++;

    // Increment white-spaced position for every space
    for (; pos_ws < GetContent().length() && isspace(content[pos_ws]); ++pos_ws);

    return pos;
}

int Line::IncPos(int n) {
    for (int i = 0; i < n; ++i)
        IncPos();

    return pos;
}

void Line::SetPos(int pos) {
    this->pos = pos;
}

void Line::SetWSPos(int pos) {
    this->pos_ws = pos;
}

/* Returns the next word. A word ends whenever a new alphabetic character is found. */
string Line::NextWord() {
    // The index of the the end of the word
    size_t end = GetContent().length();

    for (int i = pos + 1; i < GetContent().length(); ++i) {
        if (isalpha(GetContent()[i]) || GetContent()[i] == ';') {
            end = i - 1;
            break;
        }
    }

    return GetContent().substr(pos, end - pos + 1);
}

char Line::CurrentChar() {
    return GetContent()[pos];
}

int Line::GetPos() const {
    return pos;
}

int Line::GetWSPos() const {
    return pos_ws;
}

int Line::GetNum() const {
    return num;
}

bool Line::GetEnded() {
    ended = ended || pos >= content_ws.length();
    return ended;
}

void Line::SetEnded(bool ended) {
    this->ended = ended;
}
