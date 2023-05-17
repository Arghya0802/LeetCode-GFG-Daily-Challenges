// Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/

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

ListNode *reverseList(ListNode *head)
{
    ListNode *last = NULL ; ListNode *prev = NULL ;
    ListNode *curr = head ;

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
    int pairSum(ListNode* head) 
    {
        ListNode *p = head ; ListNode *q = head ;

        ListNode *fast = head ; ListNode *slow = head ; ListNode *prev = NULL ;

        while(fast && fast -> next) // Finding the Middle Node of LinkedList using Slow and Fast Pointers Concept
        {
            prev = slow ;
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }

        ListNode *reverse = reverseList(slow) ;

        prev -> next = NULL ;

        int maxSum = 0 ;

        p = head ;  q = reverse ;

        while(p != NULL && q != NULL)
        {
            int sum = p -> val + q -> val ;

            maxSum = max(maxSum , sum) ;

            p = p -> next ; q = q -> next ;
        }

        return maxSum ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
