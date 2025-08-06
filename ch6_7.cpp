#include <cstdio>
#include <unordered_map>

struct Account {
    long id{};
    double balance{};

    virtual ~Account() = default;
    virtual bool balance_check(double amount) const = 0;
    virtual double get_balance() const = 0;
    virtual void set_balance(double amount) = 0;
};

struct AccountDatabase {
    virtual ~AccountDatabase() = default;
    virtual double retrieve_amount(long id) = 0;
    virtual void set_amount(long id, double amount) = 0;
};

struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
    virtual void log_error(const char* msg) = 0;
};

struct CheckingAccount : Account {  // 당좌계좌
    CheckingAccount(long id, double balance) {
        this->id = id;
        this->balance = balance;
    }

    bool balance_check(double amount) const override {
        if (balance < amount) {
            return false;
        }

        return true;
    }

    double get_balance() const override {
        return balance;
    }

    void set_balance(double amount) override {
        balance += amount;
    }
};

struct SavingsAccount : Account {   // 저축계좌
    SavingsAccount(long id, double balance) {
        this->id = id;
        this->balance = balance;
    }

    bool balance_check(double amount) const override {
        if (balance < amount) {
            return false;
        }

        return true;
    }

    double get_balance() const override {
        return balance;
    }

    void set_balance(double amount) override {
        balance += amount;
    }
};


struct ConsoleLogger : Logger {
    const char* prefix;

    ConsoleLogger(const char* prefix)
            : prefix {prefix} { }

    void log_transfer(long from, long to, double amount) override {
        printf("[%s] %ld -> %ld: %f\n", prefix, from, to, amount);
    }

    void log_error(const char* msg) override {
        printf("%s\n", msg);
    }
};

struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld -> %ld: %f\n", from, to, amount);
    }

    void log_error(const char* msg) override {
        printf("%s\n", msg);
    }
};

struct InMemoryAccountDatabase : AccountDatabase {
    std::unordered_map<long, double> accounts_map; // Id, Amount

    double retrieve_amount(long id) override {
        return accounts_map[id];
    }

    void set_amount(long id, double amount) override {
        accounts_map[id] = amount;
    }
};

template<typename T>
struct Bank {
    Bank(Logger& logger, AccountDatabase& accountDatabase)
            : logger{logger}, accountDatabase{accountDatabase} { }

    void make_transfer(T& from_acc, T& to_acc, double amount) {
        double from_amount = accountDatabase.retrieve_amount(from_acc.id);
        double to_amount = accountDatabase.retrieve_amount(to_acc.id);

        if (!from_acc.balance_check(amount)) {
            logger.log_error("Out of balance.");
            return;
        }

        accountDatabase.set_amount(from_acc.id, from_amount - amount);  // 송신 측(잔액 감소)
        accountDatabase.set_amount(to_acc.id, to_amount + amount);  // 수신 측(잔액 증가)

        logger.log_transfer(from_acc.id, to_acc.id, amount);
    }

private:
    Logger& logger;
    AccountDatabase& accountDatabase;
};


int main() {
    CheckingAccount acc_1{1001, 2000.0};
    CheckingAccount acc_2{2002, 5000.0};

    SavingsAccount acc_3{3003, 100.0};

    InMemoryAccountDatabase accountDB;
    accountDB.set_amount(acc_1.id, acc_1.balance);
    accountDB.set_amount(acc_2.id, acc_2.balance);

    ConsoleLogger consoleLogger{"csl"};

    Bank<Account> bank{consoleLogger, accountDB};
    bank.make_transfer(acc_1, acc_2, 1000.0);
    bank.make_transfer(acc_1, acc_2, 5000000.0);
    bank.make_transfer(acc_2, acc_3, 500.0);

    return 0;
}