class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        arr = []
        l = 0
        r = 0
        while l < len(s):
            if s[l] != " ":
                r = l
                while l < len(s) and s[l] != " ":
                    l += 1
                arr.append(s[r:l])

            l += 1

        return len(arr[-1])