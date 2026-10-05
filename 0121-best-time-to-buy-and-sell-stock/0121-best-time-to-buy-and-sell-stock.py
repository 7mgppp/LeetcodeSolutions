class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        prev = 0
        i = 0
        max_profit = 0
        while i < len(prices) and prev < len(prices):
            profit = prices[i] - prices[prev]
            while prices[prev]> prices[i] and prev < i:
                prev+=1
            max_profit = max(max_profit,profit)
            i+=1
        return max_profit







