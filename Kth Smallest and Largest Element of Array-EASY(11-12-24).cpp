#include<bits/stdc++.h>
using namespace std;

// Method - 1
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    sort(arr.begin(), arr.end());

    int kthSmallest = arr[k - 1];
    int kthLargest = arr[n - k];

    return {kthSmallest, kthLargest};
}

// Method - 2 (Using min-heap and max-heap)
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0 ; i < n ; i++) {
        minHeap.push(arr[i]);

        if (minHeap.size() > k) 
            minHeap.pop();
    }
    int kthLargest = minHeap.top();

    // Max Heap
    priority_queue<int> maxHeap;

    for (int i = 0 ; i < n ; i++) {
        maxHeap.push(arr[i]);

        if (maxHeap.size() > k) 
            maxHeap.pop();
    }
    int kthSmallest = maxHeap.top();

    return {kthSmallest, kthLargest};
}

int main()
{
    int T;
    cin >> T; 

    while (T--)
    {
        int N, K;
        cin >> N >> K;

        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Arr[i];
        }

        vector<int> result = kthSmallLarge(Arr, N, K);

        cout << result[0] << " " << result[1] << endl;
    }

    return 0;
}
