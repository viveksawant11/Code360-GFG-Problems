#include <iostream>
#include <vector>
#include <string>
using namespace std;

string zigzagPattern(string str, int m) {
   if (m == 1) return str; 

   vector<string> rows(min(m, str.size()));
   int currRow = 0;
   bool goingDown = false;

   for (char ch : str) {
      rows[currRow] += ch;

      if (currRow == 0 || currRow == m - 1)
         goingDown = !goingDown;
   
      currRow += goingDown ? 1 : -1;
   }

   string result;
   for (string row : rows) {
      result += row;
   }

   return result;
}

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n, m;
        string str;

        cin >> n >> m;
        cin >> str;

        cout << zigzagPattern(str, m) << endl;
    }

    return 0;
}
