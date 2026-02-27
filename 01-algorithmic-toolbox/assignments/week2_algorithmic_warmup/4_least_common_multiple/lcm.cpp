#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_Euclid(long long a, long long b) {
  if (a > b) {
    return gcd_Euclid(b, a);
  }
  if (a == 0) {
    return b;
  }
  return gcd_Euclid(b % a, a);
}

/*
  we can get the lcm of a and b by
  (a * b) / gcd_Euclid(a, b)
*/
long long lcm_fast(long long a, long long b) {
  return (a * b) / gcd_Euclid(a, b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
