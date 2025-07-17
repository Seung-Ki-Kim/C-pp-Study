#include <cstdio>

struct Element {
	char prefix[2];
	short operating_number;

	Element* next{};
	Element* previous{};

	void insert_after(Element* new_element) {
		new_element->next = this->next;
		this->next = new_element;
	}

	void insert_before(Element* new_element) {
		new_element->previous = this->previous;
		this->previous = new_element;
	}
};

int main() {	
	Element t1, t2, t3;

	t1.prefix[0] = 'T';
	t1.prefix[1] = 'K';

	t2.prefix[0] = 'F';
	t2.prefix[1] = 'N';

	t3.prefix[0] = 'L';
	t3.prefix[1] = 'S';

	t1.operating_number = 421;
	t2.operating_number = 2187;
	t3.operating_number = 005;

	t1.insert_after(&t2);
	t2.insert_after(&t3);
	
	t3.insert_before(&t2);
	t2.insert_before(&t1);
	
	for (Element* cursor = &t1; cursor; cursor = cursor->next) {
		printf("stomtrooper %c%c-%d\n", 
				cursor->prefix[0],
				cursor->prefix[1],
				cursor->operating_number);
	}

	printf("\n");

	for (Element* cursor = &t3; cursor; cursor = cursor->previous) {
		printf("stomtrooper %c%c-%d\n",
				cursor->prefix[0],
				cursor->prefix[1],
				cursor->operating_number);
	}


	return 0;
}
