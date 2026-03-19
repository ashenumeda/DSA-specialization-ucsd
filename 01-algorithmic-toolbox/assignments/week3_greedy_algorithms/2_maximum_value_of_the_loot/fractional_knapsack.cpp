#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  std::vector<int> used_indexes(weights.size(), 0);

  while (capacity > 0) {
    double max_value_per_unit = 0.0;
    int index = -1;

    for (int i = 0; i < weights.size(); i++) {
      double value_per_unit = double(values[i]) / weights[i];

      if (value_per_unit > max_value_per_unit && used_indexes[i]==0) {
        max_value_per_unit = value_per_unit;
        index = i;
      }
    }

    if (index == -1) {return value;}
    
    if (weights[index] <= capacity) {
      value += weights[index] * max_value_per_unit;      
      capacity -= weights[index];
    } else {
      value += capacity * max_value_per_unit;
      capacity -= capacity;
    }
    used_indexes[index] = 1;   
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout << std::fixed;
  std::cout.precision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}
