#include <bits/stdc++.h>
using namespace std;

bool isSpecial(const string& str) {
    int n = str.size();
    for (int i = 0; i < n; ++i) {
        long long num = 0;
        for (int j = i; j < n; ++j) {
            num = num * 10 + (str[j] - '0');
            
            if (num == 0) continue;
            if (num > 1e9) break; // Only check for numbers up to 9 digits
            
            long long root = sqrt(num);
            if (root * (root + 1) == num) return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (isSpecial(s)) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    return 0;
}
