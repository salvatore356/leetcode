//
//  LinkedListCycle.hpp
//  LeetCode
//
//  Created by Salvatore on 7/5/24.
//

#ifndef LinkedListCycle_hpp
#define LinkedListCycle_hpp

#include <stdio.h>
#include "../../../Utils/Utils.hpp"

namespace LinkedListCycle {
    bool hasCycle(ListNode<int> *head) {
        if (head == NULL || head->next == NULL) return false;

        ListNode<int> *slow = head;
        ListNode<int> *fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }
        return false;
    }

    void addingCycle (ListNode<int> *h, int pos) {
        if (pos == -1) return;
        
        vector<ListNode<int>*> temp;
        auto h_temp = h;
        while (h_temp != NULL) {
            temp.push_back(h_temp);
            h_temp = h_temp->next;
        }
        
        temp.back()->next = temp[pos];
    }
    
    void test() {
        vector<vector<int>> head = {
            {3,2,0,-4},
            {1,2},
            {1},
            {},
            {-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5}
        };
        
        vector<int> pos = {1, 0, -1, -1, -1};
        vector<bool> expected = {true, true, false, false, false };
        
        for (int i = 0; i < head.size(); ++i) {
            ListNode<int> *h = loadList(head[i]);
            addingCycle (h, pos[i]);
            
            bool result = hasCycle(h);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* LinkedListCycle_hpp */
