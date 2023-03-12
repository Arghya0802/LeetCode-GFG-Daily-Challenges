// Link: https://leetcode.com/problems/merge-k-sorted-lists/description/

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

using pp = pair<int , ListNode *> ;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n = lists.size() ;

        priority_queue<pp , vector<pp> , greater<pp>> minHeap ;

        for(int i = 0 ; i < n ; i++)
        {
            ListNode *head = lists[i] ;

            if(head != NULL)
                minHeap.push( {head -> val , head} ) ;
        }

        ListNode *dummy = new ListNode(-1) ;
        ListNode *tail = dummy ;

        while(!minHeap.empty() )
        {
            int top = minHeap.top().first ;
            ListNode *node = minHeap.top().second ;
            minHeap.pop() ;

            tail -> next = node ;
            tail = node ;

            if(node -> next != NULL)
                minHeap.push( {node -> next -> val , node -> next} ) ;
        
        }

        tail -> next = NULL ;

        return dummy -> next ;   
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
