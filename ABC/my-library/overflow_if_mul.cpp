#include <bits/stdc++.h>
using namespace std;

// a * b がオーバーフローするならtrueを返す
// keywords: オーバーフロー オーバフロー
template <class T> bool overflow_if_mul(T a, T b) {
  return (std::numeric_limits<T>::max() / a) < b;
}
