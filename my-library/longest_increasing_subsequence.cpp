#include <bits/stdc++.h>
using namespace std;

vector<int> longestNonDecreasingSubsequence(const vector<long long>& nums) {
    if (nums.empty()) return {};

    vector<int> tails;
    vector<int> previousIndex(nums.size(), -1);
    vector<int> index(nums.size(), -1);
    int length = 0;

    for (int i = 0; i < nums.size(); ++i) {
        auto it = upper_bound(tails.begin(), tails.end(), nums[i]);
        int pos = distance(tails.begin(), it);

        if (it == tails.end()) {
            tails.push_back(nums[i]);
        } else {
            *it = nums[i];
        }

        index[pos] = i;
        if (pos > 0) {
            previousIndex[i] = index[pos - 1];
        }

        if (pos + 1 > length) {
            length = pos + 1;
        }
    }

    vector<int> lnds(length);
    int k = index[length - 1];
    for (int j = length - 1; j >= 0; --j) {
        lnds[j] = nums[k];
        k = previousIndex[k];
    }

    return lnds;
}