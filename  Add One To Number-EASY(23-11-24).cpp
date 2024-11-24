#include <bits/stdc++.h>
using namespace std;

vector<int> addOneToNumber(vector<int> arr) {
    int n = arr.size();
    int carry = 1;

    for (int i = n - 1; i >= 0; i--) {
        arr[i] += carry;

        if (arr[i] < 10) {
            carry = 0;
            break;
        }

        arr[i] = 0;
    }

    // If carry is still present, prepend 1
    if (carry) {
        arr.insert(arr.begin(), 1);
    }

    // Remove leading zeroes
    while (arr.size() > 0 && arr[0] == 0) {
        arr.erase(arr.begin());
    }

    return arr;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n; 

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; 
        }

        vector<int> result = addOneToNumber(arr);

        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
