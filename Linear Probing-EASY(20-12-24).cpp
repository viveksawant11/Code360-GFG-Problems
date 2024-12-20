#include <bits/stdc++.h>
using namespace std;

vector<int> linearProbing(vector<int> keys) {
    int n = keys.size();
    vector<int> result(n, -1); 

    for (int i = 0; i < n; i++) {
        int index = keys[i] % n; 

        // Use linear probing to find an empty slot
        while (result[index] != -1) {
            index = (index + 1) % n; // Move to the next index (circular probing)
        }

        result[index] = keys[i];
    }

    return result; 
}

int main() {
    vector<int> keys = {5, 3, 2, 6, 4}; 
    vector<int> hashTable = linearProbing(keys);

    for (int val : hashTable) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
