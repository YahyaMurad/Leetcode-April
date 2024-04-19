class Solution:
    def trap(self, height: List[int]) -> int:
        maxL = [0]
        maxL_value = float("-inf")

        for num in range(len(height)):
            if num != 0:
                maxL_value = max(maxL_value, height[num - 1])
                maxL.append(maxL_value)

        maxR = [0]
        maxR_value = float("-inf")

        for num in range(len(height) - 1, -1, -1):
            if num != len(height) - 1:
                maxR_value = max(maxR_value, height[num + 1])
                maxR.append(maxR_value)

        maxR = maxR[::-1]

        minLR = []

        for i in range(len(maxL)):
            minLR.append(min(maxL[i], maxR[i]))

        res = 0

        for i in range(len(minLR)):
            if minLR[i] - height[i] > 0:
                res += minLR[i] - height[i]

        return res
