// Link: https://leetcode.com/problems/swap-nodes-in-pairs/description/

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
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL || head -> next == NULL)
            return head ;

        ListNode *dummy = new ListNode(-1) ;
        ListNode *tail = dummy ;

        ListNode *p = head ;

        while(p != NULL && p -> next != NULL)
        {
            ListNode *first = new ListNode(p -> val) ;
            p = p -> next ;

            ListNode *second = new ListNode(p -> val) ;
            p = p -> next ;

            tail -> next = second ;
            tail = second ;

            tail -> next = first ;
            tail = first ;
        }

        if(p != NULL)
            tail -> next = p ;

        return dummy -> next ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
