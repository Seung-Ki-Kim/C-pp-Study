class PrimeNumberRange {
public:
    class Iterator {
    public:
        Iterator(int current, int end)
            : current_(current), end_(end) {
            advance_to_next_prime();
        }

        int operator*() const {
            return current_;
        }

        Iterator& operator++() {
            ++current_;
            advance_to_next_prime();
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current_ <= end_;
        }

    private:
        int current_;
        int end_;

        bool is_prime(int n) const {
            if (n < 2) return false;
            for (int i = 2; i * i <= n; ++i)
                if (n % i == 0) return false;
            return true;
        }

        void advance_to_next_prime() {
            while (current_ <= end_ && !is_prime(current_)) {
                ++current_;
            }
        }
    };

    PrimeNumberRange(int start, int end)
        : start_(start), end_(end) {}

    Iterator begin() const { return Iterator(start_, end_); }
    Iterator end() const { return Iterator(end_ + 1, end_); }

private:
    int start_;
    int end_;
};
