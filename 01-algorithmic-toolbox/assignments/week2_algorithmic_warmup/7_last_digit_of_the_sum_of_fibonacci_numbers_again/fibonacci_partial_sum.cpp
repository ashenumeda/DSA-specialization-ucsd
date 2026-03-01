#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    long long previous = 0;
    long long current = 1;
    /*
        Find the sum of (from - 1) fibonacci numbers modulo 10
        fibFrom_1_mod_10 = (fib1 + fib2 + .... + fibFrom_1) % 10
    */
    int pos1 = (from - 1 + 2) % 60; // S(from-1) = fib(from-1 + 2) - 1

    int fibFrom_1_Plus2_mod_10 = 0;
    if (pos1 <= 1) {
        fibFrom_1_Plus2_mod_10 = pos1;
    }

    for (int i = 2; i <= pos1; i++) { 
        long long temp_pre = previous;
        previous = current;
        current = (current + temp_pre) % 10;
    }
    fibFrom_1_Plus2_mod_10 = current;

    int Sfrom_1 = (fibFrom_1_Plus2_mod_10 + 10 - 1) % 10;

    /*
        Find the sum of (to) fibonacci numbers modulo 10
        fibTo_mod_10 = (fib1 + fib2 + .... + fibTo) % 10
    */
    previous = 0;
    current = 1;
    int pos2 = (to + 2) % 60; // STo = fib(to + 2) - 1

    int fibTo_mod_10 = 0;
    if (pos2 <= 1) {
        fibTo_mod_10 = pos2;
    }

    for (int i = 2; i <= pos2; i++) { 
        long long temp_pre = previous;
        previous = current;
        current = (current + temp_pre) % 10;
    }
    fibTo_mod_10 = current;

    int STo = (fibTo_mod_10 + 10 - 1) % 10;

    // last digit of fib(from) + fib(from+1) + fib(from+2) + ... + fib(to-1) + fib(to) = (STo + 10 - Sfrom_1) % 10
    return (STo + 10 - Sfrom_1) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
