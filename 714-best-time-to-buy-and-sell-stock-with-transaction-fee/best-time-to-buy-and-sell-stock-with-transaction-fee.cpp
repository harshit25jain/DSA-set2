class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -prices[0], cash = 0;
        for (int i = 1; i < prices.size(); ++i) {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};

/*
We simulate buying and selling with maximum profit.

Maintain two variables:

hold: max profit when holding a stock.
cash: max profit when not holding any stock.
On each day:

Update cash: sell today if profitable.
Update hold: buy today if better than previous buy.
Subtract fee only when selling.

*/

