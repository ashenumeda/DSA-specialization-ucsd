#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

/*
    In fibonacci numbers there's a pattern can see when computing the n th fibonacci number modulo m(lets say fibn_mod_m),
    such that after some number(lets say N) fibn_mod_m repeats.

    ex:
        m = 10, then
        fib1_mod_10 = 0
        fib2_mod_10 = 1
        fib3_mod_10 = 1
        fib4_mod_10 = 2
        fib5_mod_10 = 3
        fib5_mod_10 = 5
        .
        .
        .
        fibN_mod_10 = 0
        fibN+1_mod_10 = 1
        fibN+2_mod_10 = 1
        fibN+3_mod_10 = 2
        fibN+4_mod_10 = 3
        .
        .
        .
    
    (It's may need more than 10 pages to write 1000th fibonacci number. So dealing with large fibonacci numbers isn't easy.)
    * So, when computing the n th fibonacci number modulo m,first we need to find the perticular N for m.
    
    * Now after every N number, fibn_mod_m repeats.

    * Therefore to find n th fibonacci number modulo m(fibn_mod_m),
        1. We need to find the fibn_mod_m's position in the pattern of N long.
            position = n % N
        2. Now we need to find the (n % N) th fibonacci modulo m.
            fibn_mod_m = fib(n % N) % m
    
    * By this method we don't have to deal with very large numbers like 1000th fib.
        - This runs in O(1) time complexity because it has to compute maximum of (N - 1)th fibonacci number.
*/
long long get_fibonacci_huge_fast(long long n, long long m) {
    long long previous = 0;
    long long current  = 1;

    //Find the N
    int count = 1;

    while ((count == 1) || !(previous == 0 && current == 1)) {
        count++;
        long long temp_pre = previous;
        previous = current;
        current = (current + temp_pre) % m;
        //std::cout << count << " :" << current << '\n';
    }
    int N = count - 1;
    //std::cout << "N: " << N << '\n';

    //Find position
    int pos = n % N;

    //Find pos th fibonacci number modulo m
    if (pos <= 1) {
        return pos;
    }

    for (int i = 2; i <= pos; i++) { 
        long long temp_pre = previous; //After finding N, again previous = 0, current = 1
        previous = current;
        current = (current + temp_pre) % m;
    }
    return current;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
