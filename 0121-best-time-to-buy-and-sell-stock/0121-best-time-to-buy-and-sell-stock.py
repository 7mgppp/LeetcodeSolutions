class Solution:
    def maxProfit(self, prices: list[int]) -> int:

        minPrice = float("inf")
        maxProfit = 0

        for i in range(0, len(prices),1):
            if prices[i] < minPrice:
                minPrice = prices[i]
            else:
                profit = prices[i] - minPrice
                maxProfit = max(profit, maxProfit)

        
    
        return maxProfit
        






