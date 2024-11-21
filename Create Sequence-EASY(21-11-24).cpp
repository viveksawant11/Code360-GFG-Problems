#include<bits/stdc++.h>
using namespace std;

vector<long long> createSequence(long long n) {
    vector<long long> ans;
    queue<long long> q;

    if (n == 2) {
        ans.push_back(2);
        return ans;
    }

    q.push(2);
    q.push(5);

    while (!q.empty()) {
        long long num = q.front();
        q.pop();

        if (num < n) {
            ans.push_back(num);

            q.push((num * 10) + 2);
            q.push((num * 10) + 5);
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<long long> result = createSequence(n);

        for (size_t i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}
