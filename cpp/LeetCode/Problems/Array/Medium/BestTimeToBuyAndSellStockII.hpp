//
//  BestTimeToBuyAndSellStockII.hpp
//  LeetCode
//
//  Created by Salvatore on 4/6/24.
//

#ifndef BestTimeToBuyAndSellStockII_hpp
#define BestTimeToBuyAndSellStockII_hpp

#include <stdio.h>

namespace BestTimeToBuyAndSellStockII {
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i - 1] < prices[i])
                profit += prices[i] - prices[i - 1];
        }

        return profit;
    }

    void test() {
        vector<vector<int>> prices = {
            {7,1,5,3,6,4}, {1,2,3,4,5}, {7,6,4,3,1}
        };
        
        vector<int> expected = {7, 4, 0};
        
        for (int i = 0; i < prices.size(); ++i) {
            int result = maxProfit(prices[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* BestTimeToBuyAndSellStockII_hpp */
