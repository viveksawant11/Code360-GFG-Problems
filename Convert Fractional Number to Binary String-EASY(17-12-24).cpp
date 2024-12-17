#include <iostream>
#include <string>
using namespace std;

// When converting integer part to binary, we use 'division' by 2, ----->

// 13 / 2 = 6, remainder 1 → Least Significant Bit (LSB)
// 6 / 2 = 3, remainder 0
// 3 / 2 = 1, remainder 1
// 1 / 2 = 0, remainder 1
// Reading the remainders from bottom to top → (1101)

// When converting fractional part to binary, we use 'multiplication' by 2, ----->

// Multiply 0.625 * 2 = 1.25 → Take integer part 1 → Append 1 → Remaining: 0.25    ("0.1")
// Multiply 0.25 * 2 = 0.5 → Take integer part 0 → Append 0 → Remaining: 0.5       ("0.10")
// Multiply 0.5 * 2 = 1.0 → Take integer part 1 → Append 1 → Remaining: 0.0        ("0.101")

string convertToBinary(double n) {
    string result = "0.";
    int limit = 32;

    while (n > 0 && result.size() <= limit) {
        n *= 2;                     // We are converting fractional part to binary
        if (n >= 1) {
            result += "1";
            n -= 1;                 // If num >= 1 , then we need to subtract 1 and take only decimal part
        } else {
            result += "0";
        }
    }

    if (n != 0) return "ERROR";
    return result;
}

int main() {
    double num;
    cin >> num;  
    
    string result = convertFractionToBinary(num);  
    cout << result << endl;

    return 0;
}