#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count = 0, res = 0;

        for (char c : s) {
            if (c == '(') count++;
            res = max(count, res);
            if (c == ')') count--;
        }
        return res;
    }
};