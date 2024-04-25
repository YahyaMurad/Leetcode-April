#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> stack;
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                count++;
                stack.push(c);
            }
            else if (c == ')') {
                if (count > 0) {
                    count--;
                    stack.push(c);
                }
            }
            else {
                stack.push(c);
            }
        }

        vector<char> res;
        while (!stack.empty()) {
            char c = stack.top();
            stack.pop();

            if (c == '(' && count > 0) {
                count--;
            }
            else {
                res.push_back(c);
            }
        }

        string result(res.rbegin(), res.rend());
        return result;
    }
};