#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

/*  fib n % 10 = [fib (n-1) % 10] + [fib (n-2) % 10]
    Therefore for finding mod 10 of n th fibonacci number, we can find mod 10 of n-1 th fibonnaci and mod 10 of n-2 th
    fibonacci. Doing it recursively we can find the answer.
*/
int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1) {
        return 1;
    }
    int pre = 0;
    int curr = 1;

    for (int i = 2; i <= n; i++) {
        int temp_curr = curr;
        curr = (curr + pre) % 10;
        pre = temp_curr;
    }

    return curr;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
