#include <bits/stdc++.h>

__int128 pow_int128(__int128 base, __int128 exponent, __int128 mod = 0) {
  __int128 ret = 1;
  while (exponent > 0) {
    if (exponent & 1) ret = ret * base;
    base = base * base;
    exponent >>= 1;
    if(mod!=0) base %= mod, ret %= mod;
  }
  return ret;
}

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0
        ? static_cast<__uint128_t>(-(value + 1)) + 1
        : static_cast<__uint128_t>(value);
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse_i128(std::string_view s) {
  bool negative = !s.empty() && s.front() == '-';
  __int128 ret = 0;
  for (size_t i = negative; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return negative ? -ret : ret;
}

// 既存コードとの互換用
__int128 parse(const std::string &s) {
  return parse_i128(s);
}
