#include <bits/stdc++.h>
using namespace std;

int countPrimeFactors(int n) {
    int cnt = 0;
    
    for (int x = 2 ; x * x <= n ; x++) {
        while (n % x == 0) {
        cnt++;
        n /= x;
        }
    }

    if (n > 1)
        cnt++;

    return cnt;
}

int Rounds(int a, int b) {
    if (a == b)
        return 0;
    
    int totalFactors = 0;

    for (int i = b + 1 ; i <= a ; i++) {
        totalFactors += countPrimeFactors(i);
    }

    return totalFactors;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << Rounds(a, b) << "\n";
    }
    return 0;
}
