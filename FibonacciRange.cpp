class FibonacciRange {
public:
    class Iterator {
    public:
        Iterator(int a, int b, int count);
        int operator*() const;
        Iterator& operator++();
        bool operator!=(const Iterator& other) const;
    private:
        int a_, b_, count_;
    };

    explicit FibonacciRange(int limit);
    Iterator begin() const;
    Iterator end() const;

private:
    int limit_;
};


FibonacciRange::FibonacciRange(int limit) : limit_(limit) {}

FibonacciRange::Iterator::Iterator(int a, int b, int count)
    : a_(a), b_(b), count_(count) {}

int FibonacciRange::Iterator::operator*() const {
    return a_;
}

FibonacciRange::Iterator& FibonacciRange::Iterator::operator++() {
    int next = a_ + b_;
    a_ = b_;
    b_ = next;
    --count_;
    return *this;
}

bool FibonacciRange::Iterator::operator!=(const FibonacciRange::Iterator& other) const {
    return count_ != other.count_;
}

FibonacciRange::Iterator FibonacciRange::begin() const {
    return Iterator(0, 1, limit_);
}

FibonacciRange::Iterator FibonacciRange::end() const {
    return Iterator(0, 1, 0);
}

