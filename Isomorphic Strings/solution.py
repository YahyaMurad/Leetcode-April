class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        h = {}

        for i in range(len(s)):
            if s[i] in h:
                if h[s[i]] != t[i]:
                    return False
            else:
                h[s[i]] = t[i]

        h = {}

        for i in range(len(t)):
            if t[i] in h:
                if h[t[i]] != s[i]:
                    return False

            else:
                h[t[i]] = s[i]
                

        return True