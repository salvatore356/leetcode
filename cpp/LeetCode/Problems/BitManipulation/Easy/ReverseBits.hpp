//
//  ReverseBits.hpp
//  LeetCode
//
//  Created by Salvatore on 21/5/24.
//

#ifndef ReverseBits_hpp
#define ReverseBits_hpp

#include <stdio.h>

namespace ReverseBits {
    
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; i++) {
            result = result * 2 + (n%2);
            n /= 2;
        }
        
        return result;
    }

    void test() {
        vector<uint32_t> n = {43261596, 4294967293};
        vector<uint32_t> expected = {964176192, 3221225471};
        
        for (int i = 0; i < n.size(); ++i) {
            uint32_t result = reverseBits(n[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* ReverseBits_hpp */
