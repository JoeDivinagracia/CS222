#ifndef TERM_H
#define TERM_H

typdef enum (OPERATOR, OPERAND} Type;
typedef struct{
  Type type;
  union{
    double operand;
    char operator;
  }
}Term;
#endif
