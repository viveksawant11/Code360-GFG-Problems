#include <bits/stdc++.h>
using namespace std;

int findThirdLargest(vector<int>& arr) {
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } 
        else if (arr[i] > second) {
            third = second;
            second = arr[i];
        } 
        else if (arr[i] > third) {
            third = arr[i];
        }
    }

    return third;
}

int main() {
    int T; 
    cin >> T;
    
    while (T--) {
        int N; 
        cin >> N;
        
        vector<int> arr(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }

        cout << findThirdLargest(arr) << endl;
    }

    return 0;
}

