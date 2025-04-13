#include <bits/stdc++.h>
using namespace std;

/**
 * @fn
 * n 以下の数が素数かどうかを判定して結果を長さ n+1 の vector で返す
 * 0, 1 は false
 * @brief エラトステネスのふるい
 */
vector<bool> eratosthenes(const int& n) {
  vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p <= n; ++p) {
    if (!is_prime[p]) continue;
    for (int q = p * 2; q <= n; q += p) {
      is_prime[q] = false;
    }
  }
  return is_prime;
}

/**
 * @fn
 * n 以下の素数を列挙して結果を vector で返す
 * @brief 素数列挙
 */
vector<int> get_primes(int n) {
  auto is_prime = eratosthenes(n);
  vector<int> ret;
  for(int i=0;i<=n;i++) {
    if(is_prime.at(i)) ret.push_back(i);
  }
  return ret;
}
