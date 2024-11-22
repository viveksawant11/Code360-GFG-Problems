#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getKthLargest(vector<int> &arr, int k) {
    int n = arr.size();
    // Min-heap to store the k largest sums
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Generate all subarray sums
    for (int start = 0; start < n; ++start) {
        int sum = 0;

        for (int end = start; end < n; ++end) {
            sum += arr[end];

            minHeap.push(sum);
            if (minHeap.size() > k) {
                minHeap.pop(); 
            }
        }
    }

    return minHeap.top();
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << getKthLargest(arr, k) << endl;
    }
    return 0;
}
