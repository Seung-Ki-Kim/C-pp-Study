#include <cstdio>

struct ClockOfTheLongNow {
	int year = 2019;

	int get_year() const {
		return year;
	}
	
	bool is_leap_year(const ClockOfTheLongNow& clock) {
		if (clock.get_year() % 4 > 0) {
			return false;
		}

		return true;
	}
};

struct Avout {
	ClockOfTheLongNow apert;
	const char* name;
	

	Avout(const char* name, long year_of_apert) : 
		name{ name }, apert{ year_of_apert } {}

	void announce() const {
		printf("%s %d\n", name, apert.get_year());
	}
};

int main() {
	Avout raz { "Erasmas", 3010 };
	Avout jad { "Jad", 4090 };

	raz.announce();
	jad.announce();

	return 0;
}
