// Link: https://leetcode.com/problems/linked-list-random-node/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
ListNode *ourHead ;

public:
    Solution(ListNode* head) 
    {
        ourHead = head ;    
    }
    
    int getRandom() 
    {
        int cnt = 1 ;
        int ans = 0 ;

        ListNode *p = ourHead ;

        while(p != NULL)
        {
            if(rand() % cnt == 0)
                ans = p -> val ;
            
            cnt++ ;
            p = p -> next ;
        }
            
        return ans ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// Time Complexity:  O(N)
// Space Complexity: O(1)
