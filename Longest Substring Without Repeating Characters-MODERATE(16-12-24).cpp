#include <bits/stdc++.h> 
using namespace std;

int lengthOfLongestSubstring(string &s) {
    unordered_map<char, int> lastSeen;

    int maxLength = 0;
    int start = 0;     

    for (int end = 0; end < s.length(); end++) {
        char currentChar = s[end];

        // If the character is already seen, adjust the start of the window
        if (lastSeen.find(currentChar) != lastSeen.end() && lastSeen[currentChar] >= start) {
            start = lastSeen[currentChar] + 1;
        }

        lastSeen[currentChar] = end;

        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string s1 = "xyxyz";
    cout << lengthOfLongestSubstring(s1) << endl; // Output: 3

    string s2 = "xxx";
    cout << lengthOfLongestSubstring(s2) << endl; // Output: 1

    string s3 = "abacb";
    cout << lengthOfLongestSubstring(s3) << endl; // Output: 3

    return 0;
}
