class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        cnt = 0
        for c in s:
            if c == "(":
                cnt += 1
                stack.append(c)
            elif c == ")":
                if cnt > 0:
                    cnt -= 1
                    stack.append(c)
            else:
                stack.append(c)

        res = []
        for c in stack[::-1]:
            if c == "(" and cnt > 0:
                cnt -= 1
            else:
                res.append(c)

        return res[::-1]