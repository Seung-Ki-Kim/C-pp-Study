#include <cstdio>

void read_from(char* target) {
	printf("%s\n", target);
}

void write_to(char* target, int indx, char value) {
	target[indx] = value;
}

int main() {
	char lower[] = "abc?e";
	char upper[] = "ABC?E";

	char* upper_ptr = upper;

	lower[3] = 'd';
	upper_ptr[3] = 'D';

	char letter_d = lower[3];
	char letter_D = upper_ptr[3];

	printf("lower: %s\n", lower);
	printf("upper: %s\n", upper);

	read_from(lower);
	write_to(lower, 3, 'F');
	
	printf("%s\n", lower);


	return 0;
}
