#include <bits/stdc++.h>
using namespace std;

string reformatString(string& s, int k) {
    string temp = "";

    for (char ch : s) {
        if (ch != '-') {
            temp += toupper(ch);
        }
    }

    int n = temp.size();
    if (n == 0) return "";

    int firstGroupSize = n % k;
    if (firstGroupSize == 0) firstGroupSize = k;

    string result = temp.substr(0, firstGroupSize); 

    for (int i = firstGroupSize; i < n; i += k) {
        result += '-' + temp.substr(i, k);
    }

    return result;
}

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int k;
        string S;
        cin >> k >> S;

        cout << reformatString(S, k) << endl;
    }

    return 0;
}
