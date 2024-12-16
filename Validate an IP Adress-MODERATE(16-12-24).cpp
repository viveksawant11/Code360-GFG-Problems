#include <bits/stdc++.h> 
using namespace std;

int isValid(string &s) {
    int temp = -1, cnt = 0, index = -1;

    for (int i = 0 ; i < s.size() ; i++) {
        if (s[i] == '.') {
            cnt++;
            
            if (temp < 0 || temp > 255)
                return false;
            if (temp != 0 && s[index + 1] == '0')
                return false;

            temp = -1;
            index = i;
        }
        else {
            if (temp == -1)
                temp = 0;

            temp = temp * 10 + (s[i] - '0');
        }
    }
    if (temp < 0 || temp > 255 || cnt != 3)
        return false;
    if (temp != 0 && s[index + 1] == '0')
        return false;

    return true;
}

