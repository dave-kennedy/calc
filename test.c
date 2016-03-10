#include <stdio.h>
#include <string.h>

#include "calc.h"

#define assert(message, test) do { if (!(test)) return message; } while (0)
#define run_test(test) do { char *message = test(); tests_run++; \
                            if (message) return message; } while (0)

int tests_run = 0;

static char *test_isop()
{
	assert("error: + is an operator", isop('+'));
	assert("error: - is an operator", isop('-'));
	assert("error: * is an operator", isop('*'));
	assert("error: / is an operator", isop('/'));
	assert("error: x is not an operator", !isop('x'));
	return 0;
}

static char *test_parse()
{
	char input[MAX_INPUT];
	char op;
	float num1, num2, result = 0.0;

	strcpy(input, "1+2");
	parse(input, &op, &num1, &num2, &result);
	assert("error: op should be +", op == '+');
	assert("error: num1 should be 1.0", num1 == 1.0);
	assert("error: num2 should be 2.0", num2 == 2.0);
	strcpy(input, "1 + 2");
	parse(input, &op, &num1, &num2, &result);
	assert("error: op should be +", op == '+');
	assert("error: num1 should be 1.0", num1 == 1.0);
	assert("error: num2 should be 2.0", num2 == 2.0);
	strcpy(input, " 1+2");
	parse(input, &op, &num1, &num2, &result);
	assert("error: op should be +", op == '+');
	assert("error: num1 should be 1.0", num1 == 1.0);
	assert("error: num2 should be 2.0", num2 == 2.0);
	strcpy(input, " 1 + 2");
	parse(input, &op, &num1, &num2, &result);
	assert("error: op should be +", op == '+');
	assert("error: num1 should be 1.0", num1 == 1.0);
	assert("error: num2 should be 2.0", num2 == 2.0);
	strcpy(input, "+2");
	parse(input, &op, &num1, &num2, &result);
	assert("error: op should be +", op == '+');
	assert("error: num1 should be 0.0", num1 == 0.0);
	assert("error: num2 should be 2.0", num2 == 2.0);
	strcpy(input, "+ 2");
	parse(input, &op, &num1, &num2, &result);
	assert("error: op should be +", op == '+');
	assert("error: num1 should be 0.0", num1 == 0.0);
	assert("error: num2 should be 2.0", num2 == 2.0);
	strcpy(input, " +2");
	parse(input, &op, &num1, &num2, &result);
	assert("error: op should be +", op == '+');
	assert("error: num1 should be 0.0", num1 == 0.0);
	assert("error: num2 should be 2.0", num2 == 2.0);
	strcpy(input, " + 2");
	parse(input, &op, &num1, &num2, &result);
	assert("error: op should be +", op == '+');
	assert("error: num1 should be 0.0", num1 == 0.0);
	assert("error: num2 should be 2.0", num2 == 2.0);
	return 0;
}

static char *test_all()
{
	run_test(test_isop);
	run_test(test_parse);
	return 0;
}

int main()
{
	char *result;

	result = test_all();
	if (result != 0)
		printf("%s\n", result);
	else
		printf("all tests passed\n");
	printf("tests run: %d\n", tests_run);
	return result != 0;
}
