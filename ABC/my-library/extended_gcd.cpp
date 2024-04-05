#include <bits/stdc++.h>
using namespace std;

// 拡張ユークリッドの互除法
// 不定方程式の解が x y に代入される。
long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = ext_gcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
