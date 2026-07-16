#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_Profit = 0;

        for (size_t i = 0; i < prices.size() - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                max_Profit += (prices[i + 1] - prices[i]); // Accumulate profit
            }
        }

        return max_Profit;
    }
};

