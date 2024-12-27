#include <bits/stdc++.h>
using namespace std;

vector<string> units = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
vector<string> tens = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};

string digitsToWords(int n, string suffix) {
    string str = "";

    if (n > 19) 
        str += tens[n / 10] + units[n % 10];
    else 
        str += units[n];

    if (n != 0) 
        str += suffix;
    
    return str;
}

string handleAll(long n) {
    string res = "";

    res += digitsToWords((int)(n / 10000000), "crore ");
    res += digitsToWords((int)((n / 100000) % 100), "lakh ");
    res += digitsToWords((int)((n / 1000) % 100), "thousand ");
    res += digitsToWords((int)((n / 100) % 10), "hundred ");

    if (n > 100 && (n % 100 != 0)) 
        res += "and ";

    res += digitsToWords((int)(n % 100), "");

    return res;
}

int main() {
    int T;
    cin >> T; 

    vector<long> numbers(T);
    for (int i = 0; i < T; ++i) {
        cin >> numbers[i]; 
    }

    for (int i = 0; i < T; ++i) {
        cout << handleAll(numbers[i]) << endl;
    }

    return 0;
}
