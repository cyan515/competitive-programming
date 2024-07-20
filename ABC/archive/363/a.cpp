#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long powll(long long BASE, long long EXPONENT) {
  long long RET = 1;
  while (EXPONENT > 0) {
    if (EXPONENT & 1) RET = RET * BASE;
    BASE = BASE * BASE;
    EXPONENT >>= 1;
  }
  return RET;
}

string generatePalindrome(long long prefix, bool isOdd) {
    string result = to_string(prefix);
    int startIndex = isOdd ? result.length() - 2 : result.length() - 1;
    for (int i = startIndex; i >= 0; i--) {
        result += result[i];
    }
    return result;
}

string findNthPalindrome(long long N) {
    long long len = 1;
    long long count = 9;
    while (N > count) {
        N -= count;
        len++;
        count = 9 * powll(10, (len - 1) / 2);
    }

    long long prefix = powll(10, (len - 1) / 2) + N - 1;
    return generatePalindrome(prefix, len % 2);
}

int main() {
    long long N;
    cin >> N;N--;
    cout << findNthPalindrome(N) << endl;
    return 0;
}