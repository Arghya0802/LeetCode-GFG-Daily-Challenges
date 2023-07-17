// Link: https://leetcode.com/problems/add-two-numbers-ii/description/

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

ListNode *reverseLL(ListNode *head)
{
    ListNode *curr = head ;  ListNode *prev = NULL ;  ListNode *last = NULL ;

    while(curr)
    {
        last = prev ; prev = curr ;

        curr = curr -> next ;

        prev -> next = last ;

    }

    return prev ;
}

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL)  return l2 ;

        if(l2 == NULL)  return l1 ;

        ListNode *revA = reverseLL(l1) ;  ListNode *p = revA ;
        ListNode *revB = reverseLL(l2) ;  ListNode *q = revB ;

        ListNode *dummy = new ListNode(-1) ;  ListNode *tail = dummy ;

        int carry = 0 ;

        while(p || q || carry)
        {
            int sum = carry ;

            if(p) 
            {
                sum += p -> val ;  p = p -> next ;
            }

            if(q)
            {
                sum += q -> val ;  q = q -> next ;
            }

            ListNode *res = new ListNode(sum % 10) ;  carry = sum / 10 ;

            tail -> next = res ; tail = res ;
        } 


        return reverseLL(dummy -> next) ;
    }
};

// Time Complexity:  O(M + N)
// Space Complexity: O(M + N)
