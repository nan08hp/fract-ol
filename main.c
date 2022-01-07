#include <stdio.h>

void func(int *x)
{
	*x += 1;

	int y = *x + 1;
}

int main() {
	int x = 0;

	for (int i = 0; i < 10; i++) {
		func(&x);
		printf("i: %d x: %d\n", i, x);
	}

	printf("%d\n", x);
}
