#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> printPattern(int n)
{
    vector<vector<int>> result;

    int totalNumbers = n * (n + 1);
    int start = 1;

    for (int i = 0 ; i < n ; i++) {
        vector<int> row;
        int count = n - i;

        for (int j = 0 ; j < count ; j++) {
            row.push_back(start);
            start++;
        }

        int rightstart = totalNumbers - (count - 1);

        for (int j = 0 ; j < count ; j++) {
            row.push_back(rightstart);
            rightstart++;
        }

        totalNumbers -= count;

        result.push_back(row);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> pattern = printPattern(n);
    
    for (const auto& row : pattern) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
