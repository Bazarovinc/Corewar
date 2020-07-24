#ifndef FT_DROW_H
# define FT_DROW_H
#include <curses.h>
#include "vm.h"

#define COLOR_GREY	8
#define p0		1
#define p1              2
#define p2              3
#define p3              4
#define p4              5
#define p0w             6
#define p1w             7
#define p2w             8
#define p3w             9
#define p4w             10
#define p0b             11
#define p1b             12
#define p2b             13
#define p3b             14
#define p4b             15

void init_colors();
void init_drow();
void color_select(int is_curs, int playerno);
void ft_start_color(t_vm *vm, int pose);
void stop_color();
void draw_frame();
void drow_arena(t_vm *vm);
void stop_drow();
#endif
