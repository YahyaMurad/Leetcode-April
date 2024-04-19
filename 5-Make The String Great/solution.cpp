#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> stack;

        for (char c : s) {
            if (stack.empty()) {
                stack.push(c);
            }
            else {
                if ((isupper(c) && stack.top() == tolower(c)) || (islower(c) && stack.top() == toupper(c))) {
                    stack.pop();
                }
                else {
                    stack.push(c);
                }
            }
        }
        
        string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        
        return result;
    }
};