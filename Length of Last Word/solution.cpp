#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> arr;
        int l = 0, r = 0;
        
        while (l < s.length()) {
            if (s[l] != ' ') {
                r = l;
                while (l < s.length() && s[l] != ' ') {
                    l++;
                }
                arr.push_back(s.substr(r, l - r));
            }
            l++;
        }

        return arr.back().length();
    }
};