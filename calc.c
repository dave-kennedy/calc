#include <ctype.h>
#include <stdlib.h>

#include "calc.h"

int calc(char op, float num1, float num2, float *result)
{
	switch (op) {
		case '+':
			*result = num1 + num2;
			return 1;
		case '-':
			*result = num1 - num2;
			return 1;
		case '*':
			*result = num1 * num2;
			return 1;
		case '/':
			*result = num1 / num2;
			return 1;
		default:
			*result = 0.0;
			return 0;
	}
}

int isop(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

void parse(char *input, char *op, float *num1, float *num2, float *result)
{
	char *endp[MAX_INPUT];

	while (isspace(*input))
		input++;
	*num1 = strtod(input, endp);
	if (*num1 == 0.0 && isop(*input))
		/* this can happen when input is "+ x", "- x",
		 * "*x", "* x", "/x" or "/ x" */
		*num1 = *result;
	while (isspace(**endp))
		(*endp)++;
	*op = **endp;
	if (isop(*op)) {
		(*endp)++;
		*num2 = strtod(*endp, NULL);
	}
	else if (isop(*input)) {
		/* this can happen when input is "+x" or "-x" */
		*num2 = *num1;
		*num1 = *result;
		*op = '+';
	}
}
