#include "lib.h"
#include <string.h>
// Розробити програму, що в заданому файлі створює суцільний рівнобедрений трикутник із заданих символів (наприклад, зірочок). Висота трикутника, символ заповнювача та ширина основи задається у вхідному файлу.

int main() {
	char expression[100];

    	printf("Введіть вираз: ");
    	fgets(expression, 100, stdin);
	if (expression[strlen(expression)-1] == '\n') {
		expression[strlen(expression)-1] = '\0';
}

    	float result = evaluate_expression(expression);

    	printf("Результат: %lf\n", result);

    	return 0;
}
