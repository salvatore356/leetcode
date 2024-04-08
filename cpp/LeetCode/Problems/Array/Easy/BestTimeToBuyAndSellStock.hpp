//
//  BestTimeToBuyAndSellStock.hpp
//  LeetCode
//
//  Created by Salvatore on 8/4/24.
//

#ifndef BestTimeToBuyAndSellStock_hpp
#define BestTimeToBuyAndSellStock_hpp

#include <stdio.h>

namespace BestTimeToBuyAndSellStock {
    int maxProfit(vector<int>& prices) {
        int profit = 0, minElement = prices.front();

        for(int i = 1; i < prices.size(); ++i) {
            minElement = min(minElement, prices[i]);
            profit = max(profit, prices[i] - minElement);
        }
        return profit;
    }

    void test() {
        vector<vector<int>> cases = {
            {7, 1, 5, 3, 6, 4},
            {7, 6, 4, 3, 1},
        };
        
        vector<int> expected = {5, 0};
        
        for(int i = 0; i < cases.size(); ++i){
            int result = maxProfit(cases[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* BestTimeToBuyAndSellStock_hpp */
