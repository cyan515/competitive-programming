#include <bits/stdc++.h>
using namespace std;

// S の i 文字目以降で最初に文字 c が登場する index
// @see https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd
vector<vector<int> > calc_next(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}
