//
//  InsertDeleteGetRandomO1.hpp
//  LeetCode
//
//  Created by Salvatore on 10/6/24.
//

#ifndef InsertDeleteGetRandomO1_hpp
#define InsertDeleteGetRandomO1_hpp

#include <stdio.h>

namespace InsertDeleteGetRandomO1 {
    class RandomizedSet {
        unordered_map<int, int> uniq;
        vector<int> values;
    public:
        RandomizedSet() {}
        
        bool insert(int val) {
            auto it = uniq.find(val);

            if (it == uniq.end() ) {
                uniq[val] = (int)values.size();
                values.push_back(val);
                return true;
            }
            
            return false;
        }
        
        bool remove(int val) {
            
            auto it = uniq.find(val);

            if (it != uniq.end()) {

                int last = (int)values.size() - 1;
                uniq[values.back()] = uniq[val];
                swap(values[it->second], values[last]);
                uniq.erase(val);
                values.pop_back();
                return true;
            }
            return false;
        }
        
        int getRandom() {
            int index = rand() % values.size();
            return values[index];
        }
    };

    void test() {
        vector<vector<string>> actions = {
            {"RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"},
            {"RandomizedSet","insert","remove","insert","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"}
            
        };
        
        vector<vector<int>> input = {
            {INT_MAX, 1, 2, 2, INT_MAX, 1, 2, INT_MAX},
            {INT_MAX, 0, 0, -1, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}
        };
        
        vector<vector<int>> expected = {
            {INT_MAX,true,false,true,2,true,false,2},
            {INT_MAX,true,true,true,false,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
        };
        
        for (int i = 0; i < actions.size(); ++i) {
            RandomizedSet newSet;
            
            for (int r = 0; r < actions[i].size(); ++r) {
                string action = actions[i][r];
                
                if (action == "RandomizedSet") {
                    
                } else if (action == "insert") {
                    bool result = newSet.insert(input[i][r]);
                    assert(result == expected[i][r], result, expected[i][r]);
                } else if (action == "remove") {
                    bool result = newSet.remove(input[i][r]);
                    assert(result == expected[i][r], result, expected[i][r]);
                } else if (action == "getRandom") {
                    int result = newSet.getRandom();
                    assert(result == expected[i][r], result, expected[i][r]);
                }
                
            }
        }
    }

}

#endif /* InsertDeleteGetRandomO1_hpp */
