class Solution:
    def makeGood(self, s: str) -> str:
        stack = []

        for i in s:
            if not stack:
                stack.append(i)
            else:
                if (i.isupper() and stack[-1] == i.lower()) or (i.islower() and stack[-1] == i.upper()):
                    stack.pop()
                else:
                    stack.append(i)

        return "".join(stack)