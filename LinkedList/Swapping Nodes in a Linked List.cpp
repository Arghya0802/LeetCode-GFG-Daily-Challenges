// Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

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

ListNode *reverseLinkedList(ListNode *head)
{
    ListNode *curr = head ;
    ListNode *prev = NULL ;
    ListNode *last = NULL ;

    while(curr != NULL)
    {
        last = prev ;
        prev = curr ;
        curr = curr -> next ;

        prev -> next = last ;
    }

    return prev ;
}

public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *p = head ;
        ListNode *startNode = NULL ;

        int cnt = 0 ;

        while(cnt < k - 1)
        {
            cnt++ ;

            p = p -> next ;
        }

        startNode = p ;

        ListNode *reversed = reverseLinkedList(head) ;

        p = reversed ;
        cnt = 0 ;

        ListNode *endNode = NULL ;

        while(cnt < k - 1)
        {
            cnt++ ;
            p = p -> next ;
        }

        endNode = p ;
        
        swap(startNode -> val , endNode -> val) ;

        return reverseLinkedList(reversed) ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
