#include "lib.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

int precedence(char op) {
	if (op == '(' || op == ')') {
		return 1;
	} else if (op == '+' || op == '-') {
		return 2;
	} else if (op == '*' || op == '/') {
		return 3;
	} else if (op == '%') {
		return 4;
    	} else if (op == '^') {
		return 5;
    	} else {
		return 0;
    	}
}

float perform_operation(float subject1, float subject2, char op) {
	switch (op) {
		case '+':
	    		return subject1 + subject2;
		case '-':
	    		return subject1 - subject2;
		case '*':
	    		return subject1 * subject2;
		case '/':
	    		if (subject2 == 0) {
				printf("Помилка: Ділення на ноль\n");
				exit(0);
			}
	    		return subject1 / subject2;
		case '%':
	    		return (int)subject1 % (int)subject2;
		case '^':
	    		return pow(subject1, subject2);
		exit(0);
	}
}

float evaluate_expression(char * expression) {
	    float subjects[100];
	    char operators[100];
	    int num_subjects = 0;
	    int num_operators = 0;
	    int i = 0;
	
	    while (expression[i] != '\0') {
	    	    if (expression[i] == ' ') {
			    i++;
			    continue;
	    	    }

/*	    	    if (expression[i] >= '0' && expression[i] <= '9') {
			    char *ptr;
			    float value = strtof(&expression[i], &ptr);
			    subjects[num_subjects++] = value;
			    i = ptr - expression;*/
		    if (expression[i] == '-') {
			    i++;
			    char *ptr;
			    float value = -strtof(&expression[i], &ptr);
			    subjects[num_subjects++] = value;
			    i = ptr - expression;
		    } else if (expression[i] >= '0' && expression[i] <= '9') {
			    char *ptr;
			    float value = strtof(&expression[i], &ptr);
			    subjects[num_subjects++] = value;
			    i = ptr - expression;
	    	    } else if (expression[i] == '(') {
		       	    operators[num_operators++] = expression[i];
			    i++;
	    	    } else if (expression[i] == ')') {
			    while (num_operators > 0 && operators[num_operators - 1] != '(') {
		    		    float subject2 = subjects[--num_subjects];
		    		    float subject1 = subjects[--num_subjects];
		    		    char op = operators[--num_operators];
		    		    float result = perform_operation(subject1, subject2, op);
		    		    subjects[num_subjects++] = result;
			    }

			    if (num_operators == 0) {
		    		    printf("Невірний вираз: Закрийте скобку\n");
		    		    exit(0);
			    }
		
			    num_operators--;
			    i++;
	    	    } else {
			    while (num_operators > 0 && precedence(operators[num_operators - 1]) >= precedence(expression[i])) {
		    		    float subject2 = subjects[--num_subjects];
		    		    float subject1 = subjects[--num_subjects];
		    		    char op = operators[--num_operators];
		    		    float result = perform_operation(subject1, subject2, op);
		    		    subjects[num_subjects++] = result;
			    }

			    operators[num_operators++] = expression[i];
			    i++;
	    	    }
	    }

	    while (num_operators > 0) {
		    if (operators[num_operators - 1] == '(') {
			    printf("Невірний вираз: Закрийте скобку\n");
			    exit(0);
		    }
		    float subject2 = subjects[--num_subjects];
		    float subject1 = subjects[--num_subjects];
		    char op = operators[--num_operators];
		    float result = perform_operation(subject1, subject2, op);
		    subjects[num_subjects++] = result;
	    }

	    if (num_subjects != 1) {
		    printf("Невірний вираз: Об'єктів больше, ніж операторів\n");
		    exit(0);
	    }

	    return subjects[0];
}
