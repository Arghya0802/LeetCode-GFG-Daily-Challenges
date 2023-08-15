// Link:  https://leetcode.com/problems/partition-list/description/

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
    ListNode* partition(ListNode* head, int x) 
    {
        if(!head || !head -> next)  return head ;

        ListNode *headA = new ListNode(INT_MIN) ;
        ListNode *headB = new ListNode(INT_MAX) ;

        ListNode *tailA = headA ; ListNode *tailB = headB ;

        ListNode *p = head ;
            
        while(p)
        {
            if(p -> val < x)  
            {
                tailA -> next = p ;  tailA = p ;
            }    

            else
            {
                tailB -> next = p ; tailB = p ;
            }

            p = p -> next ;
        }


        if(tailA != headA && tailB != headB)
        {
            tailA -> next = headB -> next ;  tailB -> next = NULL ;

            return headA -> next ;
        }

        else if(tailA == headA)  return headB -> next ;

        else return headA -> next ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
