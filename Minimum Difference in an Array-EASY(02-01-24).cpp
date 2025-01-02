#include <bits/stdc++.h> 
using namespace std;

int minDiff(int n, vector < int > arr) {
   sort(arr.begin(), arr.end());

   int minDiff = INT_MAX;

   for (int i = 1 ; i < n ; i++) {
      minDiff = min(minDiff, arr[i] - arr[i - 1]);
   }

   return minDiff;
}

int main() {
    int n = 4;
    vector<int> arr = {1,8,3,10};

    cout << minDiff(n, arr);
    
    return 0;
}
