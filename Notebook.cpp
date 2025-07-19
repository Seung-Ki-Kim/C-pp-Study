# include <cstdio>
# include <cstring>


void carbon_thaw(const int& encased_solo) {
	// encased_solo++;
	auto& hibernation_sick_solo = const_cast<int&>(encased_solo);
	hibernation_sick_solo++;
}

short increment_as_short(void* target) {
	auto as_short = static_cast<short*>(target);
	*as_short += 1;
	
	return *as_short;
}


int main() {
	int i = 10;
	int* i_ptr = &i;

	carbon_thaw(*i_ptr);
	printf("%d\n", *i_ptr);

	short beast { 665 };
	auto mark_of_the_beast = increment_as_short(&beast);

	printf("%d\n", mark_of_the_beast);
	
	char text[] = "A";
	void* t;
	
	t = text;

	auto v = static_cast<int*>(t);
	
	printf("%d\n", *v);

	return 0;
}
