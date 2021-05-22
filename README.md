# Lines
A simple language based on a one-dimensional 16-bit unsigned integer array.  
The language takes inspiration from the [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) language, although it differs in a few major ways.

Lines is capable of modifying cells in the array using simple yet powerful core [operators](#operators).

# Syntax
Each line begins with a [label](#labels). After which can exist a set of [operators](#operators) referring to the line label.  
The language could be written using no spaces at all, although line breaks are needed to distinguish between different lines.

## Operators

### Remark `;`
Ignores the content coming after the symbol.
```
; Ignore me
```

### Add `aX`
Adds `X` to the current cell.
```
1 a3
; [0, 3, 0, ..., 0]
```

### Subtract `sX`
Subtracts `X` from the current cell, numbers are signed.
```
1 a3
1 s1
; [0, 2, 0, ..., 0]
```

### Repeat `rX`
Repeats the upcoming operators after the repeat statement `X` times.
If no operator is present after the repeat statement, an error wil be shown. 
```
; Equivalent to writing 'a1' 3 times, or 'a3'.
1 r3 a1
; [0, 3, 0, ..., 0]
```

### Print `p`
Prints the current cell.
```
; Prints '1' on the screen.
1 a1
1 p
```

### Input `i`
Takes input into the current cell. Pads the input with `0`s if needed.
```
; Inserts the input into the '1' cell.
1 i
; Prints the input on the screen.
1 p
```

### Range `X,Y`
Takes the content of the `X` cell, and the next `Y` cells, including the `X` cell.
```
; Equivalent to adding '1 + 2 + 3' to the '4' cell.
0 a1
1 a2
2 a3
4 a0,3
```

## Labels
Every line begins with a line label. The labels are sorted into 2 groups.

### Standard Labels
The label corresponds to the cell index the line refers to.
```
1 a1
; [0, 1, 0, ..., 0]
```

### Ranged Labels
Labels can be ranged, following the format of [X,Y](#range-xy).
Operators running inside ranged-labeled lines, would refer to the combination of the labeled cells, instead of the current cell. 
```
0,2 a2
; [0, 2, 0, ..., 0]
```
```
0,2 a511
; Decimal representation:
; [1, 255, 0, ..., 0]
; Binary representation:
; [00000001, 11111111, 0, ..., 0]
```

# Examples

### Calculator
Our calculator should be able to sum, and multiply two 32-bit unsigned integers.

First, the calculator should input two 32-bit unsigned integers, by using the `input` operator.
```
0,4 i
4,4 i
```

Summing two 32-bit unsigned integers, results in a 33-bit integer.
We wil continue by summing these two numbers into the `8-12` cells.
```
8,4 a0,4 a4,4
```

Let's print the sum, by using the `print` operator.
```
8,4 p
```

Multiplying two 32-bit unsigned integers, results in a 64-bit integer.
We can continue by multiplying the two numbers into the `13-20` cells.
Multiplication is a set of sums, thus it's easy to implement, using the `add` and `repeat` operators.
In order to multiply `X` and `Y`, we would have to add `X` to itself `Y` times. Let's write that.
```
13,8 r4,4 a0,4
```

Let's print the multiplication, by using the `print` operator.
```
13,8 p
```

To sum up, this is the final calculator code.
```
; Input two 32-bit numbers
0,4 i
4,4 i
; Sum the two numbers
8,4 a0,4 a4,4
; Print the sum
8,4 p
; Multiply the two numbers
13,8 r4,4 a0,4
; Print the multiplication
13,8 p
```

