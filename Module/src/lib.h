#ifndef __LIB_H__
#define __LIB_H__
#include <stdlib.h>
#include <stdio.h>

//Определяет скобки та знаки
int precedence(char op);

//Виконує одну операцію
float perform_operation(float subject1, float subject2, char op);

//Виконує операції у правильній послідовності
float evaluate_expression(char * expression);

#endif
