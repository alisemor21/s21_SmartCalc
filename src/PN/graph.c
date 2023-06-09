#include "graph.h"

// int main() {
//   char *string = "8/0";
//   double *val = mainpn(string, -2, 1);
//   free(val);
//   return 0;
// }

double *mainpn(const char *const_string, int XMIN, int XMAX) {
  double *val = calloc(abs(XMAX - XMIN) * 10 + 2, sizeof(double));
  char *string = (char *)const_string;
  expr *expr_in = read_expr(string);
  if (expr_in != NULL) {
    convert_to_pn(expr_in->f_in, expr_in->pn);
    if (is_correct_expression(expr_in->pn))
      fill_screen(expr_in->pn, XMIN, XMAX, val);
    else
      printf("n/a");
    free(expr_in->in_str);
    free(expr_in);
  }
  return (double *)val;
}

double *fill_screen(char *func, int XMIN, int XMAX, double *val) {
  double h = 0.1;

  int k = 0;

  for (double x = XMIN; x < XMAX + h; x += h) {
    double y = calculate(func, x);

    printf("X = %f Y = %lf\n", x, y);
    val[k] = y;
    k++;
  }

  return val;
}

double calculate(char *expr, double x) {
  st_calc *pn = NULL;
  double out = 0;
  int i = 0;
  // int j = 0;
  while (expr[i] != '\0') {
    if (is_number(expr[i])) {
      int k = 1;
      double num = 0;
      while (is_number(expr[i + k])) k++;
      char *string = calloc(k, sizeof(char));
      for (int j = 0; j < k; j++) {
        string[j] = expr[i++];
      }
      num = atof(string);
      pn = push_calc(pn, num);
      free(string);
    } else if ((expr[i]) == 'x') {
      pn = push_calc(pn, x);
    } else if (is_math_symbol(expr[i])) {
      pn = operation(expr[i], pn);
    } else if (is_math_func(expr[i])) {
      pn = function(expr[i], pn);
    }
    i++;
  }
  if (pn != NULL) out = (pn->digit);
  pop_calc(&pn);
  return out;
}
