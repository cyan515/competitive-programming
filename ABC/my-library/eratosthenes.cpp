#include <bits/stdc++.h>
using namespace std;

// N までの数が素数かどうかの長さ N+1 の vector を返す
// 0, 1 は false
// keywords: 素数判定 エラトステネスの篩 エラトステネスのふるい
vector<bool> eratosthenes(int _N) {
  vector<bool> isprime(_N+1, true);
  isprime[0] = isprime[1] = false;
  for (int p = 2; p <= _N; ++p) {
    if (!isprime[p]) continue;
    for (int q = p * 2; q <= _N; q += p) {
      isprime[q] = false;
    }
  }
  return isprime;
}