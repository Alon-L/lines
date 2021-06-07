#ifndef LINES_LINE_H
#define LINES_LINE_H

#include <string>

using namespace std;

class Line {
private:
    int num;
    int pos;
    string content;

    int pos_ws;
    string content_ws;

    bool ended;

    void RemoveWhitespaces();
public:
    Line(int num, const string &content);

    string GetContent();

    int IncPos();
    int IncPos(int n);

    void SetPos(int pos);
    void SetWSPos(int pos);

    [[nodiscard]] int GetPos() const;
    [[nodiscard]] int GetWSPos() const;
    [[nodiscard]] int GetNum() const;
    bool GetEnded();
    void SetEnded(bool ended);

    string NextWord();

    char CurrentChar();
};

#endif
