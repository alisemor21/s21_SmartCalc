#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_
#include <math.h>

#include "conditions.h"
#include "input_parse.h"
#include "pn.h"
#include "stack.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HIGHT 25
#define WIDTH 80
#define MIN_X 0
#define MAX_X 4.0 * M_PI
#define MIN_Y -1
#define MAX_Y 1

double *mainpn(const char *const_string, int XMIN, int XMAX);
void init_screen(char **screen);
double *fill_screen(char *func, int XMIN, int XMAX, double *val);
double calculate(char *expr, double x);
void draw_graph(char **screen);

#ifdef __cplusplus
}
#endif

#endif  // SRC_GRAPH_H_
