#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  /*
    Thsi runs in O(√n) time complexity. 

    This is a greedy algorithm. And works by adding the smallest possible distinct positive integers starting from 1 until
    the next integer would make remaining is small to be expressed as a distinct integer greater than the last added one.
    then the remainder is appended as the final price.
  */
  vector<int> summands;

  int curr_price = 0;
  int total_price = 0;

  /*
    Check if next price(curr_price + 1) is added, will the remaining is greater than to the next price. Otherwise we can't
    add next price. 
  */
  while(n - (total_price + curr_price + 1) > curr_price + 1) { 
    curr_price++;

    summands.push_back(curr_price);
    total_price += curr_price;
  }

  summands.push_back(n - total_price);

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
