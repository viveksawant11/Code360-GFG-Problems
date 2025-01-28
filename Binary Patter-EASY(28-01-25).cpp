#include <iostream>
#include <string>
using namespace std;

void printBinaryPattern(int N) {
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            cout << string(N - i, '1') << endl; 
        } else {
            cout << string(N - i, '0') << endl; 
        }
    }
}

int main() {
    int T; 
    cin >> T; 
    while (T--) {
        int N;
        cin >> N;
        printBinaryPattern(N);
    }
    return 0;
}
