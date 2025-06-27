#include <cstdio>

struct College {
	char name[256];
};

void print_name(College* colleges, size_t n_colleges) {
	for (size_t i = 0; i < n_colleges; i++) {
		printf("%s College\n", colleges[i].name);
	}
}

int main() {
	char lower[] = "abc?e";
	char upper[] = "ABC?E";

	char* upper_ptr = upper;	// &upper[0]
	
	lower[3] = 'd';
	upper_ptr[3] = 'D';

	char letter_d = lower[3];
	char letter_D = upper_ptr[3];

	printf("lower: %s\n", lower);
	printf("upper: %s\n", upper);
	
	





	return 0;
}
