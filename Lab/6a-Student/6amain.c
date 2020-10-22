#include <stdio.h>
#include "6a.h"
int main() {
	char expression[350];
	int number_of_inputs = 0;
	scanf("%d", &number_of_inputs);
	for(int counter = 0; counter < number_of_inputs; ++ counter) {
		scanf("%s", expression);
		printf("%d\n", postfix_eval(expression));
	}
	return 0;
}


