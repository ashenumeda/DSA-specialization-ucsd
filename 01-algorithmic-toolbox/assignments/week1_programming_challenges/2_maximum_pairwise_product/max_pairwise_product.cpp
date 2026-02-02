#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                ((long long)numbers[first] * numbers[second]));
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    int n = numbers.size();

    int largestIndex1 = -1;
    int max = -1;
    for (int i = 0; i < n; i ++) {
         if (numbers[i] > max) {
            largestIndex1 = i;
            max = numbers[i];
         }
    }

    int largestIndex2 = -1;
    int max2 = -1;
    for (int i = 0; i < n; i++) {
        if (numbers[i] > max2 && numbers[i] <= max && i != largestIndex1) {
            largestIndex2 = i;
            max2 = numbers[i];
        }
    }

    return (long long)numbers[largestIndex1] * numbers[largestIndex2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
/*
    while (true) {
        int n = 2 + std::rand() % 100;

        std::vector<int> numbers(n);
        for (int i = 0; i < n; i++) {
            numbers[i] = std::rand() % 1000;
        } 

        std::cout << n << "\n";
        for (int i = 0; i < n; i++) {
            std::cout << numbers[i] << " ";
        }
        std::cout << "\n";

        long long r1 = MaxPairwiseProduct(numbers);
        long long r2 = MaxPairwiseProductFast(numbers);

        if (r1 != r2) {
            std::cout << "wrong answers: " << r1 << " " << r2;
            break;
        }
        std::cout << "ok" << "\n";
    }
*/

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
