#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

/*
    We can get a formula,
    Sn_square = (fib0)**2 + (fib1)**2 + (fib2)**2 + ... + (fibn)**2 = fibn * fibn+1
    and,
    (fibn * fibn+1) % 10 = (fibn % 10) * (fibn+1 % 10)
*/
int fibonacci_sum_squares_fast(long long n) {
    int previous = 0;
    int current = 1;

    int pos1 = n % 60;
    int pos2 = (n + 1) % 60;

    int fibn_mod_10 = 0;
    int fibnPlus1_mod_10 = 0;

    if (pos1 <= 1) {
        fibn_mod_10 = pos1;
    } else {
        for (int i = 2; i <= pos1; i++) {
            int temp_previous = previous; //2
            previous = current; //3
            current = (current + temp_previous) % 10; //5
        }
        fibn_mod_10 = current;
    }
    
    fibnPlus1_mod_10 = (current + previous) % 10;

    return (fibn_mod_10 * fibnPlus1_mod_10) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
