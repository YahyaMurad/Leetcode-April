#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> h;

        for (int i = 0; i < s.length(); i++) {
            if (h.find(s[i]) != h.end()) {
                if (h[s[i]] != t[i]) return false;
            }
            else {
                h[s[i]] = t[i];
            }
        }

        h.clear();

        for (int i = 0; i < t.length(); i++) {
            if (h.find(t[i]) != h.end()) {
                if (h[t[i]] != s[i]) return false;
            }
            else {
                h[t[i]] = s[i];
            }
        }

        return true;
    }
};