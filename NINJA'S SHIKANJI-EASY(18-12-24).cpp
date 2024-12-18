#include <iostream>
#include <vector>
using namespace std;

bool canProvideChange(const vector<int>& billArr) {
    int count5 = 0, count10 = 0;  

    for (int bill : billArr) {
        if (bill == 5) {
            count5++;                               // Directly add $5 to the cash register
        } else if (bill == 10) {
            if (count5 > 0) {                       // Check if we can provide $5 change for a $10 bill
                count5--;
                count10++;
            } else {
                return false;                       // Cannot provide change
            }
        } else if (bill == 20) {
            if (count10 > 0 && count5 > 0) {        // Check if we can provide $15 change for a $20 bill
                count10--;
                count5--;
            } else if (count5 >= 3) {
                count5 -= 3;                        // Use three $5 notes for $15 change
            } else {
                return false;  
            }
        }
    }

    return true;  
}

int main() {
    int testCases;
    cin >> testCases; 

    while (testCases--) {
        int n;
        cin >> n;  
        vector<int> billArr(n);
        for (int i = 0; i < n; ++i) {
            cin >> billArr[i];  
        }

        if (canProvideChange(billArr)) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }

    return 0;
}
