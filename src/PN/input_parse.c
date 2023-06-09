#include "input_parse.h"

expr *read_expr(char *string) {
  int size_str = MAX_STR_SIZE;
  expr *expr = create_new_expr(size_str);
  if (expr != NULL) {
    read_symbol(expr, &size_str, string);
    func_names_to_abbrev(expr);
    end_read_expr(expr);
    write_expr_to_f_in(expr);
  }
  return expr;
}

expr *create_new_expr(int size_str) {
  expr *s = (expr *)malloc(sizeof(expr));
  s->len = 0;
  s->in_str = (char *)malloc((size_str + 1) * sizeof(char));
  s->in_str[size_str] = '\0';
  return s;
}

char read_symbol(expr *s, int *size_str, char *string) {
  char c;
  // char * string = "l";
  int len = (int)strlen(string);
  for (int i = 0; i < len; i++) {
    if (sscanf(string, "%c", &c) != 1) {
      free(s);
    } else {
      string++;
      if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' ||
          c == ')' || c == 'x' || c == 'X' || c == 's' || c == 'i' ||
          c == 'n' || c == 'c' || c == 'o' || c == 't' || c == 'a' ||
          c == '^' || c == '%' || c == 'g' || c == 'q' || c == 'r' ||
          c == 'l') {
        if (c == '-' &&
            (s->in_str[(s->len) - 1] == '(' ||
             is_math_symbol(s->in_str[(s->len) - 1]) || s->len == 0))
          c = '~';
        if (s->len == *size_str) {
          printf("realoc");
          *size_str = s->len + MAX_STR_SIZE;
          char *a = (char *)realloc(s->in_str, *size_str);
          s->in_str = a;
        }
      }
      // printf("size str = %d", s->len);
      (s->in_str[s->len]) = c;
      s->len++;
    }
  }
  return c;
}

void end_read_expr(expr *s) {
  int i = 0, size_in_str = s->len, size_f_in = s->len, size_pn = 0;
  s->in_str[size_in_str] = '\0';
  while (s->in_str[i] != '\0') {
    if (is_number(s->in_str[i])) {
      while (is_number(s->in_str[i + 1])) {
        size_pn++;
        i++;
      }
    }
    size_pn += 2;
    i++;
  }

  char *a = (char *)realloc(s->in_str, size_in_str + size_f_in + size_pn);
  if (a == NULL) {
    free(s);
    s = NULL;
  } else {
    s->in_str = a;
    s->in_str[size_in_str] = '\0';
    s->f_in = s->in_str + size_in_str + 1;
    s->f_in[size_f_in] = '\0';
    s->pn = (char *)malloc(sizeof(char) * (size_pn + 1));
    s->pn[0] = *(s->f_in + size_f_in + 1);
    s->pn[1] = '\0';
  }
}

void func_names_to_abbrev(expr *expr) {
  char func_names[ROWS][COLS] = {"asin", "acos", "atan", "sin", "cos",
                                 "ctg",  "tan",  "sqrt", "ln",  "log"};
  char func_abbrev[COLS] = {'u', 'v', 'h', 'p', 'b', 'z', 'd', 'e', 'f', 'w'};
  int len_func_names[COLS] = {4, 4, 4, 3, 3, 3, 3, 4, 2, 3};
  find_replace(expr, func_names, func_abbrev, len_func_names);
}

void find_replace(expr *expr, char names[][COLS], const char *abbrev,
                  const int *len) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    char *ip = expr->in_str;
    while (ip != NULL) {
      // printf("%s ->", expr->in_str);
      // printf("%s \n", names[i]);
      ip = strstr(expr->in_str, names[i]);
      if (ip != NULL) {
        *(ip) = abbrev[i];
        for (j = 1; j < len[i]; j++) {
          ip[j] = ' ';
        }
      }
    }
  }
}

void write_expr_to_f_in(expr *expr) {
  int i = 0, j = 0;
  while (expr->in_str[i] != '\0') {
    if (expr->in_str[i] != ' ') {
      expr->f_in[j] = expr->in_str[i];
      j++;
    }
    i++;
  }
  expr->f_in[j] = '\0';
}
