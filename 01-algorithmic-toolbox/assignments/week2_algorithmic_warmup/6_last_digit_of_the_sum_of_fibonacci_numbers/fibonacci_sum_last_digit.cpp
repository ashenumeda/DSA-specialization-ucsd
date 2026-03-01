#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

/*
    fibn+2 = fibn+1 + fibn

    fibn = fibn+2 - fibn+1

    n          n
    ∑ (fibn) = ∑ (fibn+2 - fibn+1)
    k=0        k=0

    Sn = (fib2 - fib1) + (fib3 - fib2) + (fib4 - fib3) + (fibn+1 - fn) + (fibn+2 - fibn+1)

    Sn = fibn+2 - f1

    Sn = fibn+2 - 1
*/
int fibonacci_sum_fast(long long n) {
    long long previous = 0;
    long long current  = 1;

    //Find the N for 10
    int count = 1;

    while ((count == 1) || !(previous == 0 && current == 1)) {
        count++;
        long long temp_pre = previous;
        previous = current;
        current = (current + temp_pre) % 10;
    }
    int N = count - 1; // N = 60

    //Find the position of fibn+2_mod_10 in the N element pattern.
    int pos = (n + 2) % N;

    //Find pos th fibonacci number modulo 10 (fibn+2_mod_10)
    int fibn_2_mod_10 = 0;
    if (pos <= 1) {
        fibn_2_mod_10 = pos;
    }

    for (int i = 2; i <= pos; i++) { 
        long long temp_pre = previous; //After finding N, again previous = 0, current = 1
        previous = current;
        current = (current + temp_pre) % 10;
    }
    fibn_2_mod_10 = current;

    return (fibn_2_mod_10 + 10 - 1) % 10; /* Adding 10 is not change the result of fibn_2_mod_10, but it is useful if the
    result of fibn_2_mod_10 is equl to 0. otherwise it will give unexpected result. */
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
