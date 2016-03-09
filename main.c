#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 100

int isop(char);

int main()
{
	char input[MAX_INPUT];
	char *endp[MAX_INPUT];
	char op;
	float num1, num2, result = 0.0;
	int i, j;

	while (fgets(input, MAX_INPUT, stdin)) {
		*endp = '\0';
		op = '\0';
		num1 = 0.0;
		num2 = 0.0;
		for (i = 0; isspace(input[i]); i++)
			;
		num1 = strtod(&input[i], endp);
		if (num1 == 0.0 && isop(input[i]))
			/* this can happen when input is "+ x", "- x",
			 * "*x", "* x", "/x" or "/ x" */
			num1 = result;
		for (j = 0; isspace((*endp)[j]); j++)
			;
		op = (*endp)[j];
		if (isop(op)) {
			j++;
			num2 = strtod(&(*endp)[j], NULL);
		}
		else if (isop(input[i])) {
			/* this can happen when input is "+x" or "-x" */
			num2 = num1;
			num1 = result;
			op = '+';
		}
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

int isop(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
