#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#define SLIDE_LEFT 99
#define SLIDE_RIGHT 66
#include <stddef.h>

int slide_line(int *line, size_t size, int direction);
void shift_ints_left(int *line, size_t size);
void shift_ints_right(int *line, size_t size);

#endif /* SLIDE_LINE_H */
