//
//  GasStation.hpp
//  LeetCode
//
//  Created by Salvatore on 13/6/24.
//

#ifndef GasStation_hpp
#define GasStation_hpp

#include <stdio.h>

namespace GasStation {

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;

        for (int i = 0; i < gas.size(); ++i) {
            gas[i] -= cost[i];
            tank += gas[i];
        }

        if (tank < 0) return -1;

        int index = 0;
        tank = 0;
        for (int i = 0; i < gas.size(); ++i) {
            tank += gas[i];
            if (tank < 0) {
                tank = 0;
                index = i + 1;
            }
        }
        return index;
    }
    
    void test() {
        vector<vector<int>> gas = {{1,2,3,4,5}, {2,3,4}};
        vector<vector<int>> cost = {{3,4,5,1,2}, {3,4,3}};
        vector<int> expected = {3, -1};
        
        for (int i = 0; i < gas.size(); ++i) {
            int result = canCompleteCircuit(gas[i], cost[i]);
            
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* GasStation_hpp */
