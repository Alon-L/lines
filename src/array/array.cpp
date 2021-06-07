#include "array.h"

Array g_arr = {};

void create_array() {
    // Reset the array
    for (unsigned char & i : g_arr) {
        i = 0;
    }
}
