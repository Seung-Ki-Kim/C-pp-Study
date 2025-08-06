#include <cstdio>
#include <unordered_map>

template<typename ID>
struct AccountDatabase {
    virtual ~AccountDatabase() = default;
    virtual double retrieve_amount(ID id) = 0;
    virtual void set_amount(ID id, double amount) = 0;
};

template<typename ID>
struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(ID from, ID to, double amount) = 0;
    virtual void log_error(const char* msg) = 0;
};

template<typename ID>
struct ConsoleLogger : Logger<ID> {
    const char* prefix;

    ConsoleLogger(const char* prefix)
            : prefix {prefix} { }

    void log_transfer(ID from, ID to, double amount) override {
        printf("[%s] %ld -> %ld: %f\n", prefix, from, to, amount);
    }

    void log_error(const char* msg) override {
        printf("%s\n", msg);
    }
};

template<typename ID>
struct FileLogger : Logger<ID> {
    void log_transfer(ID from, ID to, double amount) override {
        printf("[file] %ld -> %ld: %f\n", from, to, amount);
    }

    void log_error(const char* msg) override {
        printf("%s\n", msg);
    }
};

template<typename ID>
struct InMemoryAccountDatabase : AccountDatabase<ID> {
    std::unordered_map<ID, double> accounts_map;

    double retrieve_amount(ID id) override {
        return accounts_map[id];
    }

    void set_amount(ID id, double amount) override {
        accounts_map[id] = amount;
    }
};

template<typename ID>
struct Bank {
    Bank(Logger<ID>& logger, AccountDatabase<ID>& accountDatabase)
            : logger{logger}, accountDatabase{accountDatabase} { }

    void make_transfer(ID from_id, ID to_id, double amount) {
        double from_amount = accountDatabase.retrieve_amount(from_id);
        double to_amount = accountDatabase.retrieve_amount(to_id);

        if (from_amount < amount) {
            logger.log_error("Out of balance.");
            return;
        }

        accountDatabase.set_amount(from_id, from_amount - amount);  // 송신 측(잔액 감소)
        accountDatabase.set_amount(to_id, to_amount + amount);  // 수신 측(잔액 증가)

        logger.log_transfer(from_id, to_id, amount);
    }

private:
    Logger<ID>& logger;
    AccountDatabase<ID>& accountDatabase;
};


int main() {
    InMemoryAccountDatabase<long> accountDB;
    ConsoleLogger<long> consoleLogger{"csl"};

    accountDB.accounts_map[1001] = 2000.0;
    accountDB.accounts_map[2002] = 5000.0;

    Bank<long> bank{consoleLogger, accountDB};

    bank.make_transfer(1001, 2002, 1000.0);
    bank.make_transfer(1001, 2002, 5000000.0);


    return 0;
}
