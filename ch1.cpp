#include <cstdio>

int absolute_value(int x) {
	int val = x;

	if (val < 0) {
		val *= -1;
	}

	return val;
}

int sum(int a, int b) {
	return (a + b);
}

int main() {
	int my_num = -10;
	printf("The absolute value of %d is %d.\n", my_num, absolute_value(my_num));

	return 0;
}
