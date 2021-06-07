cmake_minimum_required(VERSION 3.19)
project(lines)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        lines
        src/main.cpp
        src/lexer.cpp
        src/interpreter.cpp
        src/label_range.cpp
        src/line.cpp

        src/array/array.cpp
        src/array/utils.cpp

        src/token/token.cpp
        src/token/label_token.cpp
        src/token/operator_token.cpp

        src/operators/operators.cpp
        src/operators/operator.cpp
        src/operators/param_operator.cpp

        src/operators/all/operator_add.cpp
        src/operators/all/operator_sub.cpp
        src/operators/all/operator_repeat.cpp
        src/operators/all/operator_print.cpp
        src/operators/all/operator_input.cpp
)
