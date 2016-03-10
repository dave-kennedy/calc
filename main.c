#include <stdio.h>

#include "calc.h"

int main()
{
	char input[MAX_INPUT];
	char op;
	float num1, num2, result = 0.0;

	while (fgets(input, MAX_INPUT, stdin)) {
		op = '\0';
		num1 = 0.0;
		num2 = 0.0;
		parse(input, &op, &num1, &num2, &result);
		switch (op) {
			case '+':
				result = num1 + num2;
				printf("\t%f\n", result);
				break;
			case '-':
				result = num1 - num2;
				printf("\t%f\n", result);
				break;
			case '*':
				result = num1 * num2;
				printf("\t%f\n", result);
				break;
			case '/':
				result = num1 / num2;
				printf("\t%f\n", result);
				break;
			default:
				result = 0.0;
				printf("\terror\n");
				break;
		}
	}
	return 0;
}
