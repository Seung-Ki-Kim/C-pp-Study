# include <cstdio>

struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("%ld -> %ld: %f\n", from, to, amount);
    }
};

struct Bank {
    void make_transfer(long from, long to, double amount) {
        // snip
        ConsoleLogger logger;
        logger.log_transfer(from, to, amount);
    }
};


int main() {
    Bank bank;

    bank.make_transfer(1000, 2000, 50);
    bank.make_transfer(2000, 4000, 20);

    return 0;
}