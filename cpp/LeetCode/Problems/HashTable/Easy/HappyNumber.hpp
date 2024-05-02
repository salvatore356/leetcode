//
//  HappyNumber.hpp
//  LeetCode
//
//  Created by Salvatore on 2/5/24.
//

#ifndef HappyNumber_hpp
#define HappyNumber_hpp

#include <stdio.h>

namespace HappyNumber {
    int squareNumber(int n) {
        int sum = 0;
        while(n > 0) {
            sum += pow(n%10, 2);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_map<int, bool> happyNumber = {
            {1, true}, {7, true},
        };

        while(n > 9) {
            n = squareNumber(n);
        }
        return happyNumber[n];
    }

    void test() {
        vector<int> n = {19, 2};
        vector<bool> expected = {true, false};
        
        for(int i = 0; i < n.size(); ++i) {
            bool result = isHappy(n[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* HappyNumber_hpp */
