#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;

  while (a.size() > 0) {

    int max_index = 0;

    for (size_t i = 0; i < a.size(); i++) {
      if (std::stoi(a[i] + a[max_index]) > std::stoi(a[max_index] + a[i])) {
        max_index = i;
      }
    }
    ret << a[max_index];
    a.erase(a.begin() + max_index);
  }

  string result;
  ret >> result;
  return result;  
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
