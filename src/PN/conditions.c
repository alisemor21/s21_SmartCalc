#include "conditions.h"

#include <stdio.h>

int math_symbol_prior(char a) {
  int res = 10;
  switch (a) {
    case '(':
      res = 1;
      break;
    case ')':
      res = 1;
      break;
    case '+':
      res = 2;
      break;
    case '-':
      res = 2;
      break;
    case '*':
      res = 3;
      break;
    case '/':
      res = 3;
      break;
    case '~':
      res = 4;
      break;
    case '^':
      res = 4;
      break;
    case '%':
      res = 4;
      break;
  }
  if (is_math_func(a)) res = 4;
  return res;
}

int is_math_func(char c) {
  int flag = 0;
  //  sin      cos         ctg         tan         sqrt        ln        log
  //  asin        acos         atan
  if (c == '~' || c == 'p' || c == 'b' || c == 'z' || c == 'd' || c == 'e' ||
      c == 'f' || c == 'w' || c == 'u' || c == 'v' || c == 'h') {
    flag = 1;
  }
  return flag;
}

int is_math_symbol(char c) {
  int flag = 0;
  if (c == '*' || c == '-' || c == '+' || c == '/' || c == '^' || c == '%') {
    flag = 1;
  }
  return flag;
}

int is_number(char c) {
  int flag = 0;
  if ((c >= '0' && c <= '9') || c == '.') {
    flag = 1;
  }
  return flag;
}

void add_number(char symbol, char next_symbol, char* out, int* count_out) {
  out[*count_out] = symbol;
  (*count_out)++;
  if (!is_number(next_symbol)) {
    out[*count_out] = ' ';
    (*count_out)++;
  }
}

int is_correct_expression(char* expr) {
  int i = 0, counter_math_symb = 0, counter_digits = 0, counter_func = 0,
      func = 0, res = 0;
  while (expr[i] != '\0') {
    if (expr[i] != '~' && is_math_func(expr[i])) {
      func++;
      counter_func++;
      // printf("wwwwwwwwwww\n");

    } else if (is_number(expr[i]) || expr[i] == 'x') {
      while (is_number(expr[i + 1])) {
        i++;
      }
      counter_digits++;

    } else if (is_math_symbol(expr[i])) {
      counter_math_symb++;
    }
    i++;
  }
  // if (counter_func == 1 && counter_digits == 1) {
  //     res = (counter_math_symb == 0);
  //     printf("@@@@@@@@@@@@@@@@\n");
  // } else if (func == 0 || (func > 1 && counter_func == counter_digits)) {
  //     res = (counter_digits == counter_math_symb + 1);
  //     printf("<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>\n");
  // } else if (counter_digits > 1 && counter_digits > counter_func) {
  //     res = (counter_digits == counter_math_symb + 1);
  //     printf("+++++++++++++++++++\n");
  // }
  if (counter_func == 1 && counter_digits == 1) {
    res = (counter_math_symb == 0);
    // printf("@@@@@@@@@@@@@@@@\n");
  } else if (counter_digits == 1) {
    res = 1;
    // printf("~~~~~~~~~~~~~~~~~`\n");
  } else if (counter_digits > 1 && counter_digits > counter_func) {
    res = (counter_digits == counter_math_symb + 1);
    // printf("+++++++++++++++++++\n");
  } else if (func != 0) {
    res = (counter_digits == counter_math_symb + 1);
    // printf("<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>\n");
  }

  return res;
}
