// Link:  https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    
    if(left == right)
        return head ;
    
    ListNode *dummy = new ListNode(-1) ;
        
    dummy -> next = head ;
        
    int pos = 0 ;
    
    ListNode *curr = dummy ;
    ListNode *prevLeft = dummy ;
        
    while(pos < left - 1)
    {
        prevLeft = prevLeft -> next ;
        
        pos++ ;
    }
        
    ListNode *start = prevLeft -> next ;
        
    ListNode *end = dummy ;
    pos = 0 ;
        
    while(pos < right)
    {
        end = end -> next ;
        
        pos++ ;
    }
        
    ListNode *nextRight = end -> next ;
    
    ListNode *prev = NULL ;
    ListNode *last = NULL ;
        
    curr = start ;
    
    while(curr != nextRight)
    {
        last = prev ;
        prev = curr ;
        
        curr = curr -> next ;
        
        prev -> next = last ;
        
    }
        
    // Prev is the New Head of the Reversed Linkedlist
    prevLeft -> next = prev ;
        
    start -> next = nextRight ;
    
    return dummy -> next ;
    
}
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
