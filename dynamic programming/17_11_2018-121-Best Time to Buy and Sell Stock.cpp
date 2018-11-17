//The solution idea credits to https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solution/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int minPrice=prices[0], maxProfit=0;
        for (auto price : prices)
            if (price < minPrice)
                minPrice=price;
            else if (price-minPrice>maxProfit)
                maxProfit=price-minPrice;
        return maxProfit;
    }
};
