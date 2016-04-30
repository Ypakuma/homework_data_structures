#ifndef YANGHUI_TRIANGLE_H
#define YANGHUI_TRIANGLE_H

#include "linked_queue\linked_queue.h"

/********************************
* aim:       print Yang Hui's Triangle(Pascal's Triangle).
* parameter: void.
* return:    void.
********************************/
void yanghui_triangle(void);

/********************************
* aim:       get how many line(s) Yang Hui's Triangle(Pascal's Triangle) has.
* parameter: void.
* return:    the number of line(s).
********************************/
int getlines(void);

/********************************
* aim:       print Yang Hui's Triangle(Pascal's Triangle) which was storaged by queue.
* parameter: the number of line(s).
* return:    void.
********************************/
void print_angle(int num_lines);


#endif

