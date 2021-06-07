#ifndef LINES_ARRAY_H
#define LINES_ARRAY_H

typedef unsigned char ArrayItem;

#define ARRAY_SIZE 4096
#define CELL_SIZE (sizeof(ArrayItem) * 8)
#define MAX_NUM 0b11111111
#define MAX_CELLS_SIZE (64 / CELL_SIZE)

typedef ArrayItem Array[ARRAY_SIZE];
extern Array g_arr;

extern void create_array();

#endif
