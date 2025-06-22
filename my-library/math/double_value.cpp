#include <vector>
#include <utility>
#include <atcoder/modint>
using namespace std;

// @see https://github.com/catupper/RationalModConverter/blob/main/convert.js
double double_value(atcoder::modint998244353& m) {
  pair<long long, long long> v = {m.mod(), 0};
  pair<long long, long long> w = {m.val(), 1};

  while (w.first * w.first * 2 > m.mod()) {
    long long q = v.first / w.first;
    pair<long long, long long> z = {
      v.first - q * w.first,
      v.second - q * w.second
    };
    v = w;
    w = z;
  }

  if (w.second < 0) {
    w.first *= -1;
    w.second *= -1;
  }

  return (double) w.first / (double) w.second;
}
