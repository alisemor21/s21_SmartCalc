#ifndef SRC_INPUT_PARSE_H_
#define SRC_INPUT_PARSE_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conditions.h"

typedef struct expr {
  int len;
  char *in_str;
  char *f_in;
  char *pn;
} expr;

#define MAX_STR_SIZE 100
#define ROWS 10
#define COLS 10

expr *read_expr();
expr *create_new_expr(int size_str);
char read_symbol(expr *s, int *size_str, char *string);
void func_names_to_abbrev(expr *expr);
void end_read_expr(expr *s);
void write_expr_to_f_in(expr *expr);
void find_replace(expr *expr, char names[][COLS], const char *abbrev,
                  const int *len);
#endif  // SRC_INPUT_PARSE_H_
