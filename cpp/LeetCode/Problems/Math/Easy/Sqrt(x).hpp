//
//  Sqrt(x).hpp
//  LeetCode
//
//  Created by Salvatore on 21/3/24.
//

#ifndef Sqrt_x__hpp
#define Sqrt_x__hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace Sqrt {
    
    int mySqrt(int x) {
        if(x <= 1) return x;

        int ans = x / 2;
        int temp;

        while(true){
            temp = (ans + x / ans) / 2;
            if (temp >= ans) {
                return ans;
            }
            ans = temp;
        }
        return ans;
    }
    
    inline void test() {
        vector<int> cases =    {1, 4, 8, 9, 36, 121, 2147395600};
        vector<int> expected = {1, 2, 2, 3, 6, 11, 46340};
        
        for (int i = 0; i < cases.size(); ++i) {
            int result = mySqrt(cases[i]);
            
            assert(result == expected[i], result, expected[i]);
        }
        
    }

}

#endif /* Sqrt_x__hpp */
