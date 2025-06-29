#include <cstdio>

void power_up_rat_thing(int nuclear_isotopes) {
	static thread_local int rat_things_power = 200;	
	const auto waste_heat = rat_things_power * 20;

	rat_things_power = rat_things_power + nuclear_isotopes;

	if (waste_heat > 10000) {
		printf("Warning! Hot doggie!\n");
	}

	printf("Rat_thing power: %d\n", rat_things_power);
}


int main() {
	power_up_rat_thing(100);
	power_up_rat_thing(100000);

	int* my_int_ptr = new int{42};
	printf("%d\n", *my_int_ptr);
	*my_int_ptr = 30;
	printf("%d\n", *my_int_ptr);
	
	delete my_int_ptr;


	return 0;
}
